#include "VariableCapacitorValueLedHandler.hh"
#include "Utils/hsl.hh"

VariableCapacitorValueLedHandler::VariableCapacitorValueLedHandler(Adafruit_NeoPixel strip) : AbstractLedHandler(strip)
{
}

void VariableCapacitorValueLedHandler::Initialize()
{
  pinMode(OUT_PIN, OUTPUT);
  pinMode(IN_PIN, OUTPUT);

  _strip.begin();
  _strip.show();

  Serial.begin(9600);
}

float GetCapacitorValue()
{
  pinMode(IN_PIN, INPUT);
  digitalWrite(OUT_PIN, HIGH);
  int val = analogRead(IN_PIN);
  digitalWrite(OUT_PIN, LOW);

  pinMode(IN_PIN, OUTPUT);

  return (float)val * IN_CAP_TO_GND / (float)(MAX_ADC_VALUE - val);
}

float getAverage(const LimitedBuffer<float, BUFFER_SIZE> &capas)
{
  float sum = 0;
  // index access
  for (unsigned int i = 0; i < capas.GetActualSize(); ++i)
  {
    sum += capas[i];
  }
  return sum / (float)capas.GetActualSize();
}

void VariableCapacitorValueLedHandler::Update()
{
  float capa = GetCapacitorValue();
   _capacities.Push(capa);
   uint16_t n = _strip.numPixels();

   float average = getAverage(_capacities);

   uint16_t hue = min(359, max((average - 19) / 500 * 359, 0)); // 0-359
 // uint16_t hue = min(359, max((capa - 19) / 500 * 359, 0)); // 0-359

  uint8_t saturation = 100; // 0-100
  uint8_t lightness = 50;   // 0-100
  uint32_t color = hsl(hue, saturation, lightness);

  for (uint8_t i = 0; i < n; i++)
  {
    _strip.setPixelColor(i, color);
    _strip.show();
  }
  Serial.println("lol");
}
