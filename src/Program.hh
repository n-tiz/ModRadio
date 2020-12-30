#ifndef __PROGRAM_HH__
#define __PROGRAM_HH__

#include "LedHandlers/AbstractLedHandler.hh"
#include "Utils/LimitedBuffer.hpp"

class Program
{
  public:
    Program();
    void Initialize();
    void Update();

  protected:

  private:
  AbstractLedHandler* _ledHandler;
};

#endif /*__PROGRAM_HH__*/