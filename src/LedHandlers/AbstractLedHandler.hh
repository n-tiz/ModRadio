#ifndef __ABSTRACTLEDHANDLER_HH__
#define __ABSTRACTLEDHANDLER_HH__

 #include <Adafruit_NeoPixel.h>

class AbstractLedHandler
{
  public:
    virtual void Update() = 0;
    virtual void Initialize() = 0;

 protected:
    AbstractLedHandler(Adafruit_NeoPixel strip);
    Adafruit_NeoPixel _strip;

  private:
};

#endif /*__ABSTRACTLEDHANDLER_HH__*/