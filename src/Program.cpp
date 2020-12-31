#include <Arduino.h>
#include "Program.hh"
#include "LedHandlers/VariableCapacitorValueLedHandler.hh"

Program::Program()
{
}

void Program::Initialize()
{
    FastLED.addLeds<NEOPIXEL, 6>(_leds1, LEDS1_COUNT);
   

    _ledHandlers[0] = new VariableCapacitorValueLedHandler(new LedStrip(_leds1, 0, 8));
    _ledHandlers[1] = new VariableCapacitorValueLedHandler(new LedStrip(_leds1, 8, 8));

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