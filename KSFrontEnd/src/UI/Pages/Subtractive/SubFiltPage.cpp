// ============================================================================
// Include
// ============================================================================
#include "SubFiltPage.h"
#include "Shared/SubParams.h"
#include "Usart/SynthParams.h"
#include "LocStrings.h"


// ============================================================================
// Class
// ============================================================================

SubFiltPage::SubFiltPage()
{
	CreateLabel(20, 20, "Filter");

	mCutoffClb = CreateCounterLabel(20, 60, AugNumberParamToString(ASP_VCF_CUTOFF));
	mResonanceClb = CreateCounterLabel(20, 80, AugNumberParamToString(ASP_VCF_RES));
	mModeClb = CreateCounterLabel(20, 100, AugNumberParamToString(ASP_VCF_MODE));
	mFollowClb = CreateCounterLabel(20, 120, AugNumberParamToString(ASP_VCF_FOLLOW));

	// Setup nav
	LinkUpDown(mResonanceClb, mCutoffClb);
	LinkUpDown(mModeClb, mResonanceClb);
	LinkUpDown(mFollowClb, mModeClb);
	LinkUpDown(mCutoffClb, mFollowClb);
}

void SubFiltPage::OnOpen(GuiPageType openType)
{
	SelectElem(mCutoffClb);

	LoadSubValueToLabel(mCutoffClb, ASP_VCF_CUTOFF);
	LoadSubValueToLabel(mResonanceClb, ASP_VCF_RES);
	LoadSubValueToLabel(mModeClb, ASP_VCF_MODE);
	LoadSubValueToLabel(mFollowClb, ASP_VCF_FOLLOW);
}

void SubFiltPage::Update()
{
	GuiPage::Update();

	SEND_COUNTER_TO_SYNTH(mCutoffClb, ASP_VCF_CUTOFF);
	SEND_COUNTER_TO_SYNTH(mResonanceClb, ASP_VCF_RES);
	SEND_COUNTER_TO_SYNTH(mModeClb, ASP_VCF_MODE);
	SEND_COUNTER_TO_SYNTH(mFollowClb, ASP_VCF_FOLLOW);
}