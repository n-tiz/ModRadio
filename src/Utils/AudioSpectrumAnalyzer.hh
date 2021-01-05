#ifndef __AUDIOSPECTRUMANALYZER_HH__
#define __AUDIOSPECTRUMANALYZER_HH__

// Based on "32-Band Audio Spectrum Visualizer Analyzer" written by shajeeb
// See https://create.arduino.cc/projecthub/shajeeb/32-band-audio-spectrum-visualizer-analyzer-902f51

#include <arduinoFFT.h>
#include "Hardware/LedConstants.hh"

//Must be a power of 2
#define SAMPLES 32
#define X ((SAMPLES)/2)

class AudioSpectrumAnalyzer
{
public:
    static AudioSpectrumAnalyzer& Instance();

    void Initialize();

    void Update();

    unsigned char data[X];

private:
    double vReal[SAMPLES];
    double vImag[SAMPLES];
    arduinoFFT _fft;

    static AudioSpectrumAnalyzer *_instance;
    AudioSpectrumAnalyzer() {}
};

#endif /*__AUDIOSPECTRUMANALYZER_HH__*/