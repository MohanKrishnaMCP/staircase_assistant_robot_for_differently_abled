#include<SoftwareSerial.h>
SoftwareSerial bluetooth(13,12);//(RX,TX)
//Motor A
  const int inputPin1 = 5;    // Pin 15 of L293D IC, D1 Pin of NodeMCU
  const int inputPin2= 6;    // Pin 10 of L293D IC, D0 Pin of NodeMCU
//Motor B
  const int inputPin3 = 4;    // Pin  7 of L293D IC, D2 Pin of NodeMCU
  const int inputPin4 = 3;    // Pin  2 of L293D IC, D3 Pin of NodeMCU
// Motor C
  const int inputPin5 = 9;
  const int inputPin6 = 10;
// Motor D
  const int inputPin7 = 8;
  const int inputPin8 = 9;
//int EN1 = 11;                 // Pin 1 of L293D IC, D6 Pin of NodeMCU
//int EN2 = 14;  

void setup()
{

  pinMode(inputPin1,OUTPUT);
  pinMode(inputPin2,OUTPUT);
  pinMode(inputPin3,OUTPUT);
  pinMode(inputPin4,OUTPUT);
  pinMode(inputPin5,OUTPUT);
  pinMode(inputPin6,OUTPUT);
  pinMode(inputPin7,OUTPUT);
  pinMode(inputPin8,OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
  

}

void loop()
{
  char a=bluetooth.read();
  Serial.println(a);
  if(a=='a')
  {
    forward();
  }
  else
   if(a=='b')
  {
    reverse();
  }
  
}
void forward()
{
    digitalWrite(inputPin1,LOW);
    digitalWrite(inputPin2,HIGH);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,HIGH);
    digitalWrite(inputPin5,LOW);
    digitalWrite(inputPin6,HIGH);
    digitalWrite(inputPin7,LOW);
    digitalWrite(inputPin8,HIGH);
}
void reverse()
{
    digitalWrite(inputPin1,HIGH);
    digitalWrite(inputPin2,LOW);
    digitalWrite(inputPin3,HIGH);
    digitalWrite(inputPin4,LOW);
    digitalWrite(inputPin5,HIGH);
    digitalWrite(inputPin6,LOW);
    digitalWrite(inputPin7,HIGH);
    digitalWrite(inputPin8,LOW);
}

