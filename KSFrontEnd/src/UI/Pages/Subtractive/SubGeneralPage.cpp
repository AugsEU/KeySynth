// ============================================================================
// Include
// ============================================================================
#include "SubGeneralPage.h"

#include "Shared\SubParams.h"
#include "LocStrings.h"
#include "Usart/SynthParams.h"
#include "Usart/SynthPreset.h"

// ============================================================================
// SubGeneralPage
// ============================================================================

/// @brief Constructor
SubGeneralPage::SubGeneralPage()
{
	CreateLabel(20, 20, "General");

	mTuningId = CreateCounterLabel(20, 60, AugNumberParamToString(ASP_TUNING));
	mDriveId = CreateCounterLabel(20, 80, AugNumberParamToString(ASP_DRIVE));
	mGainId = CreateCounterLabel(20, 100, AugNumberParamToString(ASP_GAIN));
	mPresetClb = CreateCounterLabel(20, 140, "Preset");

	// Setup nav
	LinkUpDown(mGainId, mDriveId);
	LinkUpDown(mDriveId, mTuningId);
	LinkUpDown(mTuningId, mPresetClb);
	LinkUpDown(mPresetClb, mGainId);
}

/// @brief Called once on opening
void SubGeneralPage::OnOpen(GuiPageType openType)
{
	SelectElem(mTuningId);

	LoadSubValueToLabel(mTuningId, ASP_TUNING);
	LoadSubValueToLabel(mDriveId, ASP_DRIVE);
	LoadSubValueToLabel(mGainId, ASP_GAIN);

	auto* presetCounter = GetElement<GuiLabelCounter>(mPresetClb);
	presetCounter->mMaxValue = 18;
	presetCounter->mMinValue = 1;
}

/// @brief Called when updating a frame
void SubGeneralPage::Update()
{
	GuiPage::Update();

	SEND_COUNTER_TO_SYNTH(mTuningId, ASP_TUNING);
	SEND_COUNTER_TO_SYNTH(mDriveId, ASP_DRIVE);
	SEND_COUNTER_TO_SYNTH(mGainId, ASP_GAIN);

	auto* presetCounter = GetElement<GuiLabelCounter>(mPresetClb);

	if(presetCounter->ConsumeChange())
	{
		LoadSubMemPreset(presetCounter->mValue - 1);
	}
}