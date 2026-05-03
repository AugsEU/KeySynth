// ============================================================================
// Synths parameters to send over to backend synth
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include "Shared/SubParams.h"

// ============================================================================
// Constants
// ============================================================================
constexpr size_t NUM_FACTORY_PRESETS = 18;
constexpr uint8_t PRESET_NUM_CHARS = 8;
constexpr uintptr_t EEPROM_PRESET_OFFSET = 0;
constexpr uint8_t MAX_USER_PRESETS = 64;


// ============================================================================
// SubSynthPreset
// ============================================================================
struct SubSynthPreset
{
    char mName[PRESET_NUM_CHARS];
    int8_t mValues[ASP_NUM_PARAMS];
};

char* GetSubMemPresetName(size_t index);
void LoadSubMemPreset(size_t index);