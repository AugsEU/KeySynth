// ============================================================================
// Include
// ============================================================================
#include "SubEnvPage.h"
#include "Shared/SubParams.h"
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
	mOscNum = 1;
	mEnvNumLbl = CreateLabel(20, 20, ENVELOPE_1_STRING);

	mAttackClb = CreateCounterLabel(20, 60, AugNumberParamToString(ASP_ENV_ATTACK1));
	mDecayClb = CreateCounterLabel(20, 80, AugNumberParamToString(ASP_ENV_DECAY1));
	mSustainClb = CreateCounterLabel(20, 100, AugNumberParamToString(ASP_ENV_SUSTAIN1));
	mReleaseClb = CreateCounterLabel(20, 120, AugNumberParamToString(ASP_ENV_RELEASE1));

	// Setup nav
	LinkUpDown(mDecayClb, mAttackClb);
	LinkUpDown(mSustainClb, mDecayClb);
	LinkUpDown(mReleaseClb, mSustainClb);
	LinkUpDown(mAttackClb, mReleaseClb);
}

void SubEnvPage::OnOpen(GuiPageType openType)
{
	SelectElem(mAttackClb);

	switch (openType)
	{
	case GuiPageType::SubEnv1:
		mOscNum = 1;
		GetElement<GuiLabel>(mEnvNumLbl)->mString = ENVELOPE_1_STRING;

		LoadSubValueToLabel(mAttackClb, ASP_ENV_ATTACK1);
		LoadSubValueToLabel(mDecayClb, ASP_ENV_DECAY1);
		LoadSubValueToLabel(mSustainClb, ASP_ENV_SUSTAIN1);
		LoadSubValueToLabel(mReleaseClb, ASP_ENV_RELEASE1);
		break;
	case GuiPageType::SubEnv2:
		mOscNum = 2;
		GetElement<GuiLabel>(mEnvNumLbl)->mString = ENVELOPE_2_STRING;

		LoadSubValueToLabel(mAttackClb, ASP_ENV_ATTACK2);
		LoadSubValueToLabel(mDecayClb, ASP_ENV_DECAY2);
		LoadSubValueToLabel(mSustainClb, ASP_ENV_SUSTAIN2);
		LoadSubValueToLabel(mReleaseClb, ASP_ENV_RELEASE2);
		break;
	default:
		break;
	}
}

void SubEnvPage::Update()
{
	GuiPage::Update();

	switch (mOscNum)
	{
	case 1:
		SEND_COUNTER_TO_SYNTH(mAttackClb, ASP_ENV_ATTACK1);
		SEND_COUNTER_TO_SYNTH(mDecayClb, ASP_ENV_DECAY1);
		SEND_COUNTER_TO_SYNTH(mSustainClb, ASP_ENV_SUSTAIN1);
		SEND_COUNTER_TO_SYNTH(mReleaseClb, ASP_ENV_RELEASE1);
		break;
	case 2:
		SEND_COUNTER_TO_SYNTH(mAttackClb, ASP_ENV_ATTACK2);
		SEND_COUNTER_TO_SYNTH(mDecayClb, ASP_ENV_DECAY2);
		SEND_COUNTER_TO_SYNTH(mSustainClb, ASP_ENV_SUSTAIN2);
		SEND_COUNTER_TO_SYNTH(mReleaseClb, ASP_ENV_RELEASE2);
		break;
	default:
		break;
	}
}