#include <I2S/Teensy4i2s.h>
#include <I2S/AudioConfig.h>
#include <Wire.h>
#include <SPI.h>
#include <arm_math.h>

int32_t acc = 0;
void processAudio(int32_t** inputs, int32_t** outputs)
{
	for (size_t i = 0; i < AUDIO_BLOCK_SAMPLES; i++)
	{
		// use can use regular sinf() as well, but it's highly recommended 
		// to use these optimised arm-specific functions whenever possible
		acc++;
		float32_t waveL = (float)acc / 100.0f;
		waveL = sinf(M_TWOPI * waveL);
		int32_t sigL = (int32_t)(100.0f * waveL);

		float32_t waveR = (float)acc / 100.0f;
		waveR = cosf(2.0f * M_TWOPI * waveR);
		int32_t sigR = (int32_t)(100.0f * waveR);

		//sig = sig | (sig << 16);
		//uint16_t sig16 = (uint16_t)sigL; 
		uint32_t sig32 = (uint16_t)sigR;//
		sig32 <<= 16;
		sig32 |= (uint16_t)sigL;
		//sig32 = sig32 | (sig32<<16);
		//outputs[0][i] = sig32;
		outputs[1][i] = sig32;

		if (acc >= 100)
			acc = 0;
	}
}

void setup(void)
{
	Serial.begin(9600);

	// Assign the callback function
	i2sAudioCallback = processAudio;

	// Start the I2S interrupts
	InitI2s();

	// need to wait a bit before configuring codec, otherwise something weird happens and there's no output...
	delay(1000); 
}

void loop(void)
{
	delay(1000);
	float avg = Timers::GetPeak(Timers::TIMER_TOTAL);
	float period = Timers::GetAvgPeriod();
	float percent = avg / period * 100;
	Serial.print("CPU Usage: ");
	Serial.print(percent, 4);
	Serial.print("%");
	Serial.print(" -- Processing period: ");
	Serial.print(period/1000, 3);
	Serial.println("ms");
}