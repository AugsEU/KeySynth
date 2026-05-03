// ============================================================================
// Includes
// ============================================================================
#include "SVFilter.h"

#include <math.h>
#include <stdint.h>

namespace Subtractive
{

// ============================================================================
// Public functions
// ============================================================================

/// @brief Init the filter
void SvfInit(SVFilter* pFilter)
{
    pFilter->mLp = 0.0f;
    pFilter->mBp = 0.0f;
    pFilter->mHp = 0.0f;
}

/// @brief Process 1 sample
float SvfProcess(SVFilter* pFilter, float sample, float freq, float res, float mode)
{
    res *= res;
    res *= 5.0f;
    res += 1.0f;
    res = 1.0f / res;

    freq *= 0.98f;
    freq *= freq;
    freq += 0.01f;
    freq = 0.01f + 0.99f * freq * freq;;

    // Filter processing
    pFilter->mHp = sample - pFilter->mLp - res * pFilter->mBp;
    pFilter->mBp += pFilter->mHp * freq;
    pFilter->mLp += pFilter->mBp; 
    
    return (pFilter->mLp * mode) + (pFilter->mHp * (1.0f - mode));
}

}