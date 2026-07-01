// ============================================================================
// Subtractive synth oscillator 1+2 settings
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include "SubEditorPage.h"

// ============================================================================
// SubOscPage
// ============================================================================
class SubOscPage final : public SubEditorPage
{
public:
	/// @brief Constructor
	SubOscPage();

	/// @brief Called once on opening
	void OnOpen() final;
	
	/// @brief Called when updating a frame
	void Update() final;

private:
	
};