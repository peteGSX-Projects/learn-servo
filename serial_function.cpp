#include <Arduino.h>
#include "serial_function.h"
#include "servo_function.h"

bool newSerialData = false;   // Flag for new serial data being received
const byte numSerialChars = 10;   // Max number of chars for serial input
char serialInputChars[numSerialChars];  // Char array for serial input

void processSerialInput() {
  static bool serialInProgress = false;
  static byte serialIndex = 0;
  char startMarker = '<';
  char endMarker = '>';
  char serialChar;
  while (Serial.available() > 0 && newSerialData == false) {
    serialChar = Serial.read();
    if (serialInProgress == true) {
      if (serialChar != endMarker) {
        serialInputChars[serialIndex] = serialChar;
        serialIndex++;
        if (serialIndex >= numSerialChars) {
          serialIndex = numSerialChars - 1;
        }
      } else {
        serialInputChars[serialIndex] = '\0';
        serialInProgress = false;
        serialIndex = 0;
        newSerialData = true;
      }
    } else if (serialChar == startMarker) {
      serialInProgress = true;
    }
  }
  if (newSerialData == true) {
    newSerialData = false;
    char * strtokIndex;
    strtokIndex = strtok(serialInputChars," ");
    char activity = strtokIndex[0];
    strtokIndex = strtok(NULL, " ");
    unsigned long pin = strtol(strtokIndex, NULL, 10);
    strtokIndex = strtok(NULL, " ");
    unsigned long parameter = strtol(strtokIndex, NULL, 10);
    switch (activity) {
      case '1':
        moveToAngle(pin, parameter);
        break;
      case '2':
        moveToMicroseconds(pin, parameter);
        break;
      case '3':
        writeAnalogueValue(pin, parameter);
        break;
      case '4':
        writeHighLow(pin, parameter);
        break;
      default:
        break;
    }
  }
}