/*
Project: Smart Museum Cabinet
Team: 17036
Submitted to: GEOST
Author: Robert Keller
File description: This file contains the state machine that controls the basic cabinet operation
*/

#include <Arduino.h>
#include <Wire.h>
#include <avr/io.h>

#include "thermistor.h"
#include "dimmer.h"
#include "ledFail.h"
/********************************************************************/
//IF THSE VALUES ARE ALTERED, ALSO CHANGE THESE VALUES IN dimmer.cpp
int  WARNINGTEMP = 0; //warning temperature in Fahrenheit
int HALFPOWERTEMP = 60; //led half power temp
int COOLDOWNTEMP = 300; //cool down (shutoff temp)
/*******************************************************************/
typedef enum stateType_enum{ idle, warning, halfPower, coolDown} stateType;  //define states
volatile stateType state = idle; //set intital state

int Tpin = 0;

int ledSetting;
int fanSetting;

void setup(){
  Serial.begin(9600);
  pinMode(Tpin, INPUT);
}
  void loop(){
          while(1){
            float temp;
            temp = thermistorRead(Tpin);
            Serial.println(temp);
            // delay(500);

            switch(state){
              case idle:
                //Serial.print(temp);
                Serial.println("    idle");
                delay(1000);
                ledSetting = initDimmer(2); //set leds to full power
                fanSetting = initFan(0);
                if(temp >= WARNINGTEMP){
                  state = warning;
                }
                else{
                  state = idle;
                }
                failShelf1();
                // failShelf2();
                // failShelf3();
                // failShelf4();
                // failShelf5();
                // failBar1();
                // failBar2();
                // failBar3();
                // failBar4();
                // failBar5();
              break;
              case warning:
                //Serial.print(temp);
                Serial.println("    Wanring");
                delay(1000); //print every 5 seconds
                ledSetting = initDimmer(2); //set leds to full power
                fanSetting = initFan(1); //fan set to low speed
                if(temp >= HALFPOWERTEMP){
                  state = halfPower;
                }
                else if(temp < WARNINGTEMP){
                  state = idle;
                }
                else{
                  state = warning;
                }
                failShelf1();
                // failShelf2();
                // failShelf3();
                // failShelf4();
                // failShelf5();
                // failBar1();
                // failBar2();
                // failBar3();
                // failBar4();
                // failBar5();
                break;
              case halfPower:
                //Serial.print(temp);
                Serial.println("    half power");
                delay(1000);
                ledSetting = initDimmer(1); //set leds to half power
                fanSetting = initFan(2); //fan speed increases linearly with temp using map function
                if(temp >= COOLDOWNTEMP){
                  state = coolDown;
                }
                else if(temp < HALFPOWERTEMP){
                  state = warning;
                }
                else if(temp >= COOLDOWNTEMP){
                  state = coolDown;
                }
                else {
                  state = halfPower;
                }
                // failShelf1();
                break;
              case coolDown:
                //Serial.print(temp);
                Serial.println("    Cooling");
                delay(1000);
                ledSetting = initDimmer(0); //turn off LEDs
                fanSetting = initFan(3); //fan set to full speed
                if(temp >= COOLDOWNTEMP){
                  state = coolDown;
                }
                else if(temp < COOLDOWNTEMP){
                  state = halfPower;
                }
                break;

          }
  }
}
