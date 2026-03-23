// ============================================================================
// Synths parameters
// ----------------------------------------------------------------------------
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>





// ============================================================================
// SynthParam parameter to send to external synth backend
// ============================================================================
struct SynthParam
{
	SynthParam() {};
    SynthParam(uint8_t paramNum, int8_t maxValue);
    void ApplyDelta(int8_t delta);
	
    float GetNormFloatValue(int8_t value);
    static float ScaleFloat(uint8_t paramNum, float input);
	
    int8_t GetMaxValue();
    int8_t GetMinValue();
    int8_t& GetValue();
	
    void SendValueToBpSynth();
	
    uint8_t mParamNum;
private:
	// A bit tricky but all bounds are (0 to X) or (-X to X)
	// To save space I store (0 to X) as X and (-X to X) as -X
    int8_t mBound;
};



// ============================================================================
// Public functions
// ============================================================================
void InitParams();