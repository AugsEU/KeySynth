// ============================================================================
// Include
// ============================================================================
#include "SubEnvPage.h"
#include "LocStrings.h"




// ============================================================================
// Constants
// ============================================================================
constexpr const char* const ENVELOPE_1_STRING = "Envelope 1";
constexpr const char* const ENVELOPE_2_STRING = "Envelope 2";




// ============================================================================
// Class
// ============================================================================

SubEnvPage::SubEnvPage()
{
	using namespace AugCSynth::Subtractive;

	mOscNum = 1;
	mEnvNumLbl = CreateLabel(20, 20, ENVELOPE_1_STRING);

	mAttackClb = CreateCounterLabel(20, 60, SubtractiveParamToString(SubParameter::EnvAttack1));
	mDecayClb = CreateCounterLabel(20, 80, SubtractiveParamToString(SubParameter::EnvDecay1));
	mSustainClb = CreateCounterLabel(20, 100, SubtractiveParamToString(SubParameter::EnvSustain1));
	mReleaseClb = CreateCounterLabel(20, 120, SubtractiveParamToString(SubParameter::EnvRelease1));

	// Setup nav
	LinkUpDown(mDecayClb, mAttackClb);
	LinkUpDown(mSustainClb, mDecayClb);
	LinkUpDown(mReleaseClb, mSustainClb);
	LinkUpDown(mAttackClb, mReleaseClb);
}

void SubEnvPage::OnOpen(GuiPageType openType)
{
	using namespace AugCSynth::Subtractive;

	SelectElem(mAttackClb);

	switch (openType)
	{
	case GuiPageType::SubEnv1:
		mOscNum = 1;
		GetElement<GuiLabel>(mEnvNumLbl)->mString = ENVELOPE_1_STRING;

		LoadSubValueToLabel(mAttackClb, SubParameter::EnvAttack1);
		LoadSubValueToLabel(mDecayClb, SubParameter::EnvDecay1);
		LoadSubValueToLabel(mSustainClb, SubParameter::EnvSustain1);
		LoadSubValueToLabel(mReleaseClb, SubParameter::EnvRelease1);
		break;
	case GuiPageType::SubEnv2:
		mOscNum = 2;
		GetElement<GuiLabel>(mEnvNumLbl)->mString = ENVELOPE_2_STRING;

		LoadSubValueToLabel(mAttackClb, SubParameter::EnvAttack2);
		LoadSubValueToLabel(mDecayClb, SubParameter::EnvDecay2);
		LoadSubValueToLabel(mSustainClb, SubParameter::EnvSustain2);
		LoadSubValueToLabel(mReleaseClb, SubParameter::EnvRelease2);
		break;
	default:
		break;
	}
}

void SubEnvPage::Update()
{
	using namespace AugCSynth::Subtractive;

	GuiPage::Update();

	switch (mOscNum)
	{
	case 1:
		SEND_COUNTER_TO_SYNTH(mAttackClb, SubParameter::EnvAttack1);
		SEND_COUNTER_TO_SYNTH(mDecayClb, SubParameter::EnvDecay1);
		SEND_COUNTER_TO_SYNTH(mSustainClb, SubParameter::EnvSustain1);
		SEND_COUNTER_TO_SYNTH(mReleaseClb, SubParameter::EnvRelease1);
		break;
	case 2:
		SEND_COUNTER_TO_SYNTH(mAttackClb, SubParameter::EnvAttack2);
		SEND_COUNTER_TO_SYNTH(mDecayClb, SubParameter::EnvDecay2);
		SEND_COUNTER_TO_SYNTH(mSustainClb, SubParameter::EnvSustain2);
		SEND_COUNTER_TO_SYNTH(mReleaseClb, SubParameter::EnvRelease2);
		break;
	default:
		break;
	}
}