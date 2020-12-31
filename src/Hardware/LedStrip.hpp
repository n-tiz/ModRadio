#ifndef __LEDSTRIP_HH__
#define __LEDSTRIP_HH__

#include <FastLED.h>
#include "LedHandlers/AbstractLedHandler.hh"
#include "Utils/LimitedBuffer.hpp"

class ILedStrip
{
public:
  virtual ~ILedStrip() {}
  virtual size_t GetCount() = 0;
  virtual void SetRGB(unsigned int index, CRGB color) = 0;
  virtual void SetRGB(unsigned int index, uint8_t r, uint8_t g, uint8_t b) = 0;
  virtual void SetHSV(unsigned int index, CHSV color) = 0;
  virtual void SetHSV(unsigned int index, uint8_t h, uint8_t s, uint8_t v) = 0;

protected:
  ILedStrip() {}
};

template <int P, int C>
class LedStrip : public ILedStrip
{
public:
  LedStrip(unsigned int offset = 0) : _count(C)
  {
    FastLED.addLeds<NEOPIXEL, P>(_leds, offset, C);
  }

  virtual size_t GetCount() override
  {
    return _count;
  }

  virtual void SetRGB(unsigned int index, CRGB color) override
  {
    SetRGB(index, color.r, color.g, color.b);
  }

  virtual void SetRGB(unsigned int index, uint8_t r, uint8_t g, uint8_t b) override
  {
    _leds[index].setRGB(r, g, b);
  }

  virtual void SetHSV(unsigned int index, CHSV color) override
  {
    SetHSV(index, color.h, color.s, color.v);
  }

  virtual void SetHSV(unsigned int index, uint8_t h, uint8_t s, uint8_t v) override
  {
    _leds[index].setHSV(h, s, v);
  }

protected:
private:
  CRGB _leds[C];
  size_t _count;
};

#endif /*__LEDSTRIP_HH__*/