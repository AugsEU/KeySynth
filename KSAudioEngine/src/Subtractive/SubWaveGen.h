// ============================================================================
// Includes
// ============================================================================
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef SUB_WAVEGEN_H
#define SUB_WAVEGEN_H

namespace Subtractive
{

// ============================================================================
// Public functions
// ============================================================================
void SynthInit(void);
void FillSoundBuffer(uint16_t* buf, uint16_t samples);

}

#endif // SUB_WAVEGEN_H