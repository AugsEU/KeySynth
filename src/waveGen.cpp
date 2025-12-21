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
void GenerateWave(int32_t** out, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		acc++;
		float32_t waveL = (float)acc / 100.0f;
		waveL = sinf(M_TWOPI * waveL);
		int32_t sigL = (int32_t)(4000.0f * waveL);

		float32_t waveR = (float)acc / 100.0f;
		waveR = cosf(2.0f * M_TWOPI * waveR);
		int32_t sigR = (int32_t)(4000.0f * waveR);

		uint32_t sig32 = (uint16_t)sigR;
		sig32 <<= 16;
		sig32 |= (uint16_t)sigL;
		
		out[0][i] = sig32;
		out[1][i] = sig32;

		if (acc >= 100)
			acc = 0;
	}
}