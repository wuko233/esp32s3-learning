#include <Arduino.h>


#include "basic.h"
#include "wifi_utils.h"
#include "oled_display.h"
#include "LDRCom.h"
#include "motor.h"
#include "ai_reply.h"
#include "bili_api.h"

#define LED_BUILTIN 2

void menu();

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    setupDisplay();
    display("Setting...", 1000);
    Serial.begin(115200);
    WiFi_Connect();
    setupMotor();
    setupLDR();
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
        } else if (msg == "5") {
            display("电机要转了哦！", 500);
            display("慢速正转", 500);
            rotateMotor(512, false, false);
            display("快速正转", 500);
            rotateMotor(512, true, false);
            display("快速倒转", 500);
            rotateMotor(512, true, true);
            display("慢速倒转", 500);
            rotateMotor(512, false, true);
        } else if (msg == "6") {
            while (1) {
            display("LDR TEST\n[1] Keep listen LDR 1\n[2] LDR ALL\n[0] Exit", 100);
            String opt = get_input();
            if (opt == "0") {
            break;
            }
        if (opt == "1") {
            display("Start Listen LDR, Press q to quit.", 1000);

            while (true) {
                String input = get_input();
                if (input.indexOf('q') != -1) break;
                int ao = returnData1();
                display(("AO: " + String(ao)).c_str(), 0);
                if (ao > 2500) {
                    display("光照不足，开启补光！", 0);
                }
            }
            display("Exit LDR模式", 1000);
        } else if (opt == "2") {
                img_test();
                delay(2500);
            } else {
                display("err!", 1000);
            }
        }
        }else if (msg == "0") {
            display("See u again!", 500);
            esp_restart();
        } else {
            display("err!", 1000);
        }
    }

}

