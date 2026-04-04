// ============================================================================
// Include
// ============================================================================
#include "SynthParams.h"



#include <math.h>

// ============================================================================
// Globals
// ============================================================================
SynthParamBounds gSynthParamBounds[NUM_PARAMETERS];
int8_t gSynthParamValues[NUM_PARAMETERS];





// ============================================================================
// Public functions
// ============================================================================
void InitParams()
{
    memset(gSynthParamValues, 0, sizeof(gSynthParamValues));

    // General          Type                                                        Bound
    gSynthParamBounds[ASP_TUNING             ] = SynthParamBounds(NUM_TUNINGS-1);
    gSynthParamBounds[ASP_DRIVE              ] = SynthParamBounds(50);
    gSynthParamBounds[ASP_GAIN               ] = SynthParamBounds(50);
    gSynthParamBounds[ASP_DELAY_TIME         ] = SynthParamBounds(50);
    gSynthParamBounds[ASP_DELAY_FEEDBACK     ] = SynthParamBounds(50);
    gSynthParamBounds[ASP_DELAY_SHEAR        ] = SynthParamBounds(50);
    gSynthParamBounds[ASP_DELAY_MODE         ] = SynthParamBounds(NUM_DELAY_MODES-1);
    gSynthParamBounds[ASP_SOUND_TYPE         ] = SynthParamBounds(NUM_SOUNT_TYPES-1);
 
    // DCO 
    gSynthParamBounds[ASP_DCO_WAVE_TYPE_1    ] = SynthParamBounds(NUM_OSC_MODES-1);
    gSynthParamBounds[ASP_DCO_TUNE_1         ] = SynthParamBounds(-50);
    gSynthParamBounds[ASP_DCO_VOL_1          ] = SynthParamBounds(50);
    gSynthParamBounds[ASP_DCO_WS_1           ] = SynthParamBounds(20);
    gSynthParamBounds[ASP_DCO_WAVE_TYPE_2    ] = SynthParamBounds(NUM_OSC_MODES-1);
    gSynthParamBounds[ASP_DCO_TUNE_2         ] = SynthParamBounds(-50);
    gSynthParamBounds[ASP_DCO_VOL_2          ] = SynthParamBounds(50);
    gSynthParamBounds[ASP_DCO_WS_2           ] = SynthParamBounds(20);

    // ENV
    gSynthParamBounds[ASP_ENV_ATTACK1        ] = SynthParamBounds(99);
    gSynthParamBounds[ASP_ENV_DECAY1         ] = SynthParamBounds(99);
    gSynthParamBounds[ASP_ENV_SUSTAIN1       ] = SynthParamBounds(50);
    gSynthParamBounds[ASP_ENV_RELEASE1       ] = SynthParamBounds(99);
    gSynthParamBounds[ASP_ENV_ATTACK2        ] = SynthParamBounds(99);
    gSynthParamBounds[ASP_ENV_DECAY2         ] = SynthParamBounds(99);
    gSynthParamBounds[ASP_ENV_SUSTAIN2       ] = SynthParamBounds(50);
    gSynthParamBounds[ASP_ENV_RELEASE2       ] = SynthParamBounds(99);
   
    // VCF   
    gSynthParamBounds[ASP_VCF_CUTOFF         ] = SynthParamBounds(50);
    gSynthParamBounds[ASP_VCF_RES            ] = SynthParamBounds(20);
    gSynthParamBounds[ASP_VCF_MODE           ] = SynthParamBounds(NUM_FILTER_MODES-1);
    gSynthParamBounds[ASP_VCF_FOLLOW         ] = SynthParamBounds(20);
   
    // LFO   
    gSynthParamBounds[ASP_LFO_RATE           ] = SynthParamBounds(99);
    gSynthParamBounds[ASP_LFO_WAVE_TYPE      ] = SynthParamBounds(NUM_LFO_OSC_MODES-1);
    gSynthParamBounds[ASP_LFO_ATTACK         ] = SynthParamBounds(99);
    gSynthParamBounds[ASP_LFO_WOBBLE         ] = SynthParamBounds(-20);
    gSynthParamBounds[ASP_LFO_OSC1_TUNE      ] = SynthParamBounds(-20);
    gSynthParamBounds[ASP_LFO_OSC1_VOLUME    ] = SynthParamBounds(-20);
    gSynthParamBounds[ASP_LFO_OSC1_SHAPE     ] = SynthParamBounds(-20);
    gSynthParamBounds[ASP_LFO_OSC2_TUNE      ] = SynthParamBounds(-20);
    gSynthParamBounds[ASP_LFO_OSC2_VOLUME    ] = SynthParamBounds(-20);
    gSynthParamBounds[ASP_LFO_OSC2_SHAPE     ] = SynthParamBounds(-20);
    gSynthParamBounds[ASP_LFO_VCF_CUTOFF     ] = SynthParamBounds(-20);
    gSynthParamBounds[ASP_LFO_VCF_RES        ] = SynthParamBounds(-20);
}