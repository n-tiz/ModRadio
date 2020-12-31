#include <Arduino.h>
#include "Program.hh"
#include "LedHandlers/VariableCapacitorValueLedHandler.hh"

Program::Program()
{
}

void Program::Initialize()
{
   

    _ledHandlers[0] = new VariableCapacitorValueLedHandler(new LedStrip<6, 8>());
 //   _ledHandlers[1] = new VariableCapacitorValueLedHandler(Adafruit_NeoPixel(8, 6, NEO_GRB + NEO_KHZ800));

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