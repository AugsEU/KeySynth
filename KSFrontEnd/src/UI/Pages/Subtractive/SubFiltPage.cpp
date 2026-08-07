// ============================================================================
// Include
// ============================================================================
#include "SubFiltPage.h"
#include "Usart/SynthParams.h"
#include "LocStrings.h"


// ============================================================================
// Class
// ============================================================================

SubFiltPage::SubFiltPage()
{
	using namespace AugCSynth::Subtractive;

	CreateLabel(20, 20, "Filter");

	mCutoffClb = CreateCounterLabel(20, 60, SubtractiveParamToString(SubParameter::VcfCutoff));
	mResonanceClb = CreateCounterLabel(20, 80, SubtractiveParamToString(SubParameter::VcfRes));
	mModeClb = CreateCounterLabel(20, 100, SubtractiveParamToString(SubParameter::VcfMode));
	mFollowClb = CreateCounterLabel(20, 120, SubtractiveParamToString(SubParameter::VcfFollow));

	// Setup nav
	LinkUpDown(mResonanceClb, mCutoffClb);
	LinkUpDown(mModeClb, mResonanceClb);
	LinkUpDown(mFollowClb, mModeClb);
	LinkUpDown(mCutoffClb, mFollowClb);
}

void SubFiltPage::OnOpen(GuiPageType openType)
{
	using namespace AugCSynth::Subtractive;

	SelectElem(mCutoffClb);

	LoadSubValueToLabel(mCutoffClb, SubParameter::VcfCutoff);
	LoadSubValueToLabel(mResonanceClb, SubParameter::VcfRes);
	LoadSubValueToLabel(mModeClb, SubParameter::VcfMode);
	LoadSubValueToLabel(mFollowClb, SubParameter::VcfFollow);
}

void SubFiltPage::Update()
{
	using namespace AugCSynth::Subtractive;

	GuiPage::Update();

	SEND_COUNTER_TO_SYNTH(mCutoffClb, SubParameter::VcfCutoff);
	SEND_COUNTER_TO_SYNTH(mResonanceClb, SubParameter::VcfRes);
	SEND_COUNTER_TO_SYNTH(mModeClb, SubParameter::VcfMode);
	SEND_COUNTER_TO_SYNTH(mFollowClb, SubParameter::VcfFollow);
}