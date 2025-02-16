#include "bili_api.h"
#include "oled_display.h"
#include "basic.h"
#include <Arduino.h>

void getBiliFans() {
    display("Please input UID:", 100);
    String UID = get_input();
    String Url = "https://api.bilibili.com/x/relation/stat?vmid=" + UID;
    digitalWrite(LED_BUILTIN, HIGH);
    HTTPClient http;
    http.begin(Url);
    int httpCode = http.GET();
    if (httpCode == HTTP_CODE_OK) {
        String resMsg = http.getString();
        display(resMsg.c_str(), 2000);
    } else {
        display(("getting failed:" + String(httpCode)).c_str(), 2000);
        for (int i = 0; i < 5; i++) {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(500);
            digitalWrite(LED_BUILTIN, LOW);
            delay(500);
        }
    }
    digitalWrite(LED_BUILTIN, LOW);
    http.end();
}
