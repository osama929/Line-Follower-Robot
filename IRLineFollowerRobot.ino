#include "AFMotor.h"
//BlackIR
// black : HIGHT : 1
// white : LOW : 0
#define Black HIGH 
#define White LOW  
//Red ID
// black : HIGHT : 0
// white : LOW : 1
//#define Black LOW 
//#define White HIGH  
AF_DCMotor motorR (3);
AF_DCMotor motorL (1);
int sensorL = A0;
int sensorM = A1;
int sensorR = A2;
int readingL;
int readingM;
int readingR;
int velocity = 250;
int velocityR=0;
int velocityL=0;
void setup() {
  pinMode(sensorL, INPUT);
  pinMode(sensorM, INPUT);
  pinMode(sensorR, INPUT);
  velocityR=velocity;
  velocityL=velocity;
}

void loop() {
  readingM = digitalRead(sensorM);
  readingR = digitalRead(sensorR);
  readingL = digitalRead(sensorL);
  if (readingL == White && readingR == White  )
  {
    motorR.setSpeed(velocityR);
    motorL.setSpeed(velocityL);
    motorR.run(FORWARD);
    motorL.run(FORWARD);
  }

  else if (readingL == Black && readingR == White )
  {
    motorR.setSpeed(velocityR);
   motorL.setSpeed(velocityL);
        motorL.run(BACKWARD);
    motorR.run(FORWARD);
  }
  else if (readingL == White &&  readingR == Black )
  {
    motorR.setSpeed(velocityR);
    motorL.setSpeed(velocityL);
    motorL.run(FORWARD);
    motorR.run(BACKWARD);

  }

  else if (readingL == Black  && readingR == Black )
  {

    motorR.setSpeed(0);
    motorL.setSpeed(0);
    motorR.run(RELEASE);
    motorL.run(RELEASE);

  }

  
  else
  {}
  
}
