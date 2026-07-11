// ============================================================================
// Include
// ============================================================================
#include "SubDelayPage.h"
#include "Shared\SubParams.h"
#include "LocStrings.h"
#include "Usart/SynthParams.h"

// ============================================================================
// Class
// ============================================================================

SubDelayPage::SubDelayPage()
{
	CreateLabel(20, 20, "Delay");

	mTimeClb = CreateCounterLabel(20, 60, AugNumberParamToString(ASP_DELAY_TIME));
	mFeedbackClb = CreateCounterLabel(20, 80, AugNumberParamToString(ASP_DELAY_FEEDBACK));
	mShearClb = CreateCounterLabel(20, 100, AugNumberParamToString(ASP_DELAY_SHEAR));
	mModeClb = CreateCounterLabel(20, 120, AugNumberParamToString(ASP_DELAY_MODE));

	// Setup nav
	LinkUpDown(mFeedbackClb, mTimeClb);
	LinkUpDown(mShearClb, mFeedbackClb);
	LinkUpDown(mModeClb, mShearClb);
	LinkUpDown(mTimeClb, mModeClb);
}

void SubDelayPage::OnOpen(GuiPageType openType)
{
	SelectElem(mTimeClb);

	LoadSubValueToLabel(mTimeClb, ASP_DELAY_TIME);
	LoadSubValueToLabel(mFeedbackClb, ASP_DELAY_FEEDBACK);
	LoadSubValueToLabel(mShearClb, ASP_DELAY_SHEAR);
	LoadSubValueToLabel(mModeClb, ASP_DELAY_MODE);
}

void SubDelayPage::Update()
{
	GuiPage::Update();

	SEND_COUNTER_TO_SYNTH(mTimeClb, ASP_DELAY_TIME);
	SEND_COUNTER_TO_SYNTH(mFeedbackClb, ASP_DELAY_FEEDBACK);
	SEND_COUNTER_TO_SYNTH(mShearClb, ASP_DELAY_SHEAR);
	SEND_COUNTER_TO_SYNTH(mModeClb, ASP_DELAY_MODE);
}