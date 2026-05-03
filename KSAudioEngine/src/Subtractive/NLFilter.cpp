// ============================================================================
// Includes
// ============================================================================
#include "NLFilter.h"
#include "Shared/SubParams.h"

#define NLFILTER_FREQ_MAX 0.73f
#define FAST_FILTER_CLIP 1

namespace Subtractive
{

// ============================================================================
// Forward decl
// ============================================================================

float FilterClip(float n);
float LowpassClip(float n);

// ============================================================================
// Globals
// ============================================================================

NLFilter gNLFilter;

// ============================================================================
// Public functions
// ============================================================================

void InitFilter()
{
	gNLFilter.mType = FILTER_MODE_OFF;
	gNLFilter.mSample0 = 0;
	gNLFilter.mSample1 = 0;
	gNLFilter.mQ = 0.9f;

	SetFilterFreq(0.0f);
}

void SetFilterRes(float val)
{
	gNLFilter.mQ = 1.0f - val;
	if(gNLFilter.mQ < 0.01f)
    {
        gNLFilter.mQ = 0.01f;
    }
}

void SetFilterFreq(float val)
{
	val *= (NLFILTER_FREQ_MAX * 0.5f);
	gNLFilter.mFreq = val;
	float g = val * val; // Gain = 18xxx + 3x
    g *= val;
    g *= 18.0f;
    val *= 3.0f;

	gNLFilter.mGain = g + val;
}

void SetFilterType(uint8_t val)
{
	gNLFilter.mType = val;
}

float CalcFilterSample(float smpl)
{
    if(gNLFilter.mType == FILTER_MODE_OFF) // Low pass
	{
        return smpl;
    }

	float out;
	float r;
	const float fg 	= gNLFilter.mGain;
    const float samp0 = gNLFilter.mSample0;
	const float samp1 = gNLFilter.mSample1;

	if (gNLFilter.mFreq >= 0.4499f)
    {
        r = 1.0f;
    }
	else
    {
        r= gNLFilter.mQ;
    } 

	const float df = fg*fg;
	const float s = FilterClip(smpl * 0.8f);
	const float d0 = 1.0f / (1.0f + 2.0f * fg * r);

	const float fdb = df * d0;
	float y1= (fdb * s+ samp1 + fg * d0 * samp0) / (fdb + 1.0f);
	const float dx = s - y1;
	const float y0 = (FilterClip(samp0) + fg * dx) * d0;

	gNLFilter.mSample0 = FilterClip(gNLFilter.mSample0) + 2.0f * fg * (dx - 2.0f * r * y0);
	gNLFilter.mSample1 += 2.0f * fg * y0;

	if(gNLFilter.mType == FILTER_MODE_LP) // Low pass
	{
		return LowpassClip(y1);
	}
	else // High pass
	{
		const float efg = 2*r*y0;
		const float h = s - efg - y1;
		out = h * FLTR_GAIN;

        if (out > 1.0f) out=1.0f;
	    if (out < -1.0f) out= -1.0f;
	}

	return out;
}

#if FAST_FILTER_CLIP
float FilterClip(float n)
{
    if(n < -4.0f) return -2.0f;
    else if(n > 4.0f) return 2.0f;
	
    float a=n*n;
    a *= 0.125f;

    if(signbit(n))
    {
        return n + a;
    }
    
    return n - a;
}

float LowpassClip(float n)
{
	if(n < -2.0f) return -1.0f;
	else if(n > 2.0f) return 1.0f;

	float a = n*n;
	a *= 0.25f;
	
	if(signbit(n))
    {
        return n + a;
    }
    
    return n - a;
}
#else
float FilterClip(float n)
{
	float a=0.5*n;
	float b = a*a;
	a = ((b + 105)*b + 945) / ((15*b + 420)*b + 945);
	return n * a;
}

float LowpassClip(float n)
{
	if(n < -1.95f) return -1.0f;
	else if(n > 1.95f) return 1.0f;
	
	return 4.15f*n/(4.29f+n*n);
}
#endif

}
