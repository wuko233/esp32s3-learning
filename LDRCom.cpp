#include <Arduino.h>
#include "config.h"

struct SensorData {
  int data1;
  int data2;
  int data3;
  int data4;
};

SensorData returnAllData() {
    int data1, data2, data3, data4;
    struct SensorData Data;
    Data.data1 = returnData1();
    Data.data2 = returnData2();
    Data.data3 = returnData3();
    Data.data4 = returnData4();
    return Data;
}

int returnData1() {
    int analogValue = analogRead(LDR_IN1);
    return analogValue;
}
int returnData2() {
    int analogValue = analogRead(LDR_IN2);
    return analogValue;
}

int returnData3() {
    int analogValue = analogRead(LDR_IN3);
    return analogValue;
}
int returnData4() {
    int analogValue = analogRead(LDR_IN4);
    return analogValue;
}