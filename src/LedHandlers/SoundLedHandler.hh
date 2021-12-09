#ifndef __SOUNDLEDHANDLER_HH__
#define __SOUNDLEDHANDLER_HH__

#include "AbstractLedHandler.hh"
#include "Utils/LimitedBuffer.hpp"
#include "Hardware/LedConstants.hh"
#include "Hardware/LedStrip.hpp"
#include "Hardware/Capacitor.hh"

#define VALUES 2

const int ANALOG_INPUT = PIN_A0;

class SoundLedHandler : public AbstractLedHandler
{
public:
  SoundLedHandler(LedStrip* strip, const Capacitor& capacitor);
  virtual void Initialize() override;
  virtual void Update() override;

protected:
private:
 // LimitedBuffer<unsigned int, VALUES> _values[LEDS_BY_RING/2];
  const Capacitor &_capacitor;
};

#endif /*__SOUNDLEDHANDLER_HH__*/