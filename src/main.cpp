#include <I2S/Teensy4i2s.h>
#include <Wire.h>
#include <SPI.h>
#include <arm_math.h>

void setup(void)
{
	Serial.begin(9600);

	// Start the I2S interrupts
	BeginI2s();

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