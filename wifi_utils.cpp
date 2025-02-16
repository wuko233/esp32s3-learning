#include "wifi_utils.h"
#include "oled_display.h"  // 为了使用display函数
#include "config.h"


void WiFi_Connect() {
    WiFi.begin(ssid_Router, password_Router);
    display((String("Connecting to ") + ssid_Router).c_str());
    while (WiFi.status() != WL_CONNECTED) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        Serial.print(".");
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
    }
    display(("\nConnected, IP address: " + WiFi.localIP().toString()).c_str());
}