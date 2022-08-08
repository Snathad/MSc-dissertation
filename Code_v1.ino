//Charles Oliver Barrett Birdsall H00219071//
//B320-RAI Robotics MSc Heriot-Watt University//
//2022 MSc Dissertation project//
//Soft Actuators for a Social Robot//
//Version 1.5//

//This code is part of the work towards the above titled dissertation project. The focus of the project is the design and testing of soft-pneumatic actuators for a social robot.//
//the actuators themselves are silicone structures that require air pressure to move. The air pressure is supplied by a compressor and allowed into the actuators by//
//deliberate control of solenoid valves. Each solenoid has to be triggered using a relay which is controlled by an Arduino. This is the arduino code to do that.//
//Additionally there are indicators and operation switches, including an emergency stop button, that are coded in the file.//

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
#include <stdio.h>    //Include arduino library

#define Green 13      //Assigns the green led to its pin, this corresponds to the top actuator/relay.
#define Blue 12       //Assigns the blue led to its pin, this corresponds to the right actuator/relay.
#define Yellow 11     //Assigns the yellow led to its pin, this corresponds to the left actuator/relay.
#define Red 10        //Assigns the red led to its pin, this corresponds to the emergency stop/ fault.
#define Emergency 9   //The emergency stop button.
#define TopRelay 1    //The pin assignment for the top actuator.
#define RightRelay 2  //The pin assignment for the right actuator.  
#define LeftRelay 3   //The pin assignment for the left actuator.
#define Power (4)     //The power switch (effectively a disable or reset for the emergency stop.

int ESflag = 0 ;      //A flag for if the emergency stop has been pushed.
int ESflagstate =0;   //A flag used for the latching of the emergency stop flag
int resetflag = 0;    //A flag that allows for the system to be reset
int i;                //A counter used in for loops.

//////////////////////////////////////////////////////////////////////////////////////////////////////////

//The pin definitions.
void setup() {
  //Outputs (4x LED's, 3x Relays)
  pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red,OUTPUT);
  pinMode (TopRelay, OUTPUT);
  pinMode (LeftRelay,OUTPUT);
  pinMode (RightRelay, OUTPUT);

  //Inputs (Power toggle switch, Emergency stop push button
  pinMode (Power, INPUT);
  pinMode (Emergency, INPUT);

  //Begin serial mointor to track output states
  Serial.begin(9600);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  //Start by setting all outputs and the emergency stop flag as low
  digitalWrite(Blue, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(TopRelay, LOW);
  digitalWrite(LeftRelay, LOW);
  digitalWrite(RightRelay, LOW);
  
  
  // Enable system if power is switched on.
  if (digitalRead(Power) == HIGH && digitalRead(Emergency) == LOW && ESflag==0) {
    digitalWrite(Red,LOW);
    if (resetflag == 0){
      left();
      //right();
      //up();
      //down();
      Serial.print(resetflag);
      }
    }
   
    //if at any point the power is on and the emergency stop is triggered set the ESflag high.
    if (digitalRead(Emergency) == HIGH && ESflag==0){
      ESflag=1;
      ESflagstate=!ESflagstate;
      }

    //If system is turned off after ES is triggered, reset ES
    if (ESflag==1 and digitalRead(Emergency)==LOW and digitalRead(Power)==LOW){
      digitalWrite(Red,LOW);
      ESflag=0;
      Serial.print("I am banana");
     }

    //Go to ES sub function when flag is active.
    if (ESflagstate==HIGH){  
      Efunct();
      }
    }

///////////////////////////////////////////////////////////////////////////////////////////////
//Moves the robot to the left by triggering the artificial muscles on its right and activates the corresponding LED
int left (){
  
    digitalWrite(Blue, HIGH);
    digitalWrite(RightRelay, HIGH);

   //Emergency stop
    if (digitalRead(Emergency) == HIGH && ESflag==0){
      ESflag=1;
      ESflagstate=!ESflagstate;
      }
      
    if (ESflagstate==HIGH){  
      Efunct();
     }
  
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Moves the robot up by triggering the artificial muscles on its bottom and activates the corresponding LED's
int up (){
 
    digitalWrite(Blue, HIGH);
    digitalWrite(Yellow, HIGH);
    digitalWrite(RightRelay, HIGH);
    digitalWrite(LeftRelay, HIGH);

    //Emergency stop
    if (digitalRead(Emergency) == HIGH && ESflag==0){
      ESflag=1;
      ESflagstate=!ESflagstate;
      }
      
    if (ESflagstate==HIGH){  
      Efunct();
      }
  
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Moves the robot down by triggering the artificial muscle on its top and activates the corresponding LED
int down (){
  
    digitalWrite(Green, HIGH);
    digitalWrite(TopRelay, HIGH);

    //Emergency stop
    if (digitalRead(Emergency) == HIGH && ESflag==0){
      ESflag=1;
      ESflagstate=!ESflagstate;
      }
      
    if (ESflagstate==HIGH){  
      Efunct();
      }
      
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Moves the robot left by triggering the artificial muscles on its right and activates the corresponding LED
int right (){
  
    digitalWrite(Yellow, HIGH);
    digitalWrite(LeftRelay, HIGH);

    //Emergency Stop
    if (digitalRead(Emergency) == HIGH && ESflag==0){
      ESflag=1;
      ESflagstate=!ESflagstate;
      }
  
    if (ESflagstate==HIGH){  
      Efunct();
     }
  
  return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Efunct (){
   //This is the emergency stop function. When activated during any of the other functions it will cease all outputs and turn on the warning indicator
    if (digitalRead(Power)==HIGH){
      digitalWrite(Red,HIGH);
      Serial.print("red");
      digitalWrite(TopRelay, LOW);
      digitalWrite(LeftRelay, LOW);
      digitalWrite(RightRelay, LOW);
      digitalWrite(Blue, LOW);
      digitalWrite(Yellow, LOW);
      digitalWrite(Green, LOW);
    }
    
  //If the system has been reset, return to original program.      
  if (ESflag=0 && digitalRead(Power)==HIGH){ 
    return 0;
  }
}
  
