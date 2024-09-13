#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial BTserial (0, 1);
int pirv=0,pir=7,fs=9,fsv=0,ss=5,ssv=0,trig=11,echo=10;
float hi;
float tr;
int  ;
int ;
float dis;
float dur;

void setup() {
  pinMode (pir, INPUT);
  pinMode (fs, INPUT);
  pinMode (ss, INPUT);
  pinMode (trig, INPUT);
  pinMode (echo, INPUT);
  pinMode (2, OUTPUT);
  BTserial.begin(9600);
}

void loop() {
  pirv = digitalRead(pir);
  fsv = digitalRead(fs);
  for (int i=1;i<=100;i++){
    if(analogRead(ss)>500 and analogRead(ss)<300){
      ssv=1;
      break;
    }
  }

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur = pulseIn(echo, HIGH);
  dis = dur * 0.034 / 2; 

  if(pirv==HIGH){
     BTserial.print("Intruder");
     BTserial.print(", ");
  }
  else{
     BTserial.print("OK");
     BTserial.print(", ");
  }
  if(fsv==HIGH){
    BTserial.print("Fire detected");
    BTserial.print(", ");
  }
  else{
    BTserial.print("Normal");
    BTserial.print(", ");
  }
  if(ssv==HIGH){
    BTserial.print("Sound detected");
    BTserial.print(", ");
  }
  else{
    BTserial.print("Normal");
    BTserial.print(", ");
  }
  if(dis<20){
     BTserial.print("Alert");
     BTserial.print (dis);
     BTserial.print("; ");
  }
  else{
    BTserial.print("Normal");
    BTserial.print("; ");
  }
  while (fsv!=HIGH){
    digitalWrite(2,HIGH);
  }
  digitalWrite(2,HIGH);
  delay(2000);
}
