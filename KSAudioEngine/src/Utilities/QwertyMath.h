// ============================================================================
// Utilities to receive from the front end
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Includes
// ============================================================================
#include <stdint.h>
#include <math.h>




// ============================================================================
// Public functions
// ============================================================================
uint32_t GetNextRand();
float_t FastUnitExp(float_t x);
float_t ComputeLfoMult(float_t lfoValue, float_t lfoAmount);
float_t ComputeLoudnessMult(float_t loudness, float_t amount);
float_t ShapeWave(float_t waveValue, float_t waveShape);
float_t DrivenSample(float_t sample);
