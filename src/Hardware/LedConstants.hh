#ifndef __LEDCONSTANTS_HH__
#define __LEDCONSTANTS_HH__

#include <stddef.h>

const size_t RINGS_COUNT = 5;
const size_t LEDS_BY_RING = 8;
const size_t LEDS_IN_FRONT_RUBAN = 21;
const size_t LEDS_IN_EYE = 2;
const size_t TOTAL_LEDS_COUNT = RINGS_COUNT * LEDS_BY_RING + LEDS_IN_FRONT_RUBAN + LEDS_IN_EYE;

#endif /*__LEDCONSTANTS_HH__*/