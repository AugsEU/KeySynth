// ============================================================================
// Synth param bounds type and scalings
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>


// ============================================================================
// SynthParamBounds: Parameter bounds
// ============================================================================
struct SynthParamBounds
{
	SynthParamBounds() {};
    SynthParamBounds(int8_t maxValue);
    int8_t ApplyDelta(int8_t value, int8_t delta);
	
    float GetNormFloatValue(int8_t value);

    static float ScaleFloatForSubParam(uint8_t paramNum, float input);
	
    int8_t GetMaxValue();
    int8_t GetMinValue();
private:
	// A bit tricky but all bounds are (0 to X) or (-X to X)
	// To save space I store (0 to X) as X and (-X to X) as -X
    int8_t mBound = 0;
};
