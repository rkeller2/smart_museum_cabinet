/*
Project: Smart Museum Cabinet
Team: 17036
Submitted to: GEOST
Author: Robert Keller
File description: This file uses a voltage divider to indicate the resistance of a thermistor.
The resistance values of the thermistor are then converted to fahrenheit temperatures.
*/

#include <Arduino.h>
#include <Wire.h>
#include <avr/io.h>
#include "thermistor.h"

float thermistorRead(int Tpin) {

  int Vo;
  float logRt,Rt,T;
  float R = 10000; // fixed resistance, measured with multimeter
  // c1, c2, c3 are calibration coefficients for a particular thermistor
  float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
  Vo = analogRead(Tpin);
  Rt = R*( 1024.0 / float(Vo) - 1.0 ); //voltage divider
  logRt = log(Rt);
  T = ( 1.0 / (c1 + c2*logRt + c3*logRt*logRt*logRt ) ) - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; //convert to Fahrenheit
  return T;

    // Serial.print("Temperature: ");
    // Serial.print(T);
    // Serial.println(" F");
    //
    // delay(500);
  }
