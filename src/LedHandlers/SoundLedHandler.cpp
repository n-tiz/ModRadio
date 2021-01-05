#include "SoundLedHandler.hh"
#include "Utils/AudioSpectrumAnalyzer.hh"

SoundLedHandler::SoundLedHandler(LedStrip *strip, int id) : AbstractLedHandler(strip), _id(id)
{
}

void SoundLedHandler::Initialize()
{
  const unsigned int medium = LEDS_BY_RING / 2 - 1;
  const size_t quarter = LEDS_BY_RING / 4;

  for (size_t i = 0; i < quarter; i++)
  {
    size_t index = quarter - i - 1;
    _ledsPairs[index][0] = i;
    _ledsPairs[index][1] = medium - i;

    size_t rindex = quarter + i;
    _ledsPairs[rindex][0] = LEDS_BY_RING - i - 1;
    _ledsPairs[rindex][1] = medium + i + 1;
  }
}

unsigned int getAverage(const LimitedBuffer<unsigned int, VALUES> &values)
{
  unsigned int sum = 0;
  // index access
  for (unsigned int i = 0; i < values.GetActualSize(); ++i)
  {
    sum += values[i];
  }
  return sum / (float)values.GetActualSize();
}

void SoundLedHandler::Update()
{
  unsigned int groups = LEDS_BY_RING / 2;

  for (size_t i = 0; i < groups; i++)
  {
    unsigned int hueMin = 160;
    unsigned int hueMax = 200;

    auto globalId = _id * groups + i;
    unsigned int h = hueMin + (hueMax - hueMin) * sin(globalId / (float)(groups * HANDLERS_COUNT) * PI);

    // unsigned int v = (unsigned int) AudioSpectrumAnalyzer::Instance().data_avgs[4];
    unsigned int v = min((unsigned int)AudioSpectrumAnalyzer::Instance().data[(int)(globalId / (float)(groups * HANDLERS_COUNT) * X)] * 5, 255);
    _values[i].Push(v);
    //       Serial.println(v);
    //unsigned int v = random(20,255);
    v = getAverage(_values[i]);
    _strip->SetHSV(_ledsPairs[i][0], h, 255, v);
    _strip->SetHSV(_ledsPairs[i][1], h, 255, v);
  }
}
