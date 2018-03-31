#include <Arduino.h>
#include <Wire.h>
#include <avr/io.h>
#include "thermistor.h"
#include "dimmer.h"
#include "ledFail.h"
#include "alarm.h"

/*

Project: Smart Museum Cabinet
Team: 17036
Submitted to: GEOST
Author: Robert Keller
File description: This file contains the state machine that controls the basic cabinet operation
*/

/********************************************************************/
//IF THSE VALUES ARE ALTERED, ALSO CHANGE THESE VALUES IN dimmer.cpp
int  WARNINGTEMP = 87; //warning temperature in Fahrenheit
int HALFPOWERTEMP = 90; //led half power temp
int COOLDOWNTEMP = 93; //cool down (shutoff temp)
/*******************************************************************/

typedef enum stateType_enum{wait, on, warning, halfPower, coolDown, off} stateType;  //define states
volatile stateType state = wait; //set intital state

int ledSetting;
int fanSetting;

int power = 1; //pass in 1 or zero to turn on/off cabinet 1 is on, 0 is off

void setup(){
  Serial.begin(9600);
}
  void loop(){
        while(1){
          alarm();
          int temp1 = (int(thermistor(analogRead(0)))); //read thermistor pin, store read temperature as integer for inside cabinet
        //  Serial.println(temp1);

        switch(state){
          case wait:
          Serial.println("      Wait");
          //LEDs, fans off, waiting for on command
          ledSetting = initDimmer(0);
          fanSetting = initFan(0);
            if(power == 1){
              state = on;
            }
            else{
              state = wait;
            }
            delay(1000); //1 second delay to turn on
            break;

          case on:
            Serial.println("    on");
            delay(1000);
            ledSetting = initDimmer(2); //set leds to full power
            fanSetting = initFan(1); // turn on fans (full power)
            if(temp1 >= WARNINGTEMP){
              state = warning;
            }
            else if(power == 0){
              state = off;
            }
            else{
              state = on;
            }
           failShelf1();
           // failShelf2();
           // failShelf3();
           // failShelf4();
           // failShelf5();
           // failGimbal1();
           // failGimbal2();
           // failGimbal3();
           // failGimbal4();
          break;

          case warning:
            Serial.println("    Wanring");
            delay(1000); //print every 5 seconds
            ledSetting = initDimmer(2);
            fanSetting = initFan(1);
            if(temp1 >= HALFPOWERTEMP){
              state = halfPower;
            }
            else if(temp1 < WARNINGTEMP){
              state = on;
            }
            else if(power == 0){
              state = off;
            }
            else{
              state = warning;
            }

            break;

          case halfPower:
            Serial.println("    half power");
            delay(1000);
            ledSetting = initDimmer(1); //set leds to half power
            fanSetting = initFan(1);
            if(temp1 >= COOLDOWNTEMP){
              state = coolDown;
            }
            else if(temp1 < HALFPOWERTEMP){
              state = warning;
            }
            else if(temp1 >= COOLDOWNTEMP){
              state = coolDown;
            }
            else if(power == 0){
              state = off;
            }
            else {
              state = halfPower;
            }
            break;

          case coolDown:
            Serial.println("    Cooling");
            delay(1000);
            ledSetting = initDimmer(0); //turn off LEDs
            fanSetting = initFan(1);
            if(temp1 >= COOLDOWNTEMP){
              state = coolDown;
            }
            else if(temp1 < COOLDOWNTEMP){
              state = halfPower;
            }
            else if(power == 0){
              state = off;
            }
            break;

            case off:
              Serial.println("     OFF");
              int temp2 = (int(thermistor(analogRead(1)))); //read thermistor pin, store read temperature as integer for outside cabinet
              ledSetting = initDimmer(0); //turn off LEDs
              fanSetting = initFan(1); //run fan
              //when inside temperature reaches outside temperature, turn off fans
              if(temp1<=temp2){
                fanSetting = initFan(0);
              }
              delay(1000);
              state = wait;
            break;

      }
}
}
