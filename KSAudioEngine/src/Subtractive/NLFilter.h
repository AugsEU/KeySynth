// ============================================================================
// Includes
// ============================================================================
#include <stdint.h>
#include <math.h>

#ifndef NL_FILTER_H
#define NL_FILTER_H

// ============================================================================
// Public constants
// ============================================================================
#define FLTR_GAIN 					   	0.87f
#define MAX_FREQ						2200.f
#define MIN_FREQ						20.f

namespace Subtractive
{

// ============================================================================
// Types
// ============================================================================
struct NLFilter
{
	uint8_t 	mType;
	float_t	    mFreq;
	float_t		mGain;
	float_t		mQ;
	float_t		mSample0;
	float_t		mSample1;
};

// ============================================================================
// Public functions
// ============================================================================
void 	InitFilter();
void 	SetFilterFreq(float_t val);
void 	SetFilterRes(float_t val);
void 	SetFilterType(uint8_t type);

float_t   CalcFilterSample(float_t smpl);

}

#endif /* NL_FILTER_H */