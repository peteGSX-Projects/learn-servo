#include <Arduino.h>
#include <Servo.h>

#define SERVO1 3      // 500Hz
#define SERVO2 5      // 1KHz
#define RED_LED 6     // 1KHz
#define AMBER_LED 9   // 500Hz
#define SERVO3 10     // 500Hz - not in use
#define GREEN_LED 11  // 500Hz

Servo servoObject1;
Servo servoObject2;
Servo servoObject3;

bool newSerialData = false;   // Flag for new serial data being received
const byte numSerialChars = 10;   // Max number of chars for serial input
char serialInputChars[numSerialChars];  // Char array for serial input

void setup() {
  Serial.begin(115200);
  Serial.println(F("Learning servo"));
}

void loop() {
  processSerialInput();
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
    newSerialData = false;
    char * strtokIndex;
    strtokIndex = strtok(serialInputChars," ");
    char activity = strtokIndex[0];
    strtokIndex = strtok(NULL," ");
    unsigned long parameter = strtol(strtokIndex, NULL, 10);
    switch(activity) {
      case '1':
        Serial.print(F("Move servo 1 to "));
        Serial.println(parameter);
        if(!servoObject1.attached()) {
          servoObject1.attach(SERVO1);
        }
        servoObject1.write(parameter);
        break;
      case '2':
        Serial.print(F("Move servo 1 to "));
        Serial.println(parameter);
        if(!servoObject2.attached()) {
          servoObject2.attach(SERVO2);
        }
        servoObject2.write(parameter);
        break;
      case '3':
        Serial.print(F("Set LED 1 to "));
        Serial.println(parameter);
        if(!servoObject3.attached()) {
          servoObject3.attach(RED_LED);
        }
        servoObject3.write(parameter);
        break;
      case '4':
        Serial.print(F("Move servo 1 for "));
        Serial.print(parameter);
        Serial.println(F(" us"));
        if(!servoObject1.attached()) {
          servoObject1.attach(SERVO1);
        }
        servoObject1.writeMicroseconds(parameter);
        break;
      case '5':
        Serial.print(F("Move servo 2 for "));
        Serial.print(parameter);
        Serial.println(F(" us"));
        if(!servoObject2.attached()) {
          servoObject2.attach(SERVO2);
        }
        servoObject2.writeMicroseconds(parameter);
        break;
      case '6':
        Serial.print(F("Set LED 1 for "));
        Serial.print(parameter);
        Serial.println(F(" us"));
        if(!servoObject3.attached()) {
          servoObject3.attach(RED_LED);
        }
        servoObject3.writeMicroseconds(parameter);
        break;
      case '7':
        servoObject1.detach();
        servoObject2.detach();
        servoObject3.detach();
        break;
      case '8':
        pinMode(RED_LED, OUTPUT);
        digitalWrite(RED_LED, HIGH);
        break;
      case '9':
        pinMode(RED_LED, OUTPUT);
        digitalWrite(RED_LED, LOW);
        break;
      default:
        break;
    }
  }
}
