# Water Flow Sensor Library Arduino
[![arduino-library-badge](https://www.ardu-badge.com/badge/FlowSensor.svg?)](https://www.ardu-badge.com/FlowSensor)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/hafidh/library/FlowSensor.svg)](https://registry.platformio.org/libraries/hafidh/FlowSensor)
[![GitHub release](https://img.shields.io/github/release/hafidhh/FlowSensor-Arduino.svg)](https://github.com/hafidhh/FlowSensor-Arduino/releases)
[![GitHub](https://img.shields.io/github/license/hafidhh/FlowSensor-Arduino.svg)](https://github.com/hafidhh/FlowSensor-Arduino/blob/master/LICENSE.md)
## Description
   
Arduino library for Flow Sensor, YF-S201   

### Volume Formula   
```math
Volume (L) = {Total Pulse \over Pulse1Liter}
```

### Flowrate Formula   
```math
Q = {Frequecy \over Pulse1Liter}60
```
```math
Q = {Pulse/Time \over Pulse1Liter}60
```
Q = Flowrate (Liter/minute)   

## Usages
See [all axemples](https://github.com/hafidhh/FlowSensor-Arduino/tree/master/examples)

### initialization
```cpp
#include <FlowSensor_Arduino.h>

uint8_t type = YFS201; // type : Sensor type
uint8_t pin = D2; // pin : interrupt pin

FlowSensor_Arduino Sensor(type, pin);
```

### Sensor begin
param **`userFunc`** 
```cpp
void begin(void (*userFunc)(void))
```

### Sensor Read
param **`calibration`**
```cpp
void read(int calibration)
```

### Count Pulse
```cpp
void count()
```

### Get Total Pulse
return **`total pulse`**
```cpp
int getPulse()
```

### Get Flowrate (L/s)
return **`Flowrate`** (L/s)
```cpp
float getFlowRate_s()
```

### Get Flowrate (L/m)
return **`Flowrate`** (L/m)
```cpp
float getFlowRate_m() 
```

### Get Total Volume (L)
return **`Volume`** (L)
```cpp
float getVolume()
```  