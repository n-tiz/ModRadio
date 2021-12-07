#ifndef __VARIABLECAPACITORVALUELEDHANDLER_HH__
#define __VARIABLECAPACITORVALUELEDHANDLER_HH__

#include "AbstractLedHandler.hh"
#include "Utils/LimitedBuffer.hpp"
#include "Hardware/LedStrip.hpp"
#include "Hardware/Capacitor.hh"

class VariableCapacitorValueLedHandler : public AbstractLedHandler
{
public:
  VariableCapacitorValueLedHandler(LedStrip *strip, const Capacitor& capacitor);
  virtual void Initialize() override;
  virtual void Update() override;

protected:
private:
  const Capacitor &_capacitor;
};

#endif /*__VARIABLECAPACITORVALUELEDHANDLER_HH__*/