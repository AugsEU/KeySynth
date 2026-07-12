// ============================================================================
// Includes
// ============================================================================
#include "WaveGen.h"
#include <I2S/AudioConfig.h>
#include <arm_math.h>

#include "AugCSynth.h"

// ============================================================================
// Globals
// ============================================================================
volatile float gFreq = 440.0f;
volatile float gVol = 1.0f;


// ============================================================================
// Public funcs
// ============================================================================

/// @brief Fill sound buffer with sounds.
void GenerateWave(uint16_t* out, size_t len)
{
	AugCSynth::Subtractive::FillSoundBuffer((int16_t*)out, (uint16_t)len/2);
}

