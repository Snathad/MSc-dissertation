//Charles Oliver Barrett Birdsall H00219071//
//B320-RAI Robotics MSc Heriot-Watt University//
//2022 MSc Dissertation project//
//Soft Actuators for a Social Robot//
//Version 1.3//

//This code is part of the work towards the above titled dissertation project. The focus of the project is the design and testing of soft-pneumatic actuators for a social robot.//
//the actuators themselves are silicone structures that require air pressure to move. The air pressure is supplied by a compressor and allowed into the actuators by//
//deliberate control of solenoid valves. Each solenoid has to be triggered using a relay which is controlled by an Arduino. This is the arduino code to do that.//
//Additionally there are indicators and operation switches, including an emergency stop button, that are coded in the file.//

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
#include <stdio.h>

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
int i;                //A counter used in for loops.

//////////////////////////////////////////////////////////////////////////////////////////////////////////

//The pin definitions.
void setup() {
  pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red,OUTPUT);
  pinMode (TopRelay, OUTPUT);
  pinMode (LeftRelay,OUTPUT);
  pinMode (RightRelay, OUTPUT);
  
  pinMode (Power, INPUT);
  pinMode (Emergency, INPUT);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  //Start by setting all outputs and the emergency stop flag as low
 int ESflag=0;
  digitalWrite(Blue, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(TopRelay, LOW);
  digitalWrite(LeftRelay, LOW);
  digitalWrite(RightRelay, LOW);
  
  // Enable system if power is switched on.
  if (Power == HIGH) {
    
    //if at any point the power is on and the emergency stop is triggered set the ESflag high.
    if (Emergency == HIGH){
      ESflag=1;
      }

    //if the ESflag is high set all outputs low except the red led to indicate an error state.  
    if (ESflag == 1) {
      digitalWrite(Red,HIGH);
      digitalWrite(TopRelay, LOW);
      digitalWrite(LeftRelay, LOW);
      digitalWrite(RightRelay, LOW);
      }
      else {

      //if the error flag is not on, the red led will not be either  
      digitalWrite(Red,LOW);  
    }

    //if the power switch is not active turn off the error state flag
} else {
  ESflag = 0;
}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Moves the robot to the left by triggering the artificial muscles on its right and activates the corresponding LED
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Moves the robot up by triggering the artificial muscles on its bottom and activates the corresponding LED's
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Moves the robot down by triggering the artificial muscle on its top and activates the corresponding LED
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Moves the robot left by triggering the artificial muscles on its right and activates the corresponding LED
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
