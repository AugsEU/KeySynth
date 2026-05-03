// ============================================================================
// Includes
// ============================================================================
#include <waveGen.h>
#include <I2S/AudioConfig.h>
#include <arm_math.h>
#include <Voice.h>
#include "Subtractive/SubWaveGen.h"

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
	Subtractive::FillSoundBuffer(out, len/2);
}

