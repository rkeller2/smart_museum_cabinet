#include <Arduino.h>
#include <Wire.h>
#include <avr/io.h>
#include "alarm.h"


/*
Project: Smart Museum Cabinet
Team: 17036
Submitted to: GEOST
Author: Robert Keller
File description:
*/

int hallSensor1 = 11; //left door
int hallSensor2 = 12; //right door

void alarm(){
  int alarmState1 = ((analogRead(hallSensor1)));
  int alarmState2 = ((analogRead(hallSensor2)));

    if((alarmState1 == LOW)  | (alarmState2 ==LOW)){
      Serial.println("Cabinet Opened");
    }

}
