#ifndef __PROGRAM_HH__
#define __PROGRAM_HH__

#include "LedHandlers/AbstractLedHandler.hh"
#include "Utils/LimitedBuffer.hpp"

const size_t LEDS1_COUNT = 2*8;

const size_t HANDLERS_COUNT = 2;

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