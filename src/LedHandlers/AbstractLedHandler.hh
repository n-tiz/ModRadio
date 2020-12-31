#ifndef __ABSTRACTLEDHANDLER_HH__
#define __ABSTRACTLEDHANDLER_HH__

#include "Hardware/LedStrip.hpp"

class AbstractLedHandler
{
  public:
    virtual void Update() = 0;
    virtual void Initialize() = 0;

 protected:
    AbstractLedHandler(ILedStrip* strip);
    
    ILedStrip* _strip;
  private:
};

#endif /*__ABSTRACTLEDHANDLER_HH__*/