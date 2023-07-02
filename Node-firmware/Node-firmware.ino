// ARDUINO MICRO

#include <SoftwareSerial.h>
#include "Commands.h"
#include "Crc16.h"

Crc16 crc;  
// software serial #1: RX = digital pin 10, TX = digital pin 11
SoftwareSerial DriverPort(10, 11);
#define DebugPort Serial

#define inblue A0
#define inRed A1
#define enPin 5   // the number of the En pin
#define stpPin 6  // the number of the Stp pin
#define dirPin 7  // the number of the Dir pin

#define blue_min 760
#define blue_max 95

void setup() {
  
  DebugPort.begin(9600);
  DriverPort.begin(38400);

  // put your setup code here, to run once:
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);  // initialize the En pin as an output
  pinMode(stpPin, OUTPUT);
  digitalWrite(stpPin, LOW);  // initialize the Stp pin as an output
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin, LOW);  // initialize the Dir pin as an output

  pinMode(inblue, INPUT);
  pinMode(inRed, INPUT);

  //sendCommand(ReturnToZero);
}

void loop() {
  //driveStepper();
  readUartDebug();
  //readNeopixel();
}









  
