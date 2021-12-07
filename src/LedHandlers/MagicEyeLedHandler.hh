#ifndef __MAGICEYELEDHANDLER_HH__
#define __MAGICEYELEDHANDLER_HH__

#include "AbstractLedHandler.hh"
#include "Utils/LimitedBuffer.hpp"
#include "Hardware/LedConstants.hh"
#include "Hardware/LedStrip.hpp"

const size_t AVERAGE_VALUES = 64;

class MagicEyeLedHandler : public AbstractLedHandler
{
public:
  MagicEyeLedHandler(LedStrip* strip);
  virtual void Initialize() override;
  virtual void Update() override;

protected:

private:
  LimitedBuffer<unsigned int, AVERAGE_VALUES> _values;

};

#endif /*__MAGICEYELEDHANDLER_HH__*/