// ============================================================================
// SVfilter for subtractive synth
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>
#include <math.h>



namespace Subtractive
{

// ============================================================================
// Types
// ============================================================================
struct SVFilter
{
    float_t mLp;             // Low-pass state
    float_t mBp;             // Band-pass state
    float_t mHp;             // High-pass state
};

// ============================================================================
// Public functions
// ============================================================================
void SvfInit(SVFilter* pFilter);
float_t SvfProcess(SVFilter* pFilter, float_t sample, float_t freq, float_t res, float_t mode);

}
