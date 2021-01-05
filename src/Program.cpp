#include <Arduino.h>
#include "Program.hh"
#include "LedHandlers/VariableCapacitorValueLedHandler.hh"
#include "LedHandlers/SoundLedHandler.hh"
#include "Utils/AudioSpectrumAnalyzer.hh"

Program::Program()
{
}

void Program::Initialize()
{
    AudioSpectrumAnalyzer::Instance().Initialize();

    randomSeed(42);
    FastLED.addLeds<NEOPIXEL, 6>(_leds1, LEDS1_COUNT);

    for (size_t i = 0; i < HANDLERS_COUNT; i++)
    {
        _ledHandlers[i] = new SoundLedHandler(new LedStrip(_leds1, LEDS_BY_RING * i, LEDS_BY_RING), i);

        //  _ledHandlers[i] = new VariableCapacitorValueLedHandler(new LedStrip(_leds1, LEDS_BY_RING * i, LEDS_BY_RING));
    }

    for (size_t i = 0; i < HANDLERS_COUNT; i++)
    {
        _ledHandlers[i]->Initialize();
    }
}

void Program::Update()
{
    AudioSpectrumAnalyzer::Instance().Update();
    for (size_t i = 0; i < HANDLERS_COUNT; i++)
    {
        _ledHandlers[i]->Update();
    }
    FastLED.show();
}