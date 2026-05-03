// ============================================================================
// Synths parameters to send over to backend synth
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>
#include "Shared/Shared.h"
#include "SynthParamBounds.h"




// ============================================================================
// SynthParamBounds: Parameter bounds
// ============================================================================
extern SynthParamBounds gSynthParamBounds[NUM_PARAMETERS];
extern int8_t gSynthParamValues[NUM_PARAMETERS];



// ============================================================================
// Public functions
// ============================================================================
void InitParamsForSubtractive();
void SendParamForSubtractive(size_t paramNum);
bool IsSubtractiveParamFloat(size_t paramNum);