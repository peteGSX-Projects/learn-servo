#ifndef SERVO_FUNCTION_H
#define SERVO_FUNCTION_H

#include <Arduino.h>

void moveToAngle(uint8_t pin, uint16_t angle);
void moveToMicroseconds(uint8_t pin, uint16_t microSeconds);
void writeAnalogueValue(uint8_t pin, uint16_t value);
void writeHighLow(uint8_t pin, uint16_t value);

#endif