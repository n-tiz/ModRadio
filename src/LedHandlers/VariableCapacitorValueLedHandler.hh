#ifndef __VARIABLECAPACITORVALUELEDHANDLER_HH__
#define __VARIABLECAPACITORVALUELEDHANDLER_HH__

#include "AbstractLedHandler.hh"
#include "Utils/LimitedBuffer.hpp"
#include "Hardware/LedStrip.hpp"

const int BUFFER_SIZE = 50;

const int OUT_PIN = 3;
const int IN_PIN = PIN_A0;

const float IN_STRAY_CAP_TO_GND = 24.48;
const float IN_CAP_TO_GND = IN_STRAY_CAP_TO_GND;
const float R_PULLUP = 34.8;
const int MAX_ADC_VALUE = 1023;

class VariableCapacitorValueLedHandler : public AbstractLedHandler
{
public:
  VariableCapacitorValueLedHandler(LedStrip* strip);
  virtual void Initialize() override;
  virtual void Update() override;

protected:
private:
  LimitedBuffer<float, BUFFER_SIZE> _capacities;
};

#endif /*__VARIABLECAPACITORVALUELEDHANDLER_HH__*/