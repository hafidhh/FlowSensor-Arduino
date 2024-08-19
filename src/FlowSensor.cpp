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
 * @brief setType, change type
 * 
 * @param type 
 */
void FlowSensor::setType(uint16_t type)
{
	this->_pulse1liter = type;
}

/**
 * @brief setPin, change pin
 * 
 * @param pin 
 */
void FlowSensor::setPin(uint8_t pin)
{
	detachInterrupt(this->_pin);
	this->_pin = pin;
}

/**
 * @brief sensor begin
 * 
 * @param userFunc 
 * @param pullup default value is fasle (0), if you have external pull up you can set to true (1)
 */
void FlowSensor::begin(void (*userFunc)(void), bool pullup)
{
	if (pullup == true)
		pinMode(this->_pin, INPUT);
	else
		pinMode(this->_pin, INPUT_PULLUP); // Optional Internal Pull-Up
	
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
 * @brief read sensor, get value
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
 * @brief get total pulse
 * 
 * @return unsigned long  _totalpulse
 */
unsigned long FlowSensor::getPulse()
{
	return this->_totalpulse;
}

/**
 * @brief get value flowrate/hour (L/h)
 * 
 * @return float flow rate / hour
 */
float FlowSensor::getFlowRate_h()
{
	this->_flowratehour = this->_flowratesecound * 3600;
	return this->_flowratehour;
}

/**
 * @brief get value flowrate/minute (L/m)
 * 
 * @return float flow rate / minute
 */
float FlowSensor::getFlowRate_m()
{
	this->_flowrateminute = this->_flowratesecound * 60;
	return this->_flowrateminute;
}

/**
 * @brief get value flowrate/second (L/s)
 * 
 * @return float flow rate / second
 */
float FlowSensor::getFlowRate_s()
{
	return this->_flowratesecound;
}

/**
 * @brief get Volume value (L)
 * 
 * @return float volume
 */
float FlowSensor::getVolume()
{
	return this->_volume;
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
 * @brief reset Volume
 * 
 */
void FlowSensor::resetVolume()
{
	this->_volume = 0;
}