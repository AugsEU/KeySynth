#ifndef __ENVELOPE_H
#define __ENVELOPE_H

// ============================================================================
// Includes
// ============================================================================
#include <stdint.h>
#include <stdbool.h>
#include <math.h>


namespace Subtractive
{
    
// ============================================================================
// Types
// ============================================================================

enum EnvelopeSection
{
    ES_ATTACK,
    ES_DECAY,
    ES_SUSTAIN,
    ES_RELEASE,
    ES_OFF
};

struct Envelope
{
    EnvelopeSection mSection;
    float_t mAttack;
    float_t mDecay;
    float_t mSustain;
    float_t mRelease;
    
    float_t mVolume;
};

// ============================================================================
// Public functions
// ============================================================================

void EnvInit(Envelope* pEnv);
void EnvNextSample(Envelope* pEnv);
    
}
    #endif // __ENVELOPE_H