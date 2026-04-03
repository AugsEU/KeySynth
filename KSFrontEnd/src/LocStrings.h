// ============================================================================
// String in language displayable to user.
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>


// ============================================================================
// Public functions
// ============================================================================
/// @brief Convert tuning to string(max 7 len)
const char* const TuningToString(uint8_t tuning);

/// @brief Convert delay mode to string (max 7 len)
const char* const DelayModeToString(uint8_t delay);

/// @brief Convert delay mode to string (max 7 len)
const char* const SoundTypeToString(uint8_t st);

/// @brief Convert osc mode to string (max 7 len)
const char* const OscModeToString(uint8_t osc);

/// @brief Convert filter mode to string (max 7 len)
const char* const FilterModeToString(uint8_t filt);

/// @brief Convert numeric paramter to string(max 4 len) 
const char* const AugNumberParamToString(uint8_t param);
