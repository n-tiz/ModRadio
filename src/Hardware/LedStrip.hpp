#ifndef __LEDSTRIP_HH__
#define __LEDSTRIP_HH__

#include <FastLED.h>
#include "LedHandlers/AbstractLedHandler.hh"
#include "Utils/LimitedBuffer.hpp"

class LedStrip
{
public:
  LedStrip(CRGB* leds, unsigned int offset, size_t count) : _leds(leds), _offset(offset), _count(count)
  {
  }

  size_t GetCount()
  {
    return _count;
  }

  void SetRGB(unsigned int index, CRGB color)
  {
    SetRGB(index, color.r, color.g, color.b);
  }

  void SetRGB(unsigned int index, uint8_t r, uint8_t g, uint8_t b)
  {
    _leds[index + _offset].setRGB(r, g, b);
  }

  void SetHSV(unsigned int index, CHSV color)
  {
    SetHSV(index, color.h, color.s, color.v);
  }

  void SetHSV(unsigned int index, uint8_t h, uint8_t s, uint8_t v)
  {
    _leds[index + _offset].setHSV(h, s, v);
  }

protected:
private:
  CRGB* _leds;
  unsigned int _offset;
  size_t _count;
};

#endif /*__LEDSTRIP_HH__*/