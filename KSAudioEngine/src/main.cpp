// ============================================================================
// Includes
// ============================================================================
#include <I2S/Teensy4i2s.h>
#include <Wire.h>
#include <SPI.h>
#include <arm_math.h>
#include <WaveGen.h>

// ============================================================================
// Constants
// ============================================================================
size_t WRITE_HEAD_DETACHED = size_t(-1);


// ============================================================================
// Globals
// ============================================================================
uint8_t gMsgBuff[8];
size_t gMsgBuffWriteHead = WRITE_HEAD_DETACHED;

void setup(void)
{
	Serial.begin(9600);
	Serial6.begin(115200);
	
	// Start the I2S interrupts
	BeginI2s();
}

void PlayNote(uint8_t noteNum)
{
	gFreq = 110.0f * powf(2.0f, noteNum / 12.0f);
	gVol = 1.0f;
}

void HandleMessage(uint8_t* buf, size_t len)
{
	if(len == 1)
	{
		PlayNote(buf[0]);
	}
}

void loop(void)
{
	int rxByte = Serial6.read();
	if(rxByte != -1)
	{
		if(gMsgBuffWriteHead == WRITE_HEAD_DETACHED)
		{
			if(rxByte == 0xAB)
			{
				gMsgBuffWriteHead = 0;
			}
		}
		else
		{
			if(rxByte == 0xBA)
			{
				HandleMessage(gMsgBuff, gMsgBuffWriteHead);
				gMsgBuffWriteHead = WRITE_HEAD_DETACHED;
			}
			else
			{
				gMsgBuff[gMsgBuffWriteHead] = (uint8_t)rxByte;
				gMsgBuffWriteHead++;
			}
		}
	}

	gVol *= 0.9999999f;
}
