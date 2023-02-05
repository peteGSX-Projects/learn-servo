#include <Arduino.h>
#include <Servo.h>
#include "globals.h"
#include "serial_function.h"

#if defined(ARDUINO_AVR_NANO)
#include "arduino_nano.h"
#else
#define CPU_TYPE_ERROR
#endif

#ifdef CPU_TYPE_ERROR
#error Unsupported CPU
#endif

uint8_t numPWMPins = NUM_PWM_PINS;

void setup() {
  Serial.begin(115200);
  Serial.println(F("Learning servo"));
}

void loop() {
  processSerialInput();
}