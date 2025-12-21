// ============================================================================
// Includes
// ============================================================================
#include <waveGen.h>
#include <arm_math.h>

// ============================================================================
// Public funcs
// ============================================================================

int32_t acc = 0;

/// @brief Fill sound buffer with sounds.
void GenerateWave(uint16_t* out, size_t len)
{
	for (size_t i = 0; i < len; i+=2)
	{
		acc++;
		float32_t waveL = (float)acc / 200.0f;
		waveL = sinf(M_TWOPI * waveL);
		int16_t sigL = (int16_t)(4000.0f * waveL);

		float32_t waveR = (float)acc / 200.0f;
		waveR = cosf(2.0f * M_TWOPI * waveR);
		int16_t sigR = (int16_t)(4000.0f * waveR);
		
		out[i] = (uint16_t)sigL;
        out[i+1] = (uint16_t)sigR;

		if (acc >= 200)
			acc = 0;
	}
}