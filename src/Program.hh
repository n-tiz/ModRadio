#ifndef __PROGRAM_HH__
#define __PROGRAM_HH__

#include "LedHandlers/AbstractLedHandler.hh"
#include "Utils/LimitedBuffer.hpp"
#include "Hardware/LedConstants.hh"
#include "Hardware/Capacitor.hh"

const size_t HANDLERS_COUNT = 3;


class Program
{
  public:
    Program();
    void Initialize();
    void Update();

  protected:

  private:
    AbstractLedHandler* _ledHandlers[HANDLERS_COUNT];
    CRGB _leds1[TOTAL_LEDS_COUNT];
    Capacitor _capacitor;
};

#endif /*__PROGRAM_HH__*/