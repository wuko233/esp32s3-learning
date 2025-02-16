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
    display("Setting...", 1000);
    Serial.begin(115200);
    WiFi_Connect();
    display("Setup done.", 500);
}

void loop() {
    menu();
}

void menu(){
    while (1) {
        String ipInfo = "IP: " + WiFi.localIP().toString();
        String first_menu = ipInfo + "\n[1] Reconnect WiFi\n[2] AI Reply\n[3] Bilifans Number\n[4] Display Test\n[0] Reboot";
        display(first_menu.c_str(), 0);
        String msg = get_input();
        if (msg == "1") {
            WiFi_Connect();
            delay(1000);
        } else if (msg == "2") {
            AI_menu();
        } else if (msg == "3") {
            getBiliFans();
        } else if (msg == "4") {
            display_menu();
        } else if (msg == "0") {
            display("See u again!", 500);
            esp_restart();
        } else {
            display("err!", 1000);
        }
    }

}

