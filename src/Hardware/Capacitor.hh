#ifndef __CAPACITOR_HH__
#define __CAPACITOR_HH__

#include <Arduino.h>
#include "Utils/LimitedBuffer.hpp"

const int OUT_PIN = 3;
const int IN_PIN = PIN_A1;

const int BUFFER_SIZE = 50;

const float IN_STRAY_CAP_TO_GND = 24.48;
const float IN_CAP_TO_GND = IN_STRAY_CAP_TO_GND;
const float R_PULLUP = 34.8;
const int MAX_ADC_VALUE = 1023;

class Capacitor
{
  public:
    Capacitor();
    void Initialize();
    void Update();
    float GetValue() const;

  private:
    float ReadCapacitorValue();
    LimitedBuffer<float, BUFFER_SIZE> _capacities;
};

#endif /*__CAPACITOR_HH__*/