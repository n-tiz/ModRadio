#include "Capacitor.hh"

Capacitor::Capacitor()
{
}

void Capacitor::Initialize()
{
    pinMode(OUT_PIN, OUTPUT);
    pinMode(IN_PIN, OUTPUT);
}

void Capacitor::Update()
{
    float capa = ReadCapacitorValue();
    _capacities.Push(capa);
}

float getAverage(const LimitedBuffer<float, BUFFER_SIZE> &capas)
{
    float sum = 0;

    for (unsigned int i = 0; i < capas.GetActualSize(); ++i)
    {
        sum += capas[i];
    }

    return sum / (float)capas.GetActualSize();
}

float Capacitor::GetValue() const
{
    return (getAverage(_capacities) - 19) / 500 * 255;
}

float Capacitor::ReadCapacitorValue()
{
    pinMode(IN_PIN, INPUT);

    digitalWrite(OUT_PIN, HIGH);
    int val = analogRead(IN_PIN);
    digitalWrite(OUT_PIN, LOW);

    pinMode(IN_PIN, OUTPUT);

    return (float)val * IN_CAP_TO_GND / (float)(MAX_ADC_VALUE - val);
}
