/**
 * @file FlowSensor.h
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

#ifndef FlowSensor_h
#define FlowSensor_h

#include "Arduino.h"

static const uint8_t YFS201{1};

class FlowSensor
{
private:
  uint8_t _pin;
  uint8_t _type;
  unsigned long _totalpulse;
  unsigned long _pulse;
  float _pulse1liter;
  float _flowrateminute;
  float _flowratesecound;
  float _volume;
  long _timebefore = 0;

public:
  FlowSensor(uint8_t type ,uint8_t pin);
  uint8_t getPin();
  uint8_t getType();
  void begin(void (*userFunc)(void));
  void read(int calibration = 0);
  void count();
  unsigned long getPulse();
  float getFlowRate_m();
  float getFlowRate_s();
  float getVolume();
};

#endif
