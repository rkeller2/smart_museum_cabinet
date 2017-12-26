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
#include "dimmer.h"

volatile int shelf1 = 13, shelf2 = 12, shelf3 = 11, shelf4 = 10, shelf5 = 9;
volatile int bar1 = 8, bar2 = 7, bar3 = 6, bar4 = 5, bar5 = 4;
int halfPowerVal = 10;

void ledSetup(){
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
}

int initDimmer(int brightness){
  //brightness = 0 = LEDs off, 1 = half power, 2 = full power
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
  /*
  // change the brightness for next time through the loop:
  if(fade == false){
    for(int i = 0; i <= 255; i++){
      brightness = brightness + step;
      delay(30);
    }
  }
  // reverse the direction of the fading at the ends of the fade:
  if (fade == true) {
    for(int i = 255; i >= 0; i--){
    brightness = brightness - step;
    delay(30);
    }
  }
  */

}
