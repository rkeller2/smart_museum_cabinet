#include <Arduino.h>
#include <Wire.h>
#include <avr/io.h>

/*
Project: Smart Museum Cabinet
Team: 17036
Submitted to: GEOST
Author: Robert Keller
File description: This file initialzes all functions used in dimmer.cpp
*/

#ifndef DIMMER_H
#define DIMMER_H

int initDimmer(int brightness);
int initFan(int fanSpeed);

#endif
