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

#include "servo.h"

Servo servoXY;
//Servo servoZ;

int posXY = 0;
//int posZ = 0;

void gimbalSetup()
{
  Serial.begin(9600);
  servoXY.attach(53);
  //servoZ.attach(51);
}

int initServos(int servoXYPin)
{
  for(posXY = 0; posXY <= 180; posXY += 1)
  {
    servoXY.write(posXY);
    delay(15);
  }
  for(posXY = 180; posXY>=0; posXY-=1)
  {
    servoXY.write(posXY);
    delay(15);
  }
  return posXY;
}
