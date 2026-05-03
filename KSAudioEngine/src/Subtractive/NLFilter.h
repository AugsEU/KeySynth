// ============================================================================
// Non-linear filter for subtractive synth
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Includes
// ============================================================================
#include <stdint.h>
#include <math.h>



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
	float	    mFreq;
	float		mGain;
	float		mQ;
	float		mSample0;
	float		mSample1;
};

// ============================================================================
// Public functions
// ============================================================================
void 	InitFilter();
void 	SetFilterFreq(float val);
void 	SetFilterRes(float val);
void 	SetFilterType(uint8_t type);

float   CalcFilterSample(float smpl);

}
