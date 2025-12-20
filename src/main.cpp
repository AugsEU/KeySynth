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
		float32_t wave = (float)acc / 100.0f;
		wave = sinf(M_TWOPI * wave);
		int32_t sig = (int32_t)(100.0f * wave);
		//sig = sig | (sig << 16);
		outputs[0][i] = sig;
		outputs[1][i] = sig;

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