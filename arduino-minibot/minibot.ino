#include "IRremote.h"

//Motors
int rightMotorSpeed = 8;
int rightMotor1= 9;
int rightMotor2= 4;

int leftMotor1= 5;
int leftMotor2 = 6;
int leftMotorSpeed = 7;

//Encoders
int encoderPinR1 = 0;
int encoderPinR2 = 0;

int encoderPinL1 = 0;
int encoderPinL2 = 0;

int ticks = 0;
int lastEncoderRdg = LOW;

//Receiver
int receiver = 12;
IRrecv irrecv(receiver);
decode_results results;

void setup() {
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorSpeed , OUTPUT);

  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2 , OUTPUT);
  pinMode(leftMotorSpeed , OUTPUT);

  irrecv.enableIRIn();
  Serial.begin(9600);
  set_speed(255, 255);
}

void loop() {
  if (irrecv.decode(&results)) { //Received signal
    translateIR();
    irrecv.resume();
  }
}

void updateEncoder() {
  int encoderRdg1 = digitalRead(encoderPinR1);
  int encoderRdg2 = digitalRead(encoderPinR2);

  if(encoderRdg1 != lastEncoderRdg && encoderRdg1 == HIGH) {
    if(encoderRdg2 == encoderRdg1) {
      ticks++; 
    } else {
      ticks--; 
    }
  }
  lastEncoderRdg = encoderRdg1;
}
