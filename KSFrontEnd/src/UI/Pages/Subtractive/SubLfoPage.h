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
	void OnOpen(GuiPageType openType) final;
	
	/// @brief Called when updating a frame
	void Update() final;

private:
	ElemId mRateClb;
	ElemId mWaveTypeClb;
	ElemId mAttackClb;
	ElemId mWobbleClb;
	ElemId mOsc1TuneClb;
	ElemId mOsc1VolClb;
	ElemId mOsc1ShapeClb;
	ElemId mOsc2TuneClb;
	ElemId mOsc2VolClb;
	ElemId mOsc2ShapeClb;
	ElemId mCutoffClb;
	ElemId mResonanceClb;
};