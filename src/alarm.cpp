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

int hallSensor = 15;
//int buzzer = 31;

void alarm(){
  //pinMode(buzzer, OUTPUT);
  int alarmState = ((analogRead(hallSensor)));

    if(alarmState == LOW){
      Serial.println("Cabinet Opened");
      //digitalWrite(buzzer, HIGH);
    }
    // else{
    //   digitalWrite(buzzer,LOW);
    // }


}
