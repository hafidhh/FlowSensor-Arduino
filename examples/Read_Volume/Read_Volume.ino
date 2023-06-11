/**
 * @file Read_Volume.ino
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief 
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/FlowSensor-Arduino
 */

#include <Arduino.h>
#include <FlowSensor.h>

// Sensor Type
// YFS201;
// YFB1;
// OF10ZAT;
// OF10ZZT;
// OF05ZAT;
// OF05ZZT;

#define type YFS201
#define pin D2 // pin -> interrupt pin

FlowSensor Sensor(type, pin);
unsigned long timebefore = 0; // same type as millis()
unsigned long reset = 0;

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
	// Print Volume
	if (millis() - timebefore >= 1000)
	{
		Sensor.read();
		Serial.print("Volume (L) : ");
		Serial.println(Sensor.getVolume());
		timebefore = millis();
	}

	// Reset Volume
	if (millis() - reset >= 60000)
	{
		Sensor.resetVolume();
		Serial.print("Volume (L) : ");
		Serial.println(Sensor.getVolume());
		reset = millis();
	}
}
