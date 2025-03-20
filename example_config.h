#pragma once
#include <Arduino.h>

// OLED Configs
#define OLED_SDA 20
#define OLED_SCL 21

// WiFi Configs
#define ssid_Router "1"
#define password_Router "1"

//AI Reply Configs
#define Api_key "Bearer sk-c1ri" // Bearer <token>
#define Model_name "Pro/deepseek-ai/DeepSeek-R1"

//Motor GPIO Define
#define MOTOR_IN1 12  // GPIO12 连接 ULN2003 IN1
#define MOTOR_IN2 13  // GPIO13 连接 ULN2003 IN2
#define MOTOR_IN3 14  // GPIO14 连接 ULN2003 IN3
#define MOTOR_IN4 15  // GPIO15 连接 ULN2003 IN4
#define STEPDELAY 2  // 值越小电机速度越快

//LDR GPIO Define
#define LDR_IN1 4
#define LDR_IN2 5
#define LDR_IN3 6
#define LDR_IN4 7