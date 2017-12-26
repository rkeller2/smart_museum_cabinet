/*
Project: Smart Museum Cabinet
Team: 17036
Submitted to: GEOST
Author: Robert Keller
File description: This file initializes all PWM pins, and contains the functions
for controlling LED brightness and fan speed
*/

#include <Arduino.h>
#include <Wire.h>
#include <avr/io.h>
#include "dimmer.h"

/*****************************************************/
//ENSURE VALUES MATCH THOSE IN main.cpp
int  warningTemp = 0; //warning temperature in Fahrenheit
int halfPowerTemp = 100; //led half power temp
int coolDownTemp = 300; //cool down (shutoff temp)
/****************************************************/

int lowSpeed = 80;
int middleSpeed = 200;
int halfPowerVal = 10; //duty cycle value for LED brightness

//initialize PWM pins
int shelf1 = 13, shelf2 = 12, shelf3 = 11, shelf4 = 10, shelf5 = 9;
int bar1 = 8, bar2 = 7, bar3 = 6, bar4 = 5, bar5 = 4;
int fanPin = 3;

void ledSetup(){
  //set brightness pins 4 to 13 as outputs for LEDs
  pinMode(shelf1, OUTPUT);
  pinMode(shelf2, OUTPUT);
  pinMode(shelf3, OUTPUT);
  pinMode(shelf4, OUTPUT);
  pinMode(shelf5, OUTPUT);
  pinMode(bar1, OUTPUT);
  pinMode(bar2, OUTPUT);
  pinMode(bar3, OUTPUT);
  pinMode(bar4, OUTPUT);
  pinMode(bar5, OUTPUT);
  //set pin 3 as output for fan
  pinMode(fanPin, OUTPUT);
}

int initDimmer(int brightness){
  //brightness: 0 = LEDs off, 1 = half power, 2 = full power
    if (brightness == 0){
      analogWrite(shelf1, 0);
      analogWrite(shelf2, 0);
      analogWrite(shelf3, 0);
      analogWrite(shelf4, 0);
      analogWrite(shelf5, 0);
      analogWrite(bar1, 0);
      analogWrite(bar2, 0);
      analogWrite(bar3, 0);
      analogWrite(bar4, 0);
      analogWrite(bar5, 0);
    }
    if (brightness == 1){
      analogWrite(shelf1, halfPowerVal);
      analogWrite(shelf2, halfPowerVal);
      analogWrite(shelf3, halfPowerVal);
      analogWrite(shelf4, halfPowerVal);
      analogWrite(shelf5, halfPowerVal);
      analogWrite(bar1, halfPowerVal);
      analogWrite(bar2, halfPowerVal);
      analogWrite(bar3, halfPowerVal);
      analogWrite(bar4, halfPowerVal);
      analogWrite(bar5, halfPowerVal);
    }
    if (brightness == 2){
      analogWrite(shelf1, 255);
      analogWrite(shelf2, 255);
      analogWrite(shelf3, 255);
      analogWrite(shelf4, 255);
      analogWrite(shelf5, 255);
      analogWrite(bar1, 255);
      analogWrite(bar2, 255);
      analogWrite(bar3, 255);
      analogWrite(bar4, 255);
      analogWrite(bar5, 255);
    }

      return brightness;
}

int initFan(int fanSpeed){
  //fan speed: 0 = off, 1 = low speed, 2 = increase speed, 3 = max speed
    if(fanSpeed == 3){
      analogWrite(fanPin, 255); //full speed
    }
    if(fanSpeed == 2){
      //speed increases linearly with temperature
      //outputs to fanPin, lower and upper bounds of temperature map linearly to lower and upper bounds of fan speed
      map(fanPin, warningTemp, coolDownTemp, lowSpeed, middleSpeed);
    }
    if(fanSpeed == 1){
      analogWrite(fanPin, lowSpeed);
    }
    if(fanSpeed == 0){
      analogWrite(fanPin, 0);
    }
    return fanSpeed;
}
