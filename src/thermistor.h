#include <Arduino.h>
#include <Wire.h>
#include <avr/io.h>

#ifndef THERMISTOR_H
#define THERMISTOR_H

float thermistorRead(int Tpin);

#endif
