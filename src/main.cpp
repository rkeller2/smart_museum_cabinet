/*
Project: Smart Museum Cabinet
Team: 17036
Submitted to: GEOST
Author: Robert Keller
File description: This file
*/

#include <Arduino.h>
#include <Wire.h>
#include <avr/io.h>

#include "thermistor.h"
#include "dimmer.h"

typedef enum stateType_enum{ idle, warning, halfPower, coolDown} stateType;  //define states
volatile stateType state = idle; //set intital state

int Tpin = 0;
float warningTemp = 50; //warning temperature in Fahrenheit
float coolDownTemp = 55; //cool down (shutoff temp)
float halfPowerTemp = 52; //led half power temp

void setup(){
  Serial.begin(9600);
}
  void loop(){

          while(1){
            float temp;
            temp = thermistorRead(Tpin);
            int ledSetting;
            // Serial.println(temp);
            // delay(500);

            switch(state){
              case idle:
                Serial.println("idle");
                delay(1000);
                ledSetting = initDimmer(2); //set leds to full power
              //set fan to low speed
                if(temp >= warningTemp){
                  state = warning;
                }
                else{
                  state = idle;
                }
              break;
              case warning:
                Serial.println("Warning");
                delay(1000); //print every 5 seconds
                ledSetting = initDimmer(2); //set leds to full power
                //increase fan speed - use map function
                if(temp >= halfPowerTemp){
                  state = halfPower;
                }
                else if(temp < warningTemp){
                  state = idle;
                }
                else{
                  state = warning;
                }
              break;
              case halfPower:
                Serial.println("Half Power");
                delay(1000);
                ledSetting = initDimmer(1); //set leds to half power
                if(temp >= coolDownTemp){
                  state = coolDown;
                }
                if(temp < halfPowerTemp){
                  state = warning;
                }
                else {
                  state = halfPower;
                }
                break;
              case coolDown:
                Serial.println("Cooling");
                delay(1000);
                ledSetting = initDimmer(0); //turn off LEDs
                //set fans to full power
                if(temp <= coolDownTemp){
                  state = halfPower;
                }
                else{
                  state = coolDown;
                }
               break;

          }
  }
}
