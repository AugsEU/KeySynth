// ============================================================================
// Synth parameters
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Includes
// ============================================================================
#include <math.h>
#include <stdint.h>
#include <Shared/Shared.h>


// ============================================================================
// Public functions
// ============================================================================

void ZeroOutParams();

float_t GetFloatParam(size_t idx);
void SetFloatParam(size_t idx, float param);

uint32_t GetIntParam(size_t idx);
void SetIntParam(size_t idx, uint32_t param);

SynthMode GetSynthMode();
void SetSynthMode(SynthMode mode);