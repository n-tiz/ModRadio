#ifndef __HSL_HH__
#define __HSL_HH__

#include <Adafruit_NeoPixel.h>

uint32_t hsl(uint16_t ih, uint8_t is, uint8_t il);

uint8_t hsl_convert(float c, float t1, float t2);

#endif /*__HSL_HH__*/