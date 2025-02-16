#include <Arduino.h>

#include "basic.h"
#include "wifi_utils.h"
#include "oled_display.h"
#include "ai_reply.h"
#include "bili_api.h"

#define LED_BUILTIN 2

void menu();

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    OLED.begin();
    OLED.setFont(u8g2_font_wqy12_t_gb2312);
    OLED.enableUTF8Print();
    OLED.clearBuffer();
    OLED.sendBuffer();
    Serial.begin(115200);
    delay(1000);
    display("Setting...");
    WiFi_Connect();
    String ipInfo = "\nConnected, IP: " + WiFi.localIP().toString() + "\n";
    display(ipInfo.c_str());
    display("Setup done.");
    delay(500);
}

void loop() {
    menu();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}

void menu(){
    String ipInfo = "IP: " + WiFi.localIP().toString();
    String first_menu = ipInfo + "\n[1] Reconnect WiFi\n[2] AI Reply\n[3] Bilifans Number\n[4] Display Test\n[0] Reboot";
    display(first_menu.c_str());
    String msg = get_input();
    if (msg == "1") {
        WiFi_Connect();
        delay(1000);
    } else if (msg == "2") {
        msg = getReply();
        display(msg.c_str());
        delay(5000);
    } else if (msg == "3") {
        getBiliFans();
    } else if (msg == "4") {
        display_menu();
    } else if (msg == "0") {
        esp_restart();
    } else {
        display("err!");
        delay(1000);
    }
}

