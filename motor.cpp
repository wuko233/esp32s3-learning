#include "motor.h"
#include "config.h"
#include <Arduino.h>

int setupMotor() {
    pinMode(MOTOR_IN1, OUTPUT);
    pinMode(MOTOR_IN2, OUTPUT);
    pinMode(MOTOR_IN3, OUTPUT);
    pinMode(MOTOR_IN4, OUTPUT);
    return 200;
}

static uint8_t fastStepSequence[4][4] = {
  {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}
};

static uint8_t normalStepSequence[8][4] = {
  {1,0,0,0}, {1,1,0,0}, {0,1,0,0}, {0,1,1,0},
  {0,0,1,0}, {0,0,1,1}, {0,0,0,1}, {1,0,0,1}
};


uint8_t (*fastMode(bool is))[4] {
  return is ? fastStepSequence : normalStepSequence;
}

void rotateMotor(int steps,bool isFast, bool clockwise) {
    uint8_t (*stepSequence)[4] = fastMode(isFast);
    int stepCount = isFast ? 4 : 8;
    for (int i = 0; i < steps; i++) {
        for (int seq = 0; seq < stepCount; seq++) {
            int currentStep = clockwise ? seq : (stepCount - 1) - seq;
            digitalWrite(MOTOR_IN1, stepSequence[currentStep][0]);
            digitalWrite(MOTOR_IN2, stepSequence[currentStep][1]);
            digitalWrite(MOTOR_IN3, stepSequence[currentStep][2]);
            digitalWrite(MOTOR_IN4, stepSequence[currentStep][3]);
            delay(STEPDELAY);
        }
    }
}
