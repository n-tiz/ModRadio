#ifndef __CIRCULARBUFFERVARIABLECAPACITORVALUELEDHANDLER_HH__
#define __CIRCULARBUFFERVARIABLECAPACITORVALUELEDHANDLER_HH__

#include "AbstractLedHandler.hh"
#include "Utils/LimitedBuffer.hpp"

const int BUFFER_SIZE = 50;

const int OUT_PIN = A2;
const int IN_PIN = A0;

const float IN_STRAY_CAP_TO_GND = 24.48;
const float IN_CAP_TO_GND = IN_STRAY_CAP_TO_GND;
const float R_PULLUP = 34.8;
const int MAX_ADC_VALUE = 1023;

class VariableCapacitorValueLedHandler : public AbstractLedHandler
{
public:
  VariableCapacitorValueLedHandler(Adafruit_NeoPixel stip);
  virtual void Initialize() override;
  virtual void Update() override;

protected:
private:
  LimitedBuffer<float, BUFFER_SIZE> _capacities;
};

#endif /*__CIRCULARBUFFERVARIABLECAPACITORVALUELEDHANDLER_HH__*/