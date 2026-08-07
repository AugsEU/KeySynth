// ============================================================================
// Include
// ============================================================================
#include "SynthParams.h"
#include "Usart/TxBackend.h"
#include "Usart/SynthPreset.h"

#include <Subtractive/SubParams.h>

#include <math.h>

// ============================================================================
// Globals
// ============================================================================
int8_t gSynthParamValues[AugCSynth::NUM_PARAMETERS];




// ============================================================================
// Pre decl
// ============================================================================
void TransmitSubtractiveParameter(uint8_t paramNum, int8_t value);




// ============================================================================
// Public functions
// ============================================================================

int8_t GetSynthParamValue(size_t paramNum)
{
    return gSynthParamValues[paramNum];
}

void ForceSendAllParams()
{
    for(size_t i = 0; i < AugCSynth::NUM_PARAMETERS; ++i)
    {
        TransmitSubtractiveParameter((uint8_t)i, gSynthParamValues[i]);
    }
}

void InitParamsForSubtractive()
{
    memset(gSynthParamValues, 0, sizeof(gSynthParamValues));
    LoadSubMemPreset(12);
}

void SendParamForSubtractive(size_t paramNum, int8_t value)
{
    int8_t prevValue = gSynthParamValues[paramNum];
    if(prevValue == value)
    {
        return;
    }

    gSynthParamValues[paramNum] = value;

    TransmitSubtractiveParameter(paramNum, value);
}

// ============================================================================
// Private functions
// ============================================================================

void TransmitSubtractiveParameter(uint8_t paramNum, int8_t value)
{
    auto param = (AugCSynth::Subtractive::SubParameter)paramNum;

    if(AugCSynth::Subtractive::SubParamIsInt(param))
    {
        TxBackendSetParam(paramNum, (int32_t)value);
    }
    else
    {
        AugCSynth::SynthParamBounds bounds = AugCSynth::Subtractive::GetSubParamBounds(param);

        float fvalue = bounds.GetNormFloatValue(value);
        fvalue = ScaleFloatForSubParam(param, fvalue);

        TxBackendSetParam(paramNum, fvalue);
    }
}