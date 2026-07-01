// ============================================================================
// Page navigation system
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================


// ============================================================================
// Public functions
// ============================================================================

/// @brief Init page nav state
void InitialisePageNavigation();

/// @brief Handle page navigation
/// @param keycode Key pressed
/// @return True if input was used for page navigation
bool NavigatePage(uint8_t keycode);