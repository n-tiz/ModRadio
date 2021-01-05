#ifndef __SOUNDLEDHANDLER_HH__
#define __SOUNDLEDHANDLER_HH__

#include "AbstractLedHandler.hh"
#include "Utils/LimitedBuffer.hpp"
#include "Hardware/LedConstants.hh"
#include "Hardware/LedStrip.hpp"

#define VALUES 2

class SoundLedHandler : public AbstractLedHandler
{
public:
  SoundLedHandler(LedStrip* strip, int id);
  virtual void Initialize() override;
  virtual void Update() override;

protected:
private:
  int _id;
  unsigned int _ledsPairs[LEDS_BY_RING/2][2];
    LimitedBuffer<unsigned int, VALUES> _values[LEDS_BY_RING/2];

};

#endif /*__SOUNDLEDHANDLER_HH__*/