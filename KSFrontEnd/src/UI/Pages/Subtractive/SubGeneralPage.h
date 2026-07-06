// ============================================================================
// Subtractive synth general settings page + presets
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include "SubEditorPage.h"

// ============================================================================
// SubGeneralPage
// ============================================================================
class SubGeneralPage final : public SubEditorPage
{
public:
	/// @brief Constructor
	SubGeneralPage();

	/// @brief Called once on opening
	void OnOpen(GuiPageType openType) final;
	
	/// @brief Called when updating a frame
	void Update() final;

private:
	ElemId mTuningId = EMPTY_ID;
	ElemId mDriveId = EMPTY_ID;
	ElemId mGainId = EMPTY_ID;
};