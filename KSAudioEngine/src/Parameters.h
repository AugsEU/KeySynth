// ============================================================================
// Includes
// ============================================================================
#include <math.h>
#include <stdint.h>

#ifndef PARAMETERS_H
#define PARAMETERS_H

// ============================================================================
// Public functions
// ============================================================================

void ZeroOutParams();

float_t GetFloatParam(size_t idx);
void SetFloatParam(size_t idx, float param);

uint32_t GetIntParam(size_t idx);
void SetIntParam(size_t idx, uint32_t param);

#endif // PARAMETERS_H