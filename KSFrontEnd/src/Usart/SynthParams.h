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
#include "AugCSynth.h"



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