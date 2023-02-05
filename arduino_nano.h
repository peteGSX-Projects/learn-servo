#ifndef ARDUINO_NANO_H
#define ARDUINO_NANO_H

#include <Arduino.h>
#include <Servo.h>
#include "defines.h"

#define NUM_PWM_PINS 6

Servo servoObject0;
Servo servoObject1;
Servo servoObject2;
Servo servoObject3;
Servo servoObject4;
Servo servoObject5;

servoDefinition servoObjects[NUM_PWM_PINS] = {
  {servoObject0, 3}, {servoObject1, 5}, {servoObject2, 6}, {servoObject3, 9}, {servoObject4, 10}, {servoObject5, 11},
};

#endif