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
	void OnOpen(GuiPageType openType) final;
	
	/// @brief Called when updating a frame
	void Update() final;

private:
	uint8_t mOscNum = 0;
	
	ElemId mEnvNumLbl;

	ElemId mAttackClb;
	ElemId mDecayClb;
	ElemId mSustainClb;
	ElemId mReleaseClb;
};