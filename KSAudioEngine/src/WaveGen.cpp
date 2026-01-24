// ============================================================================
// Includes
// ============================================================================
#include <waveGen.h>
#include <I2S/AudioConfig.h>
#include <arm_math.h>
#include <Voice.h>

// ============================================================================
// Globals
// ============================================================================
volatile float_t gFreq = 440.0f;
volatile float_t gVol = 1.0f;


// ============================================================================
// Public funcs
// ============================================================================
float_t gSteppers[VOICE_POLYPHONY] = {};

float_t Saw(float_t x)
{
	if(x < 0.5f)
	{
		return 2.0f * x;
	}

	return 2.0f * x - 2.0f;
}

/// @brief Fill sound buffer with sounds.
void GenerateWave(uint16_t* out, size_t len)
{
	for (size_t i = 0; i < len; i+=2)
	{
		// Calculate wave
		float_t wave = 0.0f;
		for(int i = 0; i < VOICE_POLYPHONY; i++)
		{
			if(gVoices[i].mNoteNum != INVALID_NOTE)
			{
				float_t& t = gSteppers[i];
				t += gVoices[i].mPhaseShift;
				if(t >= 1.0f) t -= 1.0f;

				wave += Saw(t);
			}
		}
		wave *= gVol / VOICE_POLYPHONY;

		int16_t sig = (int16_t)(8000.0f * wave);
		
		// Write left & right
		out[i] = (uint16_t)sig;
        out[i+1] = (uint16_t)sig;
	}
}

