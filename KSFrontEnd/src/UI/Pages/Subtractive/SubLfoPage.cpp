// ============================================================================
// Include
// ============================================================================
#include "SubLfoPage.h"
#include "Shared\SubParams.h"
#include "LocStrings.h"
#include "Usart/SynthParams.h"

// ============================================================================
// Class
// ============================================================================

SubLfoPage::SubLfoPage()
{
	mRateClb = 		CreateCounterLabel(20, 20, AugNumberParamToString(ASP_LFO_RATE));
	mWaveTypeClb = 	CreateCounterLabel(20, 40, AugNumberParamToString(ASP_LFO_WAVE_TYPE));
	mAttackClb = 	CreateCounterLabel(20, 60, AugNumberParamToString(ASP_LFO_ATTACK));
	mWobbleClb = 	CreateCounterLabel(20, 80, AugNumberParamToString(ASP_LFO_WOBBLE));
	mOsc1TuneClb = 	CreateCounterLabel(20, 100, AugNumberParamToString(ASP_LFO_OSC1_TUNE));
	mOsc1VolClb = 	CreateCounterLabel(20, 120, AugNumberParamToString(ASP_LFO_OSC1_VOLUME));
	mOsc1ShapeClb = CreateCounterLabel(20, 140, AugNumberParamToString(ASP_LFO_OSC1_SHAPE));
	mOsc2TuneClb = 	CreateCounterLabel(60, 20, AugNumberParamToString(ASP_LFO_OSC2_TUNE));
	mOsc2VolClb = 	CreateCounterLabel(60, 40, AugNumberParamToString(ASP_LFO_OSC2_VOLUME));
	mOsc2ShapeClb = CreateCounterLabel(60, 80, AugNumberParamToString(ASP_LFO_OSC2_SHAPE));
	mCutoffClb = 	CreateCounterLabel(60, 100, AugNumberParamToString(ASP_LFO_VCF_CUTOFF));
	mResonanceClb = CreateCounterLabel(60, 120, AugNumberParamToString(ASP_LFO_VCF_RES));

	// Setup nav
	LinkUpDown(mWaveTypeClb, mRateClb);
	LinkUpDown(mAttackClb, mWaveTypeClb);
	LinkUpDown(mWobbleClb, mAttackClb);
	LinkUpDown(mOsc1TuneClb, mWobbleClb);
	LinkUpDown(mOsc1VolClb, mOsc1TuneClb);
	LinkUpDown(mOsc1ShapeClb, mOsc1VolClb);
	LinkUpDown(mOsc2TuneClb, mOsc1ShapeClb);
	LinkUpDown(mOsc2VolClb, mOsc2TuneClb);
	LinkUpDown(mOsc2ShapeClb, mOsc2VolClb);
	LinkUpDown(mCutoffClb, mOsc2ShapeClb);
	LinkUpDown(mResonanceClb, mCutoffClb);
	LinkUpDown(mRateClb, mResonanceClb);
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