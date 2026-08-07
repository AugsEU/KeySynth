// ============================================================================
// Include
// ============================================================================
#include "SubLfoPage.h"
#include "LocStrings.h"
#include "Usart/SynthParams.h"

// ============================================================================
// Class
// ============================================================================

SubLfoPage::SubLfoPage()
{
	using namespace AugCSynth::Subtractive;

	CreateLabel(20, 20, "LFO");

	mRateClb = 		CreateCounterLabel(20, 60, SubtractiveParamToString(SubParameter::LfoRate));
	mWaveTypeClb = 	CreateCounterLabel(20, 80, SubtractiveParamToString(SubParameter::LfoWaveType));
	mAttackClb = 	CreateCounterLabel(20, 100, SubtractiveParamToString(SubParameter::LfoAttack));
	mWobbleClb = 	CreateCounterLabel(20, 120, SubtractiveParamToString(SubParameter::LfoWobble));

	mCutoffClb = 	CreateCounterLabel(20, 160, SubtractiveParamToString(SubParameter::LfoVcfCutoff));
	mResonanceClb = CreateCounterLabel(20, 180, SubtractiveParamToString(SubParameter::LfoVcfRes));

	mOsc1TuneClb = 	CreateCounterLabel(160, 60, SubtractiveParamToString(SubParameter::LfoOsc1Tune));
	mOsc1VolClb = 	CreateCounterLabel(160, 80, SubtractiveParamToString(SubParameter::LfoOsc1Volume));
	mOsc1ShapeClb = CreateCounterLabel(160, 100, SubtractiveParamToString(SubParameter::LfoOsc1Shape));

	mOsc2TuneClb = 	CreateCounterLabel(160, 140, SubtractiveParamToString(SubParameter::LfoOsc2Tune));
	mOsc2VolClb = 	CreateCounterLabel(160, 160, SubtractiveParamToString(SubParameter::LfoOsc2Volume));
	mOsc2ShapeClb = CreateCounterLabel(160, 180, SubtractiveParamToString(SubParameter::LfoOsc2Shape));

	// Setup nav
	LinkUpDown(mWaveTypeClb, mRateClb);
	LinkUpDown(mAttackClb, mWaveTypeClb);
	LinkUpDown(mWobbleClb, mAttackClb);
	LinkUpDown(mCutoffClb, mWobbleClb);
	LinkUpDown(mResonanceClb, mCutoffClb);
	LinkUpDown(mOsc1TuneClb, mResonanceClb);
	LinkUpDown(mOsc1VolClb, mOsc1TuneClb);
	LinkUpDown(mOsc1ShapeClb, mOsc1VolClb);
	LinkUpDown(mOsc2TuneClb, mOsc1ShapeClb);
	LinkUpDown(mOsc2VolClb, mOsc2TuneClb);
	LinkUpDown(mOsc2ShapeClb, mOsc2VolClb);
	LinkUpDown(mRateClb, mOsc2ShapeClb);
	
	LinkLeftRight(mRateClb, mOsc1TuneClb);
	LinkLeftRight(mWaveTypeClb, mOsc1VolClb);
	LinkLeftRight(mAttackClb, mOsc1ShapeClb);
	LinkLeftRight(mWaveTypeClb, mOsc1VolClb);
	LinkLeftRight(mWobbleClb, mOsc2TuneClb);
	LinkLeftRight(mCutoffClb, mOsc2VolClb);
	LinkLeftRight(mResonanceClb, mOsc2ShapeClb);
}

void SubLfoPage::OnOpen(GuiPageType openType)
{
	using namespace AugCSynth::Subtractive;
	
	SelectElem(mRateClb);

	LoadSubValueToLabel(mRateClb, SubParameter::LfoRate);
	LoadSubValueToLabel(mWaveTypeClb, SubParameter::LfoWaveType);
	LoadSubValueToLabel(mAttackClb, SubParameter::LfoAttack);
	LoadSubValueToLabel(mWobbleClb, SubParameter::LfoWobble);
	LoadSubValueToLabel(mOsc1TuneClb, SubParameter::LfoOsc1Tune);
	LoadSubValueToLabel(mOsc1VolClb, SubParameter::LfoOsc1Volume);
	LoadSubValueToLabel(mOsc1ShapeClb, SubParameter::LfoOsc1Shape);
	LoadSubValueToLabel(mOsc2TuneClb, SubParameter::LfoOsc2Tune);
	LoadSubValueToLabel(mOsc2VolClb, SubParameter::LfoOsc2Volume);
	LoadSubValueToLabel(mOsc2ShapeClb, SubParameter::LfoOsc2Shape);
	LoadSubValueToLabel(mCutoffClb, SubParameter::LfoVcfCutoff);
	LoadSubValueToLabel(mResonanceClb, SubParameter::VcfRes);
}

void SubLfoPage::Update()
{
	using namespace AugCSynth::Subtractive;

	GuiPage::Update();

	SEND_COUNTER_TO_SYNTH(mRateClb, SubParameter::LfoRate);
	SEND_COUNTER_TO_SYNTH(mWaveTypeClb, SubParameter::LfoWaveType);
	SEND_COUNTER_TO_SYNTH(mAttackClb, SubParameter::LfoAttack);
	SEND_COUNTER_TO_SYNTH(mWobbleClb, SubParameter::LfoWobble);
	SEND_COUNTER_TO_SYNTH(mOsc1TuneClb, SubParameter::LfoOsc1Tune);
	SEND_COUNTER_TO_SYNTH(mOsc1VolClb, SubParameter::LfoOsc1Volume);
	SEND_COUNTER_TO_SYNTH(mOsc1ShapeClb, SubParameter::LfoOsc1Shape);
	SEND_COUNTER_TO_SYNTH(mOsc2TuneClb, SubParameter::LfoOsc2Tune);
	SEND_COUNTER_TO_SYNTH(mOsc2VolClb, SubParameter::LfoOsc2Volume);
	SEND_COUNTER_TO_SYNTH(mOsc2ShapeClb, SubParameter::LfoOsc2Shape);
	SEND_COUNTER_TO_SYNTH(mCutoffClb, SubParameter::LfoVcfCutoff);
	SEND_COUNTER_TO_SYNTH(mResonanceClb, SubParameter::VcfRes);
}