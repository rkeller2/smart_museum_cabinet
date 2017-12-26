#include <Arduino.h>
#include <Wire.h>
#include <avr/io.h>

#ifndef DIMMER_H
#define DIMMER_H

int initDimmer(int brightness);
int initFan(int fanSpeed);

#endif
