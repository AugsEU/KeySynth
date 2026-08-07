// ============================================================================
// Include
// ============================================================================
#include "SubOscPage.h"
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
	using namespace AugCSynth::Subtractive;

	mOscNum = 1;
	mOscNumLbl = CreateLabel(20, 20, OSCILLATOR_1_STRING);

	mWaveTypeClb = CreateCounterLabel(20, 60, SubtractiveParamToString(SubParameter::DcoWaveType1));
	mTuneClb = CreateCounterLabel(20, 80, SubtractiveParamToString(SubParameter::DcoTune1));
	mVolClb = CreateCounterLabel(20, 100, SubtractiveParamToString(SubParameter::DcoVol1));
	mWaveShapeClb = CreateCounterLabel(20, 120, SubtractiveParamToString(SubParameter::DcoWs1));

	// Setup nav
	LinkUpDown(mTuneClb, mWaveTypeClb);
	LinkUpDown(mVolClb, mTuneClb);
	LinkUpDown(mWaveShapeClb, mVolClb);
	LinkUpDown(mWaveTypeClb, mWaveShapeClb);
}

void SubOscPage::OnOpen(GuiPageType openType)
{
	using namespace AugCSynth::Subtractive;

	SelectElem(mWaveTypeClb);

	switch (openType)
	{
	case GuiPageType::SubOsc1:
		mOscNum = 1;
		GetElement<GuiLabel>(mOscNumLbl)->mString = OSCILLATOR_1_STRING;

		LoadSubValueToLabel(mWaveTypeClb, SubParameter::DcoWaveType1);
		LoadSubValueToLabel(mTuneClb, SubParameter::DcoTune1);
		LoadSubValueToLabel(mVolClb, SubParameter::DcoVol1);
		LoadSubValueToLabel(mWaveShapeClb, SubParameter::DcoWs1);
		break;
	case GuiPageType::SubOsc2:
		mOscNum = 2;
		GetElement<GuiLabel>(mOscNumLbl)->mString = OSCILLATOR_2_STRING;

		LoadSubValueToLabel(mWaveTypeClb, SubParameter::DcoWaveType2);
		LoadSubValueToLabel(mTuneClb, SubParameter::DcoTune2);
		LoadSubValueToLabel(mVolClb, SubParameter::DcoVol2);
		LoadSubValueToLabel(mWaveShapeClb, SubParameter::DcoWs2);
		break;
	default:
		break;
	}
}

void SubOscPage::Update()
{
	using namespace AugCSynth::Subtractive;

	GuiPage::Update();

	switch (mOscNum)
	{
	case 1:
		SEND_COUNTER_TO_SYNTH(mWaveTypeClb, SubParameter::DcoWaveType1);
		SEND_COUNTER_TO_SYNTH(mTuneClb, SubParameter::DcoTune1);
		SEND_COUNTER_TO_SYNTH(mVolClb, SubParameter::DcoVol1);
		SEND_COUNTER_TO_SYNTH(mWaveShapeClb, SubParameter::DcoWs1);
		break;
	case 2:
		SEND_COUNTER_TO_SYNTH(mWaveTypeClb, SubParameter::DcoWaveType2);
		SEND_COUNTER_TO_SYNTH(mTuneClb, SubParameter::DcoTune2);
		SEND_COUNTER_TO_SYNTH(mVolClb, SubParameter::DcoVol2);
		SEND_COUNTER_TO_SYNTH(mWaveShapeClb, SubParameter::DcoWs2);
		break;
	default:
		break;
	}
}
