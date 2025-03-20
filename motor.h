#pragma once
#include <stdint.h> 
int setupMotor();


typedef uint8_t (*StepSequence)[4]; 

void rotateMotor(int steps,bool isFast, bool clockwise);