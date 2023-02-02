#include <Arduino.h>
#include <Servo.h>

Servo servoObject1;
Servo servoObject2;

const uint8_t servo1Pin = 3;
const uint8_t servo2Pin = 11;

bool newSerialData = false;   // Flag for new serial data being received
const byte numSerialChars = 10;   // Max number of chars for serial input
char serialInputChars[numSerialChars];  // Char array for serial input

void setup() {
  Serial.begin(115200);
  Serial.println(F("Learning servo"));
  // pinMode(servo1Pin, OUTPUT);
  // pinMode(servo2Pin, OUTPUT);
  // TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM20);
  // TCCR2B = _BV(CS22);
  // OCR2A = 180;
  // OCR2B = 50;
  servoObject1.attach(servo1Pin);
  servoObject2.attach(servo2Pin);
}

void loop() {
  processSerialInput();
  // Serial.println("10");
  // analogWrite(servo1Pin, 10);
  // analogWrite(servo2Pin, 200);
  // delay(1000);
  // Serial.println("50");
  // analogWrite(servo1Pin, 50);
  // delay(1000);
  // Serial.println("100");
  // analogWrite(servo1Pin, 100);
  // analogWrite(servo2Pin, 10);
  // delay(1000);
  // Serial.println("150");
  // analogWrite(servo1Pin, 150);
  // delay(1000);
  // Serial.println("255");
  // analogWrite(servo1Pin, 255);
  // delay(1000);
}

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
    Serial.println("Process input");
    newSerialData = false;
    char * strtokIndex;
    strtokIndex = strtok(serialInputChars," ");
    unsigned long parameter = strtol(strtokIndex, NULL, 10);
    analogWrite(servo1Pin, parameter);
    Serial.print("analogWrite(");
    Serial.print(servo1Pin);
    Serial.print(", ");
    Serial.print(parameter);
    Serial.println(");");
  }
}
