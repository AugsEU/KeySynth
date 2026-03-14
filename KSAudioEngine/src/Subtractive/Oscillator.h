// ============================================================================
// Includes
// ============================================================================
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef INC_OSCILLATOR_H_
#define INC_OSCILLATOR_H_

namespace Subtractive
{

// ============================================================================
// Types
// ============================================================================
struct Oscillator
{
	float_t 	mPhase;	// Radians
};

// ============================================================================
// Public functions
// ============================================================================
void OscInit(Oscillator* osc);
void OscPhaseInc(Oscillator* osc, float_t phaseInc);

float_t OscSine(Oscillator* osc);
float_t OscSquareBLEP(Oscillator* osc, float_t dt, float_t shape);
float_t OscSquareLF(Oscillator* osc);
float_t OscSawTooth(Oscillator* osc, float_t phaseInc);
float_t OscOrgan(Oscillator* osc, float_t shape);

}

#endif /* INC_OSCILLATOR_H_ */
