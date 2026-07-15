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
	CreateLabel(20, 20, "LFO");

	mRateClb = 		CreateCounterLabel(20, 60, AugNumberParamToString(ASP_LFO_RATE));
	mWaveTypeClb = 	CreateCounterLabel(20, 80, AugNumberParamToString(ASP_LFO_WAVE_TYPE));
	mAttackClb = 	CreateCounterLabel(20, 100, AugNumberParamToString(ASP_LFO_ATTACK));
	mWobbleClb = 	CreateCounterLabel(20, 120, AugNumberParamToString(ASP_LFO_WOBBLE));

	mCutoffClb = 	CreateCounterLabel(20, 160, AugNumberParamToString(ASP_LFO_VCF_CUTOFF));
	mResonanceClb = CreateCounterLabel(20, 180, AugNumberParamToString(ASP_LFO_VCF_RES));

	mOsc1TuneClb = 	CreateCounterLabel(160, 60, AugNumberParamToString(ASP_LFO_OSC1_TUNE));
	mOsc1VolClb = 	CreateCounterLabel(160, 80, AugNumberParamToString(ASP_LFO_OSC1_VOLUME));
	mOsc1ShapeClb = CreateCounterLabel(160, 100, AugNumberParamToString(ASP_LFO_OSC1_SHAPE));

	mOsc2TuneClb = 	CreateCounterLabel(160, 140, AugNumberParamToString(ASP_LFO_OSC2_TUNE));
	mOsc2VolClb = 	CreateCounterLabel(160, 160, AugNumberParamToString(ASP_LFO_OSC2_VOLUME));
	mOsc2ShapeClb = CreateCounterLabel(160, 180, AugNumberParamToString(ASP_LFO_OSC2_SHAPE));

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
	SelectElem(mRateClb);

	LoadSubValueToLabel(mRateClb, ASP_LFO_RATE);
	LoadSubValueToLabel(mWaveTypeClb, ASP_LFO_WAVE_TYPE);
	LoadSubValueToLabel(mAttackClb, ASP_LFO_ATTACK);
	LoadSubValueToLabel(mWobbleClb, ASP_LFO_WOBBLE);
	LoadSubValueToLabel(mOsc1TuneClb, ASP_LFO_OSC1_TUNE);
	LoadSubValueToLabel(mOsc1VolClb, ASP_LFO_OSC1_VOLUME);
	LoadSubValueToLabel(mOsc1ShapeClb, ASP_LFO_OSC1_SHAPE);
	LoadSubValueToLabel(mOsc2TuneClb, ASP_LFO_OSC2_TUNE);
	LoadSubValueToLabel(mOsc2VolClb, ASP_LFO_OSC2_VOLUME);
	LoadSubValueToLabel(mOsc2ShapeClb, ASP_LFO_OSC2_SHAPE);
	LoadSubValueToLabel(mCutoffClb, ASP_LFO_VCF_CUTOFF);
	LoadSubValueToLabel(mResonanceClb, ASP_LFO_VCF_RES);
}

void SubLfoPage::Update()
{
	GuiPage::Update();

	SEND_COUNTER_TO_SYNTH(mRateClb, ASP_LFO_RATE);
	SEND_COUNTER_TO_SYNTH(mWaveTypeClb, ASP_LFO_WAVE_TYPE);
	SEND_COUNTER_TO_SYNTH(mAttackClb, ASP_LFO_ATTACK);
	SEND_COUNTER_TO_SYNTH(mWobbleClb, ASP_LFO_WOBBLE);
	SEND_COUNTER_TO_SYNTH(mOsc1TuneClb, ASP_LFO_OSC1_TUNE);
	SEND_COUNTER_TO_SYNTH(mOsc1VolClb, ASP_LFO_OSC1_VOLUME);
	SEND_COUNTER_TO_SYNTH(mOsc1ShapeClb, ASP_LFO_OSC1_SHAPE);
	SEND_COUNTER_TO_SYNTH(mOsc2TuneClb, ASP_LFO_OSC2_TUNE);
	SEND_COUNTER_TO_SYNTH(mOsc2VolClb, ASP_LFO_OSC2_VOLUME);
	SEND_COUNTER_TO_SYNTH(mOsc2ShapeClb, ASP_LFO_OSC2_SHAPE);
	SEND_COUNTER_TO_SYNTH(mCutoffClb, ASP_LFO_VCF_CUTOFF);
	SEND_COUNTER_TO_SYNTH(mResonanceClb, ASP_LFO_VCF_RES);
}