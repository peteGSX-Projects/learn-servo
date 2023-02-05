#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include "defines.h"

extern servoDefinition servoObjects[MAX_PWM_PINS];
extern uint8_t numPWMPins;

#endif