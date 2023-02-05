#include <Arduino.h>
#include <Servo.h>
#include "globals.h"
#include "servo_function.h"

void moveToAngle(uint8_t pin, uint16_t angle) {
  for (uint8_t i = 0; i < numPWMPins; i++) {
    if (servoObjects[i].pin == pin) {
      if (! servoObjects[i].servoObject.attached()) {
        servoObjects[i].servoObject.attach(servoObjects[i].pin);
      }
      servoObjects[i].servoObject.write(angle);
    }
  }
}

void moveToMicroseconds(uint8_t pin, uint16_t microSeconds) {
  for (uint8_t i = 0; i < numPWMPins; i++) {
    if (servoObjects[i].pin == pin) {
      if (! servoObjects[i].servoObject.attached()) {
        servoObjects[i].servoObject.attach(servoObjects[i].pin);
      }
      servoObjects[i].servoObject.writeMicroseconds(microSeconds);
    }
  }
}