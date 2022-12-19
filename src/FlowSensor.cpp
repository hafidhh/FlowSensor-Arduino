/**
 * @file FlowSensor.cpp
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

#include "Arduino.h"
#include "FlowSensor.h"

/**
 * @brief Construct a new FlowSensor::FlowSensor object
 * 
 * @param type 
 * @param pin 
 */
FlowSensor::FlowSensor(uint8_t type ,uint8_t pin)
{
  _pin = pin;
  _type = type;
  switch (this->_type)
  {
  case YFS201:
    _pulse1liter = 450;
    break;
  
  default:
    break;
  }
}

/**
 * @brief 
 * 
 * @return uint8_t pin
 */
uint8_t FlowSensor::getPin()
{
  return this->_pin;
}

/**
 * @brief 
 * 
 * @return uint8_t sensor type
 */
uint8_t FlowSensor::getType()
{
  return this->_type;
}

/**
 * @brief count pulse
 * 
 */
void FlowSensor::count()
{
  this->_pulse++;
  this->_totalpulse++;
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
  attachInterrupt(this->_pin, userFunc, RISING);
}

/**
 * @brief
 * 
 * @param calibration 
 */
void FlowSensor::read(int calibration)
{
  this->_flowratesecound = (this->_pulse / (this->_pulse1liter + calibration)) / ((millis() - _timebefore) / 1000);
  this->_volume += (this->_pulse / (this->_pulse1liter + calibration));
  this->_pulse = 0;
}

/**
 * @brief 
 * 
 * @return int total pulse
 */
int FlowSensor::getPulse()
{
  return this->_totalpulse;
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