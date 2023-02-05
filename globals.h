#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include "defines.h"

#if defined(ARDUINO_AVR_NANO)
#include "arduino_nano.h"
#else
#define CPU_TYPE_ERROR
#endif

extern servoDefinition servoObjects[NUM_PWM_PINS];
extern uint8_t numPWMPins;

#endif