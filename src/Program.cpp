#include <Arduino.h>
#include "Program.hh"
#include "LedHandlers/VariableCapacitorValueLedHandler.hh"



Program::Program()
{
}

void Program::Initialize()
{
    _ledHandler = new VariableCapacitorValueLedHandler(Adafruit_NeoPixel(16, 6, NEO_GRB + NEO_KHZ800));
    _ledHandler->Initialize();
}

void Program::Update()
{
    _ledHandler->Update();
}