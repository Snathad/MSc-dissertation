#include <stdio.h>

#define Green 13
#define Blue 12
#define Yellow 11
#define Red 10
#define Emergency 9
#define TopRelay 1
#define RightRelay 2
#define LeftRelay 3
#define Power (4)

int ESflag = 0 ;
int i;

void setup() {
  pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red,OUTPUT);
  pinMode (Emergency, INPUT);
  pinMode (TopRelay, OUTPUT);
  pinMode (LeftRelay,OUTPUT);
  pinMode (RightRelay, OUTPUT);
  pinMode (Power, INPUT);
  

}

void loop() {
 int ESflag=0;
  digitalWrite(Blue, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(TopRelay, LOW);
  digitalWrite(LeftRelay, LOW);
  digitalWrite(RightRelay, LOW);
  

  if (Power == HIGH) {
    if (Emergency == HIGH){
      ESflag=1;
      }
    if (ESflag == 1) {
      digitalWrite(Red,HIGH);
      digitalWrite(TopRelay, LOW);
      digitalWrite(LeftRelay, LOW);
      digitalWrite(RightRelay, LOW);
      }
      else {
        digitalWrite(Red,LOW);  
    }
} else {
  ESflag = 0;
}
}

int left (){
  for (i=0; i=100; i++){
    digitalWrite(Blue, HIGH);
    digitalWrite(RightRelay, HIGH);
    if (Emergency == HIGH){
      ESflag=1;
      return(0);
    }
  }
  return 0;
}

int up (){
  for (i=0; i=100; i++){
    digitalWrite(Blue, HIGH);
    digitalWrite(Yellow, HIGH);
    digitalWrite(RightRelay, HIGH);
    digitalWrite(LeftRelay, HIGH);
     if (Emergency == HIGH){
      ESflag=1;
      return(0);
    }
  }
  return 0;
}

int down (){
  for (i=0; i=100; i++){
    digitalWrite(Green, HIGH);
    digitalWrite(TopRelay, HIGH);
     if (Emergency == HIGH){
      ESflag=1;
      return(0);
    }
  }
  return 0;
}

int right (){
  for (i=0; i=100;i++){
    digitalWrite(Yellow, HIGH);
    digitalWrite(LeftRelay, HIGH);
     if (Emergency == HIGH){
      ESflag=1;
      return(0);
    } 
  }
  return 0;
}
