// ============================================================================
// Voice for subtractive synth
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Includes
// ============================================================================
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "Oscillator.h"
#include "Envelope.h"



namespace Subtractive
{

// ============================================================================
// Public types
// ============================================================================
struct SubVoice
{
    float_t mFreq; // Note: Oscillator frequency may vary from this.
    uint8_t mPlayingNoteIdx;

    Oscillator mOsc1;
    Envelope mEnv1;

    Oscillator mOsc2;
    Envelope mEnv2;

    float_t mLfoDelta;
    float_t mLfoAmount;
};


// ============================================================================
// Public functions
// ============================================================================

void VoiceInit(SubVoice* pVoice);

void VoiceOn(SubVoice* pVoice, uint8_t playingNoteIdx);
void VoiceOnSteal(SubVoice* pVoice, uint8_t playingNoteIdx);
void VoiceOff(SubVoice* pVoice);

void VoicePrepSampleBlock(SubVoice* pVoice);
float_t VoiceGetSample(SubVoice* pVoice, 
    uint32_t waveShape1, uint32_t waveShape2, 
    float_t tune1, float_t tune2, 
    float_t shape1, float_t shape2,
    float_t lfoValue);

float VoiceEligibility(SubVoice* pVoice, uint8_t noteIdx);

}