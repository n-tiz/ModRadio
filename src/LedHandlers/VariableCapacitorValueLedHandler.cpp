#include <Arduino.h>
#include "VariableCapacitorValueLedHandler.hh"

VariableCapacitorValueLedHandler::VariableCapacitorValueLedHandler(LedStrip *strip, const Capacitor &capacitor)
    : AbstractLedHandler(strip), _capacitor(capacitor)
{
}

void VariableCapacitorValueLedHandler::Initialize()
{
}

void VariableCapacitorValueLedHandler::Update()
{

  uint16_t n = _strip->GetCount();

  float capacitor = _capacitor.GetValue();
  unsigned int hueMin = max(capacitor - 25, 0);
  unsigned int hueMax = min(255, capacitor + 25);

  for (uint8_t i = 0; i < n; i++)
  {
    unsigned int h = hueMin + (hueMax - hueMin) * sin(i / (float)(_strip->GetCount()) * PI);
    _strip->SetHSV(i, h, 255, 120 + cos(millis() /1000.0)*25);
  }
}
