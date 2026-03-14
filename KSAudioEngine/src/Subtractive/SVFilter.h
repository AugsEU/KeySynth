
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>
#include <math.h>

#ifndef __SVFILTER_H
#define __SVFILTER_H

namespace Subtractive
{

// ============================================================================
// Types
// ============================================================================
struct SVFilter
{
    float_t mLp;             // Low-pass state
    float_t mBp;             // Band-pass state
    float_t mHp;             // High-pass state
};

// ============================================================================
// Public functions
// ============================================================================
void SvfInit(SVFilter* pFilter);
float_t SvfProcess(SVFilter* pFilter, float_t sample, float_t freq, float_t res, float_t mode);

}

#endif // __SVFILTER_H