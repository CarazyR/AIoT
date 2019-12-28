// for 台灣大學講課 LoraWAN
#include <Wire.h>
#include <SPI.h>

int counter=0;
// SHARP GP2Y1010AU0F 使用測試代碼: 
//  　依使用說明最後四Pin (　紅　黑　白　藍)
// 　白 Pin　接 Arduino digital Pin ==>D7   註: D2與Dragino Lora Shield相沖
//     藍 Pin　接 Arduino analog Pin ==>A0
// I2C LED   與 Arduino ADK MEGA接線
// SDA to pin 20 SDA (Lilypad A4)
// CLK to pin 21 CLK (Lilypad A5)
//================================================
int dustPin=0;   // A0
float dustVal=0;
int ledPower=7;   // D7
int delayTime=280;
int delayTime2=40;
float offTime=9680;
//=========================
void setup() {
   pinMode(ledPower,OUTPUT);
   pinMode(dustPin, INPUT);
   Serial.begin(9600);
}
void loop()
{
   // ledPower is any digital pin on the arduino connected to Pin 3 on the sensor
    digitalWrite(ledPower,LOW); // power on the LED
    delayMicroseconds(delayTime);
    dustVal=analogRead(dustPin); // read the dust value via pin 5 on the sensor
    delayMicroseconds(delayTime2);
    digitalWrite(ledPower,HIGH); // turn the LED off
    delayMicroseconds(offTime);
    delay(3000);
    float AirQ=float((dustVal/1024)-0.0356)*120000*0.035;
    Serial.println((float(dustVal/1024)-0.0356)*120000*0.035);
    Serial.println(AirQ);
   String AirQT=" ";
   if (AirQ < 300)   { AirQT=" : Good      ";}
   if (AirQ >= 300 && AirQ < 1050)    { AirQT=" :Moderate";}
   if  ( AirQ >= 1050 && AirQ < 3000){ AirQT=" :Unhealthy";}
   if  (  AirQ > 3000){ AirQT=" :Hazardous";}
   Serial.println(AirQ+ AirQT);
  //===============================
      uint8_t data[48] ;
      String total_countString = "PM2.5 > "+ String((int)AirQ,DEC)+ AirQT ;
      for (int i=0 ; i< 48; i++)
           {
             data[i] = total_countString.charAt(i);
            }
  //==============
  delay(4000);
  counter++;
}

