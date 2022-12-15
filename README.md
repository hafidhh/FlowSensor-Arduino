# Water Flow Sensor Library Arduino
Arduino library for Flow Sensor, YF-S201

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