// ============================================================================
// Include
// ============================================================================
#include "SubDelayPage.h"
#include "LocStrings.h"
#include "Usart/SynthParams.h"

// ============================================================================
// Class
// ============================================================================

SubDelayPage::SubDelayPage()
{
	using namespace AugCSynth::Subtractive;

	CreateLabel(20, 20, "Delay");

	mTimeClb = CreateCounterLabel(20, 60, SubtractiveParamToString(SubParameter::DelayTime));
	mFeedbackClb = CreateCounterLabel(20, 80, SubtractiveParamToString(SubParameter::DelayFeedback));
	mShearClb = CreateCounterLabel(20, 100, SubtractiveParamToString(SubParameter::DelayShear));
	mModeClb = CreateCounterLabel(20, 120, SubtractiveParamToString(SubParameter::DelayMode));

	// Setup nav
	LinkUpDown(mFeedbackClb, mTimeClb);
	LinkUpDown(mShearClb, mFeedbackClb);
	LinkUpDown(mModeClb, mShearClb);
	LinkUpDown(mTimeClb, mModeClb);
}

void SubDelayPage::OnOpen(GuiPageType openType)
{
	using namespace AugCSynth::Subtractive;

	SelectElem(mTimeClb);

	LoadSubValueToLabel(mTimeClb, SubParameter::DelayTime);
	LoadSubValueToLabel(mFeedbackClb, SubParameter::DelayFeedback);
	LoadSubValueToLabel(mShearClb, SubParameter::DelayShear);
	LoadSubValueToLabel(mModeClb, SubParameter::DelayMode);
}

void SubDelayPage::Update()
{
	using namespace AugCSynth::Subtractive;

	GuiPage::Update();

	SEND_COUNTER_TO_SYNTH(mTimeClb, SubParameter::DelayTime);
	SEND_COUNTER_TO_SYNTH(mFeedbackClb, SubParameter::DelayFeedback);
	SEND_COUNTER_TO_SYNTH(mShearClb, SubParameter::DelayShear);
	SEND_COUNTER_TO_SYNTH(mModeClb, SubParameter::DelayMode);
}