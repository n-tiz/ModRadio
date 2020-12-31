#include "VariableCapacitorValueLedHandler.hh"

VariableCapacitorValueLedHandler::VariableCapacitorValueLedHandler(LedStrip *strip) : AbstractLedHandler(strip)
{
}

void VariableCapacitorValueLedHandler::Initialize()
{
  pinMode(OUT_PIN, OUTPUT);
  pinMode(IN_PIN, OUTPUT);
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
  uint16_t n = _strip->GetCount();

  float average = getAverage(_capacities);

  uint8_t h = min(255, max((average - 19) / 500 * 255, 0)); // 0-255

  for (uint8_t i = 0; i < n; i++)
  {
    _strip->SetHSV(i, h, 255, 120);
  }
}
