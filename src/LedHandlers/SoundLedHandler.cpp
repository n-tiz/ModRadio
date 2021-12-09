#include "SoundLedHandler.hh"
#include "Utils/AudioSpectrumAnalyzer.hh"

SoundLedHandler::SoundLedHandler(LedStrip *strip, const Capacitor& capacitor) : AbstractLedHandler(strip), _capacitor(capacitor)
{
}

void SoundLedHandler::Initialize()
{
  pinMode(ANALOG_INPUT,INPUT);
  // const unsigned int medium = LEDS_BY_RING / 2 - 1;
  // const size_t quarter = LEDS_BY_RING / 4;

  // for (size_t i = 0; i < quarter; i++)
  // {
  //   size_t index = quarter - i - 1;
  //   _ledsPairs[index][0] = i;
  //   _ledsPairs[index][1] = medium - i;

  //   size_t rindex = quarter + i;
  //   _ledsPairs[rindex][0] = LEDS_BY_RING - i - 1;
  //   _ledsPairs[rindex][1] = medium + i + 1;
  // }
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

// get maximum reading value
uint16_t get_max() {
  uint16_t max_v = 0;
  for(uint8_t i = 0; i < 100; i++) {
    uint16_t r = analogRead(ANALOG_INPUT);  // read from analog channel 3 (A3)
    if(max_v < r) max_v = r;
    delayMicroseconds(200);
  }
  return max_v;
}
 



void SoundLedHandler::Update()
{
  uint16_t n = _strip->GetCount();

  float capacitor = _capacitor.GetValue();
  unsigned int hueMin = max(capacitor - 25, 0);
  unsigned int hueMax = min(255, capacitor + 25);

//   auto val = analogRead(ANALOG_INPUT);
//   val = abs(val - 512); // Center on zero
// Serial.println(val);
//   for (uint8_t i = 0; i < n; i++)
//   {
//     unsigned int h = hueMin + (hueMax - hueMin) * sin(i / (float)(_strip->GetCount()) * PI);
//     bool rand = !(random() % 500);
//     _strip->SetHSV(i, h, 255, rand ? 255 : (val > 60 ? val : 0));
//   }

  uint32_t v = get_max();
  // get actual voltage (ADC voltage reference = 1.1V)
  v = v * 1100/1023;
  // calculate the RMS value ( = peak/√2 )
  v /= sqrt(2);

// Serial.println(v - 430);

  for (uint8_t i = 0; i < n; i++)
  {
    unsigned int h = hueMin + (hueMax - hueMin) * sin(i / (float)(_strip->GetCount()) * PI);
    bool rand = !(random() % 500);
//    _strip->SetHSV(i, h, 255, rand ? 255 : (val > 60 ? val : 0));
    _strip->SetHSV(i, h, 255,  (v - 430) * 20);
  }
}
