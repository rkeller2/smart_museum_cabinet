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

int readShelf1 = A1, readShelf2 = A2, readShelf3 = A3, readShelf4 = A4, readShelf5 = A5;
int readBar1 = A6, readBar2 = A7, readBar3 = A8, readBar4 = A9, readBar5 = A10;

//initialize voltage readings to zero
float voltageShelf1 = 0.0;
float voltageShelf2 = 0.0;
float voltageShelf3 = 0.0;
float voltageShelf4 = 0.0;
float voltageShelf5 = 0.0;
float voltageBar1 = 0.0;
float voltageBar2 = 0.0;
float voltageBar3 = 0.0;
float voltageBar4 = 0.0;
float voltageBar5 = 0.0;
float r1=100000.0; //value of resistor 1 in voltage divider
float r2=10000.0; //value of resistor 2 in voltage divider

int ledDrop = 11; //(voltage drop of one circuit - voltage drop of one led)
int barDrop = 12;

bool fail = false; //initialize failure to false

// void failShelf1(){
//   //read analog values for all LEDs, convert values to voltages
//   voltageShelf1 = (((analogRead(readShelf1) * 5.0) /1024.0) / (r2/(r1+r2)));
//   //eliminate any electrical noise by setting threashold
//    if (voltageShelf1 < 0.1)
//    {
//     voltageShelf1=0.0;
//    }
//   //detect voltage increase, declare output accordingly
//   if(voltageShelf1 > (ledDrop)){
//     fail = true;
//     Serial.println("LED FAILURE SHELF 1");
//     }
//   else{
//     fail = false;
//     }
//   Serial.println(voltageShelf1);
//    delay(300); //samples every 300ms
// }

// //repeat same function for all LEDs
// void failShelf2(){
//   voltageShelf2 = (((analogRead(readShelf2) * 5.0) /1024.0) / (r2/(r1+r2)));
//   if (voltageShelf2 < 0.1)
//   {
//     voltageShelf2=0.0;
//   }
//   if(voltageShelf2 >= (ledDrop)){
//     fail = true;
//     Serial.println("LED FAILURE SHELF 2");
//     }
//   else{
//     fail = false;
//     }
//   //
//    delay(300); //samples every 300ms
// }

// void failShelf3(){
//   voltageShelf3 = (((analogRead(readShelf3) * 5.0) /1024.0) / (r2/(r1+r2)));
//   if (voltageShelf3 < 0.1)
//   {
//     voltageShelf3=0.0;
//   }
//   if(voltageShelf3 >= (ledDrop)){
//     fail = true;
//     Serial.println("LED FAILURE SHELF 3");
//     }
//   else{
//     fail = false;
//     }
//   //
//    delay(300); //samples every 300ms
// }
//
// void failShelf4(){
//   voltageShelf4 = (((analogRead(readShelf4) * 5.0) /1024.0) / (r2/(r1+r2)));
//   if (voltageShelf4 < 0.1)
//   {
//     voltageShelf4=0.0;
//   }
//   if(voltageShelf4 >= (ledDrop)){
//     fail = true;
//     Serial.println("LED FAILURE SHELF 4");
//     }
//   else{
//     fail = false;
//     }
//   //
//    delay(300); //samples every 300ms
// }
//
// void failShelf5(){
//   voltageShelf5 = (((analogRead(readShelf5) * 5.0) /1024.0) / (r2/(r1+r2)));
//   if (voltageShelf5 < 0.1)
//   {
//     voltageShelf5=0.0;
//   }
//   if(voltageShelf5 >= (ledDrop)){
//     fail = true;
//     Serial.println("LED FAILURE SHELF 5");
//     }
//   else{
//     fail = false;
//     }
//   //
//    delay(300); //samples every 300ms
// }
void failBar1(){
  voltageBar1 = (((analogRead(readBar1) * 5.0) /1024.0) / (r2/(r1+r2)));
  if (voltageBar1 < 0.1)
  {
    voltageBar1 = 0.0;
  }
  if(voltageBar1 <= barDrop){
    fail = true;
    Serial.println("BAR FAILURE 1");
    }
  else{
    fail = false;
    }
 //Serial.println(voltageBar1);
   delay(300); //samples every 300ms
}
// void failBar2(){
//   voltageBar2 = (((analogRead(readBar2) * 5.0) /1024.0) / (r2/(r1+r2)));
//   if (voltageBar2 < 0.1)
//   {
//     voltageBar2 = 0.0;
//   }
//   if(voltageBar2 == 0){
//     fail = true;
//     Serial.println("BAR FAILURE 2");
//     }
//   else{
//     fail = false;
//     }
//   //
//    delay(300); //samples every 300ms
// }
// void failBar3(){
//   voltageBar3 = (((analogRead(readBar3) * 5.0) /1024.0) / (r2/(r1+r2)));
//   if (voltageBar3 < 0.1)
//   {
//     voltageBar3 = 0.0;
//   }
//   if(voltageBar3 == 0{
//     fail = true;
//     Serial.println("BAR FAILURE 3");
//     }
//   else{
//     fail = false;
//     }
//   //
//    delay(300); //samples every 300ms
// }
// void failBar4(){
//   voltageBar4 = (((analogRead(readBar4) * 5.0) /1024.0) / (r2/(r1+r2)));
//   if (voltageBar4 < 0.1)
//   {
//     voltageBar4 = 0.0;
//   }
//   if(voltageBar4 == 0){
//     fail = true;
//     Serial.println("BAR FAILURE 4");
//     }
//   else{
//     fail = false;
//     }
//   //
//    delay(300); //samples every 300ms
// }
// void failBar5(){
//   voltageBar5 = (((analogRead(readBar5) * 5.0) /1024.0) / (r2/(r1+r2)));
//   if (voltageBar5 < 0.1)
//   {
//     voltageBar5 = 0.0;
//   }
//   if(voltageBar5 == 0){
//     fail = true;
//     Serial.println("BAR FAILURE 5");
//     }
//   else{
//     fail = false;
//     }
//   //
//    delay(300); //samples every 300ms
// }
