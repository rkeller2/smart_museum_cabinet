/*
Project: Smart Museum Cabinet
Team: 17036
Submitted to: GEOST
Author: Robert Keller
File description: This file uses a voltage divider to measure the voltage of a
load of LEDs. If an LED burns out, it will result in a substantial voltage
increase. Should the voltage increase substaintially for a specific load, the
user is notified that an LED has failed in that load.
*/

#include <Arduino.h>
#include <Wire.h>
#include <avr/io.h>
#include "ledFail.h"

//Note: LED failure funciton only called in main in states where LEDs are operating on full power

int readShelf1 = A2, readShelf2 = A3, readShelf3 = A4, readShelf4 = A5, readShelf5 = A6;
int readGimbal1 = A7, readGimbal2 = A8, readGimbal3 = A9, readGimbal4 = A10;

//initialize voltage readings to zero
float voltageShelf1 = 0.0;
float voltageShelf2 = 0.0;
float voltageShelf3 = 0.0;
float voltageShelf4 = 0.0;
float voltageShelf5 = 0.0;

float voltageGimbal1 = 0.0;
float voltageGimbal2 = 0.0;
float voltageGimbal3 = 0.0;
float voltageGimbal4 = 0.0;

float r1=100000.0; //value of resistor 1 in voltage divider
float r2=10000.0; //value of resistor 2 in voltage divider

int ledThresh = 22; //max voltage threshold (if led fails, the voltage read will be the full 24V since LEDs are connected in series)
int gimbalThresh = 10; //max voltage threshold

bool fail = false; //initialize failure to false

void failShelf1(){
  //read analog values for all LEDs, convert values to voltages
  voltageShelf1 = (((analogRead(readShelf1) * 5.0) /1024.0) / (r2/(r1+r2)));
  //eliminate any electrical noise by setting threashold
   if (voltageShelf1 < 0.1)
   {
    voltageShelf1=0.0;
   }
   delay(200);
  //detect voltage increase, declare output accordingly
  if(voltageShelf1 > ledThresh){
    fail = true;
    Serial.println("LED FAILURE SHELF 1");
    }
  else{
    fail = false;
    }
  Serial.println(voltageShelf1);
   delay(300); //samples every 300ms
}
void failShelf2(){
  voltageShelf2 = (((analogRead(readShelf2) * 5.0) /1024.0) / (r2/(r1+r2)));
   if (voltageShelf2 < 0.1)
   {
    voltageShelf2=0.0;
   }
   delay(200);
  if(voltageShelf2 > ledThresh){
    fail = true;
    Serial.println("LED FAILURE SHELF 2");
    }
  else{
    fail = false;
    }
//  Serial.println(voltageShelf2);
   delay(300);
}
void failShelf3(){
  voltageShelf3 = (((analogRead(readShelf3) * 5.0) /1024.0) / (r2/(r1+r2)));
   if (voltageShelf3 < 0.1)
   {
    voltageShelf3=0.0;
   }
   delay(200);
  if(voltageShelf3 > ledThresh){
    fail = true;
    Serial.println("LED FAILURE SHELF 3");
    }
  else{
    fail = false;
    }
//  Serial.println(voltageShelf3);
   delay(300);
}
void failShelf4(){
  voltageShelf4 = (((analogRead(readShelf4) * 5.0) /1024.0) / (r2/(r1+r2)));
   if (voltageShelf4 < 0.1)
   {
    voltageShelf4=0.0;
   }
   delay(200);
  if(voltageShelf4 > ledThresh){
    fail = true;
    Serial.println("LED FAILURE SHELF 4");
    }
  else{
    fail = false;
    }
  //Serial.println(voltageShelf4);
   delay(300);
}
void failShelf5(){
  voltageShelf5 = (((analogRead(readShelf5) * 5.0) /1024.0) / (r2/(r1+r2)));
   if (voltageShelf5 < 0.1)
   {
    voltageShelf5=0.0;
   }
   delay(200);
  if(voltageShelf5 > ledThresh){
    fail = true;
    Serial.println("LED FAILURE SHELF 5");
    }
  else{
    fail = false;
    }
//  Serial.println(voltageShelf5);
   delay(300);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void failGimbal1(){
  voltageGimbal1 = (((analogRead(readGimbal1) * 5.0) /1024.0) / (r2/(r1+r2)));
   if (voltageGimbal1 < 0.1)
   {
    voltageGimbal1=0.0;
   }
   delay(200);
  if(voltageGimbal1 > gimbalThresh){
    fail = true;
    Serial.println("GIMBALING SPOTLIGHT 1 FAILURE");
    }
  else{
    fail = false;
    }
//  Serial.println(voltageGimbal1);
   delay(300);
}
void failGimbal2(){
  voltageGimbal2 = (((analogRead(readGimbal2) * 5.0) /1024.0) / (r2/(r1+r2)));
   if (voltageGimbal2 < 0.1)
   {
    voltageGimbal2=0.0;
   }
   delay(200);
  if(voltageGimbal2 > gimbalThresh){
    fail = true;
    Serial.println("GIMBALING SPOTLIGHT 2 FAILURE");
    }
  else{
    fail = false;
    }
//  Serial.println(voltageGimbal2);
   delay(300);
}
void failGimbal3(){
  voltageGimbal3 = (((analogRead(readGimbal3) * 5.0) /1024.0) / (r2/(r1+r2)));
   if (voltageGimbal3 < 0.1)
   {
    voltageGimbal3=0.0;
   }
   delay(200);
  if(voltageGimbal3 > gimbalThresh){
    fail = true;
    Serial.println("GIMBALING SPOTLIGHT 3 FAILURE");
    }
  else{
    fail = false;
    }
//  Serial.println(voltageGimbal3);
   delay(300);
}
void failGimbal4(){
  voltageGimbal4 = (((analogRead(readGimbal4) * 5.0) /1024.0) / (r2/(r1+r2)));
   if (voltageGimbal4 < 0.1)
   {
    voltageGimbal4=0.0;
   }
   delay(200);
  if(voltageGimbal4 > gimbalThresh){
    fail = true;
    Serial.println("GIMBALING SPOTLIGHT 4 FAILURE");
    }
  else{
    fail = false;
    }
//  Serial.println(voltageGimbal4);
   delay(300);
}
