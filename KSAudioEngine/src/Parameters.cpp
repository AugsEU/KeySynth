// ============================================================================
// Includes
// ============================================================================
#include "Parameters.h"

#include <string.h>
#include <stdlib.h>
#include <math.h>




// ============================================================================
// Private Types
// ============================================================================
struct SynthParameter
{
	union
	{
		float_t mFloatValue;
		uint32_t mIntValue;
	};
};


// ============================================================================
// Globals
// ============================================================================
SynthParameter gParameters[256];


// ============================================================================
// Public functions
// ============================================================================

void ZeroOutParams()
{
	memset(gParameters, 0x00, sizeof(gParameters));
}

float_t GetFloatParam(size_t idx)
{
	return gParameters[idx].mFloatValue;
}

void SetFloatParam(size_t idx, float param)
{
	gParameters[idx].mFloatValue = param;
}

uint32_t GetIntParam(size_t idx)
{
	return gParameters[idx].mIntValue;
}

void SetIntParam(size_t idx, uint32_t param)
{
	gParameters[idx].mIntValue = param;
}
