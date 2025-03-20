#include "motor.h"
#include "config.h"
#include <Arduino.h>

const uint8_t stepSequence[8][4] = {
  {1, 0, 0, 0}, // 步 1: IN1激活
  {1, 1, 0, 0}, // 步 2: IN1+IN2激活
  {0, 1, 0, 0}, // 步 3: IN2激活
  {0, 1, 1, 0}, // 步 4: IN2+IN3激活
  {0, 0, 1, 0}, // 步 5: IN3激活
  {0, 0, 1, 1}, // 步 6: IN3+IN4激活
  {0, 0, 0, 1}, // 步 7: IN4激活
  {1, 0, 0, 1}  // 步 8: IN4+IN1激活
};

int stepDelay = 2; //值越小速度越快

void rotateMotor(int steps, bool clockwise) {
  for (int i = 0; i < steps; i++) {
    for (int seq = 0; seq < 8; seq++) {
      int currentStep = clockwise ? seq : 7 - seq; // 方向控制
      digitalWrite(MOTOR_IN1, stepSequence[currentStep][0]);
      digitalWrite(MOTOR_IN2, stepSequence[currentStep][1]);
      digitalWrite(MOTOR_IN3, stepSequence[currentStep][2]);
      digitalWrite(MOTOR_IN4, stepSequence[currentStep][3]);
      delay(stepDelay);
    }
  }
}