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
	void OnOpen(GuiPageType openType) final;
	
	/// @brief Called when updating a frame
	void Update() final;

private:
	uint8_t mOscNum = 0;
	
	ElemId mOscNumLbl;

	ElemId mWaveTypeClb;
	ElemId mTuneClb;
	ElemId mVolClb;
	ElemId mWaveShapeClb;
};