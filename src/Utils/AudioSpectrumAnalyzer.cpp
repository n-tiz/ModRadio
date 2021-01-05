#include "AudioSpectrumAnalyzer.hh"

AudioSpectrumAnalyzer *AudioSpectrumAnalyzer::_instance;

AudioSpectrumAnalyzer &AudioSpectrumAnalyzer::Instance()
{

    //static Cleanup cleanup;
    if (AudioSpectrumAnalyzer::_instance == nullptr)
        AudioSpectrumAnalyzer::_instance = new AudioSpectrumAnalyzer();
    return *AudioSpectrumAnalyzer::_instance;
}

void AudioSpectrumAnalyzer::Initialize()
{
       _fft = arduinoFFT();

    // set ADC to free running mode and set pre-scalar to 32 (0xe5)
    ADCSRA = 0b11100101;

    // use pin A1 and external voltage reference
    ADMUX = 0b00000001;

    // wait to get reference voltage stabilized
    delay(50);
}

void AudioSpectrumAnalyzer::Update()
{
    for (int i = 0; i < SAMPLES; i++)
    {
        // wait for ADC to complete current conversion ie ADIF bit set
        while (!(ADCSRA & 0x10))
            ;

        // clear ADIF bit so that ADC can do next operation (0xf5)
        ADCSRA = 0b11110101;

        // Read from ADC
        int value = ADC;
        // Copy to bins after compressing
        vReal[i] = value;
        vImag[i] = 0;
    }

//     for (int i = 0; i < X; i++)
//     {
//         Serial.print(i);
//         Serial.print(" : ");
//         Serial.println(vReal[i]);         
//  }

    _fft = arduinoFFT(vReal, vImag, SAMPLES, 0);
    _fft.DCRemoval();
    // -- Sampling

    // ++ FFT
     _fft.Windowing(FFT_WIN_TYP_BLACKMAN, FFT_FORWARD);
     _fft.Compute(FFT_FORWARD);
     _fft.ComplexToMagnitude();



    for (int i = 0; i < X; i++)
    {
        data[i] = vReal[i];
    }
    //Serial.println((unsigned int)data_avgs[0]);
    // -- re-arrange FFT result to match with no. of columns on display ( xres )
}