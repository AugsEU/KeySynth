// ============================================================================
// Subtractive synth LFO settings
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include "SubEditorPage.h"

// ============================================================================
// SubLfoPage
// ============================================================================
class SubLfoPage final : public SubEditorPage
{
public:
	/// @brief Constructor
	SubLfoPage();

	/// @brief Called once on opening
	void OnOpen() final;
	
	/// @brief Called when updating a frame
	void Update() final;

private:
	
};