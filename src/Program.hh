#ifndef __PROGRAM_HH__
#define __PROGRAM_HH__

#include "LedHandlers/AbstractLedHandler.hh"
#include "Utils/LimitedBuffer.hpp"
#include "Hardware/LedConstants.hh"

class Program
{
  public:
    Program();
    void Initialize();
    void Update();

  protected:

  private:
    AbstractLedHandler* _ledHandlers[HANDLERS_COUNT];
    CRGB _leds1[LEDS1_COUNT];
};

#endif /*__PROGRAM_HH__*/