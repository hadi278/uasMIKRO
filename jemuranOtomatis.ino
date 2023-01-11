#include <AccelStepper.h>
#include <MultiStepper.h> 
#define motorPin1 3
#define motorPin2 4
#define motorPin3 5
#define motorPin4 6
#define MotorInterfaceType 8

int int_cahaya = A1;
int air = A2;
int buzzer = 9;
AccelStepper stepper = AccelStepper(MotorInterfaceType,
motorPin1, motorPin3, motorPin2, motorPin4);
const int bawah=0;
const int atas=1024;
void setup() {
    pinMode(int_cahaya,INPUT);
    pinMode(air,INPUT);
    pinMode(buzzer, OUTPUT);
    stepper.setMaxSpeed(1000);
    stepper.setAcceleration(900);
    Serial.begin(9600);
}

void loop() {
  int data_air=analogRead(air);
  int range=map(data_air,bawah,atas,0,3);
  int cahaya=analogRead(int_cahaya);
  Serial.print("Air : ");
  Serial.println(range);
  delay(1000);
  Serial.print("Cahaya : ");
  Serial.println(cahaya);
  delay(1000);
  if((cahaya<=400)&&(range<=1))
  { 
    stepper.runToNewPosition(0);
    tone(buzzer, HIGH); 
  }
  else
  { 
    stepper.runToNewPosition(10050); 
    // digitalWrite(buzzer, HIGH);
    tone(buzzer, HIGH);
  }
 }