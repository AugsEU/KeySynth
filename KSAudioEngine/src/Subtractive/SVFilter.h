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
    float mLp;             // Low-pass state
    float mBp;             // Band-pass state
    float mHp;             // High-pass state
};

// ============================================================================
// Public functions
// ============================================================================
void SvfInit(SVFilter* pFilter);
float SvfProcess(SVFilter* pFilter, float sample, float freq, float res, float mode);

}
