// ============================================================================
// Includes
// ============================================================================
#include <I2S/Teensy4i2s.h>
#include <Wire.h>
#include <SPI.h>
#include <arm_math.h>
#include <WaveGen.h>

#include <Usart/RxFrontEnd.h>
#include "Subtractive/SubWaveGen.h"

// ============================================================================
// Constants
// ============================================================================



// ============================================================================
// Globals
// ============================================================================

void setup(void)
{
	// Begin serial
	Serial.begin(9600);
	RxFrontEndBegin();

	Subtractive::SynthInit();

	// Start the I2S interrupts
	BeginI2s();
}

void loop(void)
{
	// Should this be interrupt based instead?
	RxFrontEndPoll();
}
