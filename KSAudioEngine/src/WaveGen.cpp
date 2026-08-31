// ============================================================================
// Includes
// ============================================================================
#include "WaveGen.h"
#include <I2S/AudioConfig.h>
#include <arm_math.h>

#include "AugCSynth.h"
#include "ProfileScope.h"


// ============================================================================
// Public funcs
// ============================================================================

/// @brief Fill sound buffer with sounds.
void GenerateWave(uint16_t* out, size_t len)
{
	AUGCLIB_PROFILE_SCOPE("Fill sound buffer");
	AugCSynth::FillSoundBuffer((int16_t*)out, (uint16_t)len/2);
}

