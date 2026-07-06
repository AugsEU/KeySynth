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
// SubFiltPage
// ============================================================================
class SubFiltPage final : public SubEditorPage
{
public:
	/// @brief Constructor
	SubFiltPage();

	/// @brief Called once on opening
	void OnOpen(GuiPageType openType) final;
	
	/// @brief Called when updating a frame
	void Update() final;

private:
	ElemId mCutoffClb;
	ElemId mResonanceClb;
	ElemId mModeClb;
	ElemId mFollowClb;
};