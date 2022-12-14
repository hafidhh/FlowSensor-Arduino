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
 * https://github.com/hafidhh/FlowSensor-Arduino
 */

#include <Arduino.h>
#include <FlowSensor.h>

// pin -> interrupt pin
FlowSensor Sensor(YFS201, D2);
unsigned long timebefore = 0; // Same type as millis()

// Uncomment if use ESP8266 and ESP32
// void IRAM_ATTR count()
// {
//   Sensor.count();
// }

// Comment if use ESP8266 and ESP32
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
