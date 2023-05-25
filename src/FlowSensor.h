/**
 * @file FlowSensor.h
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief 
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/FlowSensor-Arduino
 */

#ifndef FlowSensor_h
#define FlowSensor_h

#include "Arduino.h"
#include "FlowSensor_Type.h"

/**
 * @brief FlowSensor Class > Sensor(uint8_t Type, uint8_t Pin)
 * 
 */
class FlowSensor
{
private:
	uint8_t _pin;
	volatile unsigned long _totalpulse;
	volatile unsigned long _pulse;
	float _pulse1liter;
	float _flowratehour;
	float _flowrateminute;
	float _flowratesecound;
	float _volume;
	unsigned long _timebefore = 0;

public:
	FlowSensor(uint16_t type ,uint8_t pin);
	void begin(void (*userFunc)(void));
	void count();
	void read(long calibration = 0);
	unsigned long getPulse();
	void resetPulse();
	float getFlowRate_h();
	float getFlowRate_m();
	float getFlowRate_s();
	float getVolume();
	void resetVolume();
};

#endif