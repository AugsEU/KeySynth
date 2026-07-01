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



// ============================================================================
// Public functions
// ============================================================================

/// @brief Get a synth parameter
/// @param paramNum Parameter id
/// @return Synth param value
int8_t GetSynthParamValue(size_t paramNum);

/// @brief Send every parameter in the cache over to the synth
void ForceSendAllParams();

/// Subtractive synth

/// @brief Initialise parameters for the subtractive synth
void InitParamsForSubtractive();

/// @brief Send a parameter over to the subtractive synth
/// @param paramNum The parameter id
/// @param value The parameter value
void SendParamForSubtractive(size_t paramNum, int8_t value);

/// @brief Is this a float or integer parameter for the subtractive synth?
/// @param paramNum Parameter id
/// @return True if this is a float parameter
bool IsSubtractiveParamFloat(size_t paramNum);