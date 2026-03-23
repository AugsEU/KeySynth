#include <Arduino.h>
#include <Shared/SubParams.h>


/// @brief Convert tuning to string(max 7 len)
const char* const TuningToString(uint8_t tuning)
{
    switch (tuning)
    {
    case TUNING_12TET:
        return "12 TET";
    case TUNING_Cn_JI:
        return "C Just";
    case TUNING_Cs_JI:
        return "C# Just";
    case TUNING_Dn_JI:
        return "D Just";
    case TUNING_Ds_JI:
        return "D# Just";
    case TUNING_En_JI:
        return "E Just";
    case TUNING_Fn_JI:
        return "F Just";
    case TUNING_Fs_JI:
        return "F# Just";
    case TUNING_Gn_JI:
        return "G Just";
    case TUNING_Gs_JI:
        return "G# Just";
    case TUNING_An_JI:
        return "A Just";
    case TUNING_As_JI:
        return "A# Just";
    case TUNING_Bn_JI:
        return "B Just";
    case TUNING_24TET:
        return "24 TET";
    case CIRCLE_OF_5 :
        return "5 Circ";
    case WONKY:
        return "Wonky";
    default:
        break;
    }

    return "ERROR";
}

/// @brief Convert delay mode to string 
const char* const DelayModeToString(uint8_t delay)
{
    switch (delay)
    {
    case DELAY_MODE_OFF:
        return "Off";
    case DELAY_MODE_NORMAL:
        return "Normal";
    case DELAY_MODE_SLAPBACK:
        return "Slapbck";
    case DELAY_MODE_GLITCH:
        return "Glitch";
    default:
        break;
    }

    return "ERROR";
}

/// @brief Convert delay mode to string (max 7 len)
const char* const SoundTypeToString(uint8_t st)
{
    switch (st)
    {
    case SOUND_TYPE_POLY:
        return "Poly";
    case SOUND_TYPE_MONO:
        return "Mono";
    case SOUND_TYPE_PIANO:
        return "Pluck";
    case SOUND_TYPE_BASS:
        return "Bass";
    default:
        break;
    }

    return "ERROR";
}

/// @brief Convert osc mode to string 
const char* const OscModeToString(uint8_t osc)
{
    switch (osc)
    {
    case OSC_MODE_SINE:
        return "Sine";
    case OSC_MODE_SQUARE:
        return "Square";
    case OSC_MODE_SAW:
        return "Saw";
    case OSC_MODE_ORGAN:
        return "Organ";
    default:
        break;
    }

    return "ERROR";
}

/// @brief Convert osc mode to string 
const char* const FilterModeToString(uint8_t filt)
{
    switch (filt)
    {
    case FILTER_MODE_OFF:
        return "Off";
    case FILTER_MODE_LP:
        return "Low";
    case FILTER_MODE_HP:
        return "High";
    default:
        break;
    }

    return "ERROR";
}

/// @brief Convert numeric paramter to string(max 4 len) 
const char* const AugNumberParamToString(uint8_t param)
{
    switch (param)
    {
    case ASP_DRIVE:
        return "Drve";
    case ASP_GAIN:
        return "Gain";
    case ASP_DELAY_TIME:
        return "Time";
    case ASP_DELAY_FEEDBACK:
        return "Feed";
    case ASP_DELAY_SHEAR:
        return "Move";
    case ASP_DCO_WS_1:
    case ASP_DCO_WS_2:
    case ASP_LFO_OSC1_SHAPE:
    case ASP_LFO_OSC2_SHAPE:
        return "Shpe";
    case ASP_DCO_VOL_1:
    case ASP_DCO_VOL_2:
    case ASP_LFO_OSC1_VOLUME:
    case ASP_LFO_OSC2_VOLUME:
        return "Vol";
    case ASP_DCO_TUNE_1:
    case ASP_DCO_TUNE_2:
    case ASP_LFO_OSC1_TUNE:
    case ASP_LFO_OSC2_TUNE:
        return "Tune";
    case ASP_ENV_ATTACK1:
    case ASP_ENV_ATTACK2:
    case ASP_LFO_ATTACK:
        return "Attk";
    case ASP_ENV_DECAY1:
    case ASP_ENV_DECAY2:
        return "Dcay";
    case ASP_ENV_SUSTAIN1:
    case ASP_ENV_SUSTAIN2:
        return "Sust";
    case ASP_ENV_RELEASE1:
    case ASP_ENV_RELEASE2:
        return "Rele";
    case ASP_VCF_CUTOFF:
    case ASP_LFO_VCF_CUTOFF:
        return "Freq";
    case ASP_VCF_RES:
    case ASP_LFO_VCF_RES:
        return "Res";
    case ASP_VCF_FOLLOW:
        return "Fllw";
    case ASP_LFO_RATE:
        return "Rate";
    case ASP_LFO_WOBBLE:
        return "Wobl";
    default:
        break;
    }

    return "ERR";
}