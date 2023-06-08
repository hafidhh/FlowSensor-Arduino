/**
 * @file FlowSensor.cpp
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief 
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/FlowSensor-Arduino
 */

#include "FlowSensor.h"

/**
 * @brief Construct a new FlowSensor::FlowSensor object
 * 
 * @param type Sensor Type
 * @param pin Interrupt Pin
 */
FlowSensor::FlowSensor(uint16_t type ,uint8_t pin)
{
	this->_pin = pin;
	this->_pulse1liter = type;
}

/**
 * @brief 
 * 
 * @param userFunc 
 */
void FlowSensor::begin(void (*userFunc)(void))
{
	pinMode(this->_pin, INPUT);
	digitalWrite(this->_pin, INPUT_PULLUP); // Optional Internal Pull-Up
	attachInterrupt(digitalPinToInterrupt(this->_pin), userFunc, RISING); // For better compatibility with any board, for example Arduino Leonardo Boards
}

/**
 * @brief count pulse
 * 
 */
void FlowSensor::count()
{
	this->_pulse++;
}

/**
 * @brief
 * 
 * @param calibration Calibration pulse/liter
 */
void FlowSensor::read(long calibration)
{
	this->_flowratesecound = (this->_pulse / (this->_pulse1liter + calibration)) / ((millis() - this->_timebefore) / 1000);
	this->_volume += (this->_pulse / (this->_pulse1liter + calibration));
	this->_totalpulse += this->_pulse;
	this->_pulse = 0;
	this->_timebefore = millis();
}

/**
 * @brief 
 * 
 * @return unsigned long  _totalpulse
 */
unsigned long FlowSensor::getPulse()
{
	return this->_totalpulse;
}

/**
 * @brief Reset pulse count
 * 
 */
void FlowSensor::resetPulse()
{
	this->_pulse=0;
	this->_totalpulse=0;
}

/**
 * @brief 
 * 
 * @return float flow rate / hour
 */
float FlowSensor::getFlowRate_h()
{
	this->_flowratehour = this->_flowratesecound * 3600;
	return this->_flowratehour;
}

/**
 * @brief 
 * 
 * @return float flow rate / minute
 */
float FlowSensor::getFlowRate_m()
{
	this->_flowrateminute = this->_flowratesecound * 60;
	return this->_flowrateminute;
}

/**
 * @brief 
 * 
 * @return float flow rate / secound
 */
float FlowSensor::getFlowRate_s()
{
	return this->_flowratesecound;
}

/**
 * @brief 
 * 
 * @return float volume
 */
float FlowSensor::getVolume()
{
	return this->_volume;
}

/**
 * @brief reset Volume
 * 
 */
void FlowSensor::resetVolume()
{
	this->_volume = 0;
}