// ============================================================================
// Subtractive synth envelope oscillator 1+2 settings
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include "SubEditorPage.h"

// ============================================================================
// SubEnvPage
// ============================================================================
class SubEnvPage final : public SubEditorPage
{
public:
	/// @brief Constructor
	SubEnvPage();

	/// @brief Called once on opening
	void OnOpen() final;
	
	/// @brief Called when updating a frame
	void Update() final;

private:
	
};