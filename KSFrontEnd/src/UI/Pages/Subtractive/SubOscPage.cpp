// ============================================================================
// Include
// ============================================================================
#include "SubOscPage.h"
#include "Shared/SubParams.h"
#include "LocStrings.h"

// ============================================================================
// Constants
// ============================================================================
constexpr const char* const OSCILLATOR_1_STRING = "Oscillator 1";
constexpr const char* const OSCILLATOR_2_STRING = "Oscillator 2";

// ============================================================================
// Class
// ============================================================================

SubOscPage::SubOscPage()
{
	mOscNum = 1;
	mOscNumLbl = CreateLabel(20, 20, OSCILLATOR_1_STRING);

	mWaveTypeClb = CreateCounterLabel(20, 60, AugNumberParamToString(ASP_DCO_WAVE_TYPE_1));
	mTuneClb = CreateCounterLabel(20, 80, AugNumberParamToString(ASP_DCO_TUNE_1));
	mVolClb = CreateCounterLabel(20, 100, AugNumberParamToString(ASP_DCO_VOL_1));
	mWaveShapeClb = CreateCounterLabel(20, 120, AugNumberParamToString(ASP_DCO_WS_1));

	// Setup nav
	LinkUpDown(mTuneClb, mWaveTypeClb);
	LinkUpDown(mVolClb, mTuneClb);
	LinkUpDown(mWaveShapeClb, mVolClb);
	LinkUpDown(mWaveTypeClb, mWaveShapeClb);
}

void SubOscPage::OnOpen(GuiPageType openType)
{
	SelectElem(mWaveTypeClb);

	switch (openType)
	{
	case GuiPageType::SubOsc1:
		mOscNum = 1;
		GetElement<GuiLabel>(mOscNumLbl)->mString = OSCILLATOR_1_STRING;

		LoadSubValueToLabel(mWaveTypeClb, ASP_DCO_WAVE_TYPE_1);
		LoadSubValueToLabel(mTuneClb, ASP_DCO_TUNE_1);
		LoadSubValueToLabel(mVolClb, ASP_DCO_VOL_1);
		LoadSubValueToLabel(mWaveShapeClb, ASP_DCO_WS_1);
		break;
	case GuiPageType::SubOsc2:
		mOscNum = 2;
		GetElement<GuiLabel>(mOscNumLbl)->mString = OSCILLATOR_2_STRING;

		LoadSubValueToLabel(mWaveTypeClb, ASP_DCO_WAVE_TYPE_2);
		LoadSubValueToLabel(mTuneClb, ASP_DCO_TUNE_2);
		LoadSubValueToLabel(mVolClb, ASP_DCO_VOL_2);
		LoadSubValueToLabel(mWaveShapeClb, ASP_DCO_WS_2);
		break;
	default:
		break;
	}
}

void SubOscPage::Update()
{
	GuiPage::Update();

	switch (mOscNum)
	{
	case 1:
		SEND_COUNTER_TO_SYNTH(mWaveTypeClb, ASP_DCO_WAVE_TYPE_1);
		SEND_COUNTER_TO_SYNTH(mTuneClb, ASP_DCO_TUNE_1);
		SEND_COUNTER_TO_SYNTH(mVolClb, ASP_DCO_VOL_1);
		SEND_COUNTER_TO_SYNTH(mWaveShapeClb, ASP_DCO_WS_1);
		break;
	case 2:
		SEND_COUNTER_TO_SYNTH(mWaveTypeClb, ASP_DCO_WAVE_TYPE_2);
		SEND_COUNTER_TO_SYNTH(mTuneClb, ASP_DCO_TUNE_2);
		SEND_COUNTER_TO_SYNTH(mVolClb, ASP_DCO_VOL_2);
		SEND_COUNTER_TO_SYNTH(mWaveShapeClb, ASP_DCO_WS_2);
		break;
	default:
		break;
	}
}
