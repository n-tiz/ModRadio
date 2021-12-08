#include "MagicEyeLedHandler.hh"
#include "Utils/AudioSpectrumAnalyzer.hh"

MagicEyeLedHandler::MagicEyeLedHandler(LedStrip *strip) : AbstractLedHandler(strip)
{
}

void MagicEyeLedHandler::Initialize()
{

}

unsigned int getAverage(const LimitedBuffer<unsigned int, AVERAGE_VALUES> &values)
{
  unsigned int sum = 0;
  // index access
  for (unsigned int i = 0; i < values.GetActualSize(); ++i)
  {
    sum += values[i];
  }
  return sum / (float)values.GetActualSize();
}

void MagicEyeLedHandler::Update()
{
  uint16_t n = _strip->GetCount();

  uint8_t r = random() % 42 == 0 ? 200 : 10;
  _values.Push(r);
  uint8_t v = getAverage(_values);
  for (uint8_t i = 0; i < n; i++)
  {
    _strip->SetHSV(i, 85, 175, v);
  }
}
