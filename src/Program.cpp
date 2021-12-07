#include <Arduino.h>
#include "Program.hh"
#include "LedHandlers/VariableCapacitorValueLedHandler.hh"
#include "LedHandlers/SoundLedHandler.hh"
#include "LedHandlers/MagicEyeLedHandler.hh"
#include "Utils/AudioSpectrumAnalyzer.hh"

Program::Program()
{
}

void Program::Initialize()
{
    randomSeed(42);
    _capacitor.Initialize();
    FastLED.addLeds<NEOPIXEL, 6>(_leds1, TOTAL_LEDS_COUNT);
    _ledHandlers[0] = new SoundLedHandler(new LedStrip(_leds1, 0, LEDS_BY_RING * RINGS_COUNT));
    _ledHandlers[1] = new VariableCapacitorValueLedHandler(new LedStrip(_leds1, LEDS_BY_RING * RINGS_COUNT, LEDS_IN_FRONT_RUBAN), _capacitor);
    _ledHandlers[2] = new MagicEyeLedHandler(new LedStrip(_leds1, LEDS_BY_RING * RINGS_COUNT + LEDS_IN_FRONT_RUBAN, LEDS_IN_EYE));

    for (size_t i = 0; i < HANDLERS_COUNT; i++)
    {
        _ledHandlers[i]->Initialize();
    }
}

void Program::Update()
{
    _capacitor.Update();
    for (size_t i = 0; i < HANDLERS_COUNT; i++)
    {
        _ledHandlers[i]->Update();
    }
    FastLED.show();
}