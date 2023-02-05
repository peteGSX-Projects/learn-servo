#ifndef DEFINES_H
#define DEFINES_H

#include <Arduino.h>
#include <Servo.h>

struct servoDefinition {
  Servo servoObject;
  uint8_t pin;
};

#define MAX_PWM_PINS 16

#endif