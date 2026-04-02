// ============================================================================
// Include
// ============================================================================
#include "SynthParamBounds.h"
#include "Shared/Shared.h"
#include "Shared/SubParams.h"

#include <math.h>


// ============================================================================
// Functions
// ============================================================================
SynthParamBounds::SynthParamBounds(int8_t maxValue)
{
    mBound = maxValue;
}

int8_t SynthParamBounds::ApplyDelta(int8_t value, int8_t delta)
{
    value += delta;
    int8_t max = GetMaxValue();
    int8_t min = GetMinValue();
    if(value > max)
    {
        value = max;
    }
    else if(value < min)
    {
        value = min;
    }

	return value;
}

float SynthParamBounds::GetNormFloatValue(int8_t value)
{
    int8_t max = GetMaxValue();
    int8_t min = GetMinValue();
    if(min < 0 && value < 0)
    {
        return -(float)value / (float)min;
    }

    return (float)value / (float)max;
}

float SynthParamBounds::ScaleFloatForSubParam(uint8_t paramNum, float fv)
{
    switch (paramNum)
    {
    // General
    case ASP_DRIVE:
	case ASP_GAIN: // 0 to 1
        fv *= fv;
		break;
	case ASP_DELAY_TIME: // 0 to 1 
    case ASP_DELAY_FEEDBACK:
    case ASP_DELAY_SHEAR:
    case ASP_DELAY_MODE:
		break;

    // DCO
	case ASP_DCO_TUNE_1:
	case ASP_DCO_TUNE_2:
        fv = fv * fv * fv;
        fv = powf(4, fv);
		break;
	case ASP_DCO_VOL_1:
	case ASP_DCO_VOL_2:
        fv *= fv;
		break;
	case ASP_DCO_WS_1: // 0.0f to 1.0f
	case ASP_DCO_WS_2:
		break;

    // ENV
	case ASP_ENV_ATTACK1: // 1.0f / (SAMPLE_RATE * (8.01f - 8.0f * n));
    case ASP_ENV_DECAY1:
    case ASP_ENV_RELEASE1:
	case ASP_ENV_ATTACK2:
    case ASP_ENV_DECAY2:
    case ASP_ENV_RELEASE2:
    case ASP_LFO_ATTACK:
        fv *= fv;// Give weight to small values.
        fv = 1.0f - fv;
        fv = 1.0f / ((float)SAMPLE_RATE * (8.0 + 0.01 - 8.0 * fv));
		break;
	case ASP_ENV_SUSTAIN1: // 0 to 1 
    case ASP_ENV_SUSTAIN2:
		break;

    // VCF
	case ASP_VCF_CUTOFF: // x*x
        fv = fv * fv;
		break;
	case ASP_VCF_RES: // 0 to 1 weight high values
    case ASP_VCF_FOLLOW:
        fv = 1.0f - fv;
        fv *= fv * fv;
        fv = 1.0f - fv;
		break;

    // LFO
	case ASP_LFO_RATE: // (x*x*50+0.1)*SAMPLE_PERIOD 
        fv *= fv;
        fv *= 50.0f;
        fv += 0.1f;
        fv *= (1.0f / (float)SAMPLE_RATE);
		break;
	case ASP_LFO_WOBBLE: // -0.5f to 0.5f
    case ASP_LFO_OSC1_VOLUME:
    case ASP_LFO_OSC2_VOLUME:
    case ASP_LFO_OSC1_SHAPE:
    case ASP_LFO_OSC2_SHAPE:
    case ASP_LFO_VCF_CUTOFF:
    case ASP_LFO_VCF_RES:
        fv *= 0.5f;
		break;
    case ASP_LFO_OSC1_TUNE: // -1 to 1 weighted to small values
    case ASP_LFO_OSC2_TUNE:
        fv *= fabsf(fv);
        break;
    }

    return fv;
}

int8_t SynthParamBounds::GetMaxValue()
{
    if(mBound > 0)
    {
        return mBound;
    }

    return -mBound;
}

int8_t SynthParamBounds::GetMinValue()
{
    if(mBound < 0)
    {
        return mBound;
    }

    return 0;
}