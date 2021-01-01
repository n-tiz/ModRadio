#include <Arduino.h>
#include "Program.hh"
#include "LedHandlers/VariableCapacitorValueLedHandler.hh"

Program::Program()
{
}

void Program::Initialize()
{
    FastLED.addLeds<NEOPIXEL, 6>(_leds1, LEDS1_COUNT);

    for (size_t i = 0; i < HANDLERS_COUNT; i++)
    {
        _ledHandlers[i] = new VariableCapacitorValueLedHandler(new LedStrip(_leds1, LEDS_BY_RING * i, LEDS_BY_RING));
    }

    for (size_t i = 0; i < HANDLERS_COUNT; i++)
    {
        _ledHandlers[i]->Initialize();
    }
}

void Program::Update()
{
    for (size_t i = 0; i < HANDLERS_COUNT; i++)
    {
        _ledHandlers[i]->Update();
    }
    FastLED.show();
}