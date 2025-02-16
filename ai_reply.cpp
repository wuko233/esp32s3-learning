#include "ai_reply.h"
#include "oled_display.h"
#include "basic.h"
#include "config.h"
#include <Arduino.h>

void AI_menu() {
    while (1) {
        display("AI Reply\n[1] Siliconflow\n[2] Ollama\n[0] Exit", 100);
        String opt = get_input();
        if (opt == "0") {
            break;
        }
        if (opt == "1") {
            getSiliconflowReply();
        } else if (opt == "2") {
            continue;
        } else {
            display("err!", 1000);
        }
    }
}

String getSiliconflowReply() {
    String url = "https://api.siliconflow.cn/v1/chat/completions";
    while (1) {
        display("Press \"/q\" to quit.\nPlease input your msg:", 100);
        String msg = get_input();
        if (msg == "/q") {
            return "quit.";
        }
        display((("> " + msg)).c_str(), 100);
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(LED_BUILTIN, HIGH);
        DynamicJsonDocument jsonRequest(512);
        jsonRequest["model"] = Model_name;
        JsonArray messages = jsonRequest.createNestedArray("messages");
        JsonObject message = messages.createNestedObject();
        message["role"] = "user";
        message["content"] = "（输出简洁明了）" + msg;
        String payload;
        serializeJson(jsonRequest, payload);
        HTTPClient http;
        http.begin(url);
        http.addHeader("Authorization", Api_key);
        http.addHeader("Content-Type", "application/json");
        http.setTimeout(30000);  // 总超时时间设为30秒
        http.setConnectTimeout(15000);  // 连接超时15秒
        http.setReuse(true);  // 允许连接复用
        int code = http.POST(payload);
        digitalWrite(LED_BUILTIN,LOW);
        String res = http.getString();
        http.end(); // 确保每次请求后调用
        if (code == HTTP_CODE_OK) {
            DynamicJsonDocument doc(1024); // 增大文档容量
            DeserializationError error = deserializeJson(doc, res);
            if (error) {
                msg = "JSON error: " + String(error.c_str());
                display(msg.c_str(), 1000);
                break;
            }
            if (!doc.containsKey("choices") || doc["choices"].size() == 0) {
                msg = "No choices in response";
                display(msg.c_str(), 1000);
                break;
            }
            String reply = doc["choices"][0]["message"]["content"];
            msg = reply;
            display(msg.c_str(), 2500);
        } else {
            String errorDetail = "HTTP Error: " + String(code) + "\n";
            errorDetail += "Error Description: " + http.errorToString(code) + "\n";
            errorDetail += "Response: " + res + "\n";
            errorDetail += "Payload: " + payload;
            msg = errorDetail;
            display(msg.c_str(), 1000);
            break;
        }
    }

}