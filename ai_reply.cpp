#include "ai_reply.h"
#include "oled_display.h"
#include "basic.h"
#include "config.h"
#include <Arduino.h>

String getReply() {
    String url = "https://api.siliconflow.cn/v1/chat/completions";
    int status = 0;
    display("Press \"/q\" to quit.\nPlease input your msg:");
    String msg = get_input();
    if (msg == "/q") {
        return "quit.";
    }
    display((("> " + msg)).c_str());
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
            return "JSON error: " + String(error.c_str());
        }
        if (!doc.containsKey("choices") || doc["choices"].size() == 0) {
            return "No choices in response";
        }
        String reply = doc["choices"][0]["message"]["content"];
        return reply;
    } else {
        String errorDetail = "HTTP Error: " + String(code) + "\n";
        errorDetail += "Error Description: " + http.errorToString(code) + "\n";
        errorDetail += "Response: " + res + "\n";
        errorDetail += "Payload: " + payload;
        return errorDetail;
    }
}