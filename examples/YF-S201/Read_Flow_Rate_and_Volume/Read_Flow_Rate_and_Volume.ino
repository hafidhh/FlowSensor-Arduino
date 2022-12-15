/**
 * @file Read_Flow_Rate_and_Volume.ino
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2022-12-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 */

#include <Arduino.h>
#include <FlowSensor_Arduino.h>

// pin -> interrupt pin
FlowSensor_Arduino Sensor(YFS201, D2);
int timebefore = 0;

void count()
{
  Sensor.count();
}

void setup() {
  Serial.begin(115200);
  Sensor.begin(count);
}

void loop() {
  if (millis() - timebefore >= 1000)
  {
    Sensor.read();
    Serial.print("Flow rate (L/minute) : ");
    Serial.println(Sensor.getFlowRate_m());
    Serial.print("Volume (L) : ");
    Serial.println(Sensor.getVolume());
    timebefore = millis();
  }
}