#include <Arduino.h>

// ============================================================================
// Include
// ============================================================================
#include "LocStrings.h"

#include <Subtractive/SubParams.h>

using namespace AugCSynth;

/// @brief Convert tuning to string(max 7 len)
const char* const TuningToString(AugCSynth::Tuning tuning)
{
    switch (tuning)
    {
    case AugCSynth::Tuning::Equal12:
        return "12 TET";
    case AugCSynth::Tuning::JustC:
        return "C Just";
    case AugCSynth::Tuning::JustCs:
        return "C# Just";
    case AugCSynth::Tuning::JustD:
        return "D Just";
    case AugCSynth::Tuning::JustDs:
        return "D# Just";
    case AugCSynth::Tuning::JustE:
        return "E Just";
    case AugCSynth::Tuning::JustF:
        return "F Just";
    case AugCSynth::Tuning::JustFs:
        return "F# Just";
    case AugCSynth::Tuning::JustG:
        return "G Just";
    case AugCSynth::Tuning::JustGs:
        return "G# Just";
    case AugCSynth::Tuning::JustA:
        return "A Just";
    case AugCSynth::Tuning::JustAs:
        return "A# Just";
    case AugCSynth::Tuning::JustB:
        return "B Just";
    case AugCSynth::Tuning::Equal24:
        return "24 TET";
    case AugCSynth::Tuning::CircleOfFifths:
        return "5 Circ";
    case AugCSynth::Tuning::Wonky:
        return "Wonky";
    default:
        break;
    }

    return "ERROR";
}

/// @brief Convert delay mode to string 
const char* const DelayModeToString(AugCSynth::DelayMode delay)
{
    switch (delay)
    {
    case AugCSynth::DelayMode::Off:
        return "Off";
    case AugCSynth::DelayMode::Feedback :
        return "Normal";
    case AugCSynth::DelayMode::Slapback:
        return "Slapbck";
    case AugCSynth::DelayMode::Glitch:
        return "Glitch";
    default:
        break;
    }

    return "ERROR";
}

/// @brief Convert delay mode to string (max 7 len)
const char* const SoundTypeToString(Subtractive::PresetType st)
{
    switch (st)
    {
    case Subtractive::PresetType::Poly:
        return "Poly";
    case Subtractive::PresetType::Mono:
        return "Mono";
    case Subtractive::PresetType::Piano:
        return "Pluck";
    case Subtractive::PresetType::Bass:
        return "Bass";
    default:
        break;
    }

    return "ERROR";
}

/// @brief Convert osc mode to string 
const char* const OscModeToString(AugCSynth::WaveType osc)
{
    switch (osc)
    {
    case AugCSynth::WaveType::Sine:
        return "Sine";
    case AugCSynth::WaveType::Square:
        return "Square";
    case AugCSynth::WaveType::Saw:
        return "Saw";
    case AugCSynth::WaveType::Organ:
        return "Organ";
    default:
        break;
    }

    return "ERROR";
}

/// @brief Convert osc mode to string 
const char* const FilterModeToString(AugCSynth::FilterMode filt)
{
    switch (filt)
    {
    case AugCSynth::FilterMode::Off:
        return "Off";
    case AugCSynth::FilterMode::LowPass:
        return "Low";
    case AugCSynth::FilterMode::HighPass:
        return "High";
    default:
        break;
    }

    return "ERROR";
}

/// @brief Convert numeric paramter to string(max 4 len) 
const char* const SubtractiveParamToString(AugCSynth::Subtractive::SubParameter param)
{
    switch (param)
    {
    case Subtractive::SubParameter::Tuning:
        return "Tuning";
    case Subtractive::SubParameter::Drive:
        return "Drive";
    case Subtractive::SubParameter::Gain:
        return "Gain";
    case Subtractive::SubParameter::DelayTime:
        return "Time";
    case Subtractive::SubParameter::DelayFeedback:
        return "Feed";
    case Subtractive::SubParameter::DelayShear:
        return "Move";
    case Subtractive::SubParameter::DcoWs1:
    case Subtractive::SubParameter::DcoWs2:
    case Subtractive::SubParameter::LfoOsc1Shape:
    case Subtractive::SubParameter::LfoOsc2Shape:
        return "Shpe";
    case Subtractive::SubParameter::DcoVol1:
    case Subtractive::SubParameter::DcoVol2:
    case Subtractive::SubParameter::LfoOsc1Volume:
    case Subtractive::SubParameter::LfoOsc2Volume:
        return "Vol";
    case Subtractive::SubParameter::DcoTune1:
    case Subtractive::SubParameter::DcoTune2:
    case Subtractive::SubParameter::LfoOsc1Tune:
    case Subtractive::SubParameter::LfoOsc2Tune:
        return "Tune";
    case Subtractive::SubParameter::EnvAttack1:
    case Subtractive::SubParameter::EnvAttack2:
    case Subtractive::SubParameter::LfoAttack:
        return "Attk";
    case Subtractive::SubParameter::EnvDecay1:
    case Subtractive::SubParameter::EnvDecay2:
        return "Dcay";
    case Subtractive::SubParameter::EnvSustain1:
    case Subtractive::SubParameter::EnvSustain2:
        return "Sust";
    case Subtractive::SubParameter::EnvRelease1:
    case Subtractive::SubParameter::EnvRelease2:
        return "Rele";
    case Subtractive::SubParameter::VcfCutoff:
    case Subtractive::SubParameter::LfoVcfCutoff:
        return "Freq";
    case Subtractive::SubParameter::VcfRes:
    case Subtractive::SubParameter::LfoVcfRes:
        return "Res";
    case Subtractive::SubParameter::VcfFollow:
        return "Fllw";
    case Subtractive::SubParameter::LfoRate:
        return "Rate";
    case Subtractive::SubParameter::LfoWobble:
        return "Wobl";
    default:
        break;
    }

    return "ERR";
}