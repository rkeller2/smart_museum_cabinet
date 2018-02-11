#include <Arduino.h>
#include <Wire.h>
#include <avr/io.h>
#include "thermistor.h"
#include <math.h>

/*
Project: Smart Museum Cabinet
Team: 17036
Submitted to: GEOST
Author: Robert Keller
File description: This file uses a voltage divider to indicate the resistance of a thermistor.
The resistance values of the thermistor are then converted to fahrenheit temperatures.
(Equations and constants derived from datasheet of thermistor).
*/

double thermistor(int Tpin) {
   double Temp;
   Temp = log(10000.0*((1024.0/Tpin-1))); //linearize values
   Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp ); //temperature coefficients for 100k ohm 3950 NTC thermistor
   Temp = Temp - 273.15; //convert degrees K to C
   Temp = (Temp * 9.0)/ 5.0 + 32.0; //convert C to F
   Temp = Temp - 1; //error adjustment
   return Temp;
   //Serial.println(Temp);
  }
