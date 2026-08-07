// ============================================================================
// Include
// ============================================================================
#include "SubGeneralPage.h"

#include "LocStrings.h"
#include "Usart/SynthParams.h"
#include "Usart/SynthPreset.h"

// ============================================================================
// SubGeneralPage
// ============================================================================

/// @brief Constructor
SubGeneralPage::SubGeneralPage()
{
	using namespace AugCSynth::Subtractive;

	CreateLabel(20, 20, "General");

	mTuningId = CreateCounterLabel(20, 60, SubtractiveParamToString(SubParameter::Tuning));
	mDriveId = CreateCounterLabel(20, 80, SubtractiveParamToString(SubParameter::Drive));
	mGainId = CreateCounterLabel(20, 100, SubtractiveParamToString(SubParameter::Gain));
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
	using namespace AugCSynth::Subtractive;

	SelectElem(mTuningId);

	LoadSubValueToLabel(mTuningId, SubParameter::Tuning);
	LoadSubValueToLabel(mDriveId, SubParameter::Drive);
	LoadSubValueToLabel(mGainId, SubParameter::Gain);

	auto* presetCounter = GetElement<GuiLabelCounter>(mPresetClb);
	presetCounter->mMaxValue = 18;
	presetCounter->mMinValue = 1;
}

/// @brief Called when updating a frame
void SubGeneralPage::Update()
{
	using namespace AugCSynth::Subtractive;

	GuiPage::Update();

	SEND_COUNTER_TO_SYNTH(mTuningId, SubParameter::Tuning);
	SEND_COUNTER_TO_SYNTH(mDriveId, SubParameter::Drive);
	SEND_COUNTER_TO_SYNTH(mGainId, SubParameter::Gain);

	auto* presetCounter = GetElement<GuiLabelCounter>(mPresetClb);

	if(presetCounter->ConsumeChange())
	{
		LoadSubMemPreset(presetCounter->mValue - 1);
	}
}