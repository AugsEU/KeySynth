// ============================================================================
// String in language displayable to user.
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>

#include <AugCSynth.h>


// ============================================================================
// Public functions
// ============================================================================
/// @brief Convert tuning to string(max 7 len)
const char* const TuningToString(AugCSynth::Tuning tuning);

/// @brief Convert delay mode to string (max 7 len)
const char* const DelayModeToString(AugCSynth::DelayMode delay);

/// @brief Convert delay mode to string (max 7 len)
const char* const SoundTypeToString(AugCSynth::Subtractive::PresetType st);

/// @brief Convert osc mode to string (max 7 len)
const char* const OscModeToString(AugCSynth::WaveType osc);

/// @brief Convert filter mode to string (max 7 len)
const char* const FilterModeToString(AugCSynth::FilterMode filt);

/// @brief Convert numeric paramter to string(max 4 len) 
const char* const SubtractiveParamToString(AugCSynth::Subtractive::SubParameter param);
