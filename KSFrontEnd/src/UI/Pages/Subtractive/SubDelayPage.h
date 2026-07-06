// ============================================================================
// Subtractive synth delay effect settings
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include "SubEditorPage.h"

// ============================================================================
// SubDelayPage
// ============================================================================
class SubDelayPage final : public SubEditorPage
{
public:
	/// @brief Constructor
	SubDelayPage();

	/// @brief Called once on opening
	void OnOpen(GuiPageType openType) final;
	
	/// @brief Called when updating a frame
	void Update() final;

private:
	ElemId mTimeClb;
	ElemId mFeedbackClb;
	ElemId mShearClb;
	ElemId mModeClb;
};