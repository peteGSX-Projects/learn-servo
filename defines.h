#ifndef DEFINES_H
#define DEFINES_H

#include <Arduino.h>
#include <Servo.h>

struct servoDefinition {
  Servo servoObject;
  uint8_t pin;
};

#if defined(ARDUINO_AVR_NANO)
#define NUM_PWM_PINS 6
#endif

#endif