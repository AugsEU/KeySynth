	// ============================================================================
// Include
// ============================================================================
#include "ILI9341_ImmediateDriver.h"
#include "ILI9341_Constants.h"

#include "Arduino.h"

namespace ILI9341
{

ImmediateDriver::ImmediateDriver(Device device) : 
	DisplayDriver(device)
{
}



void ImmediateDriver::DrawPixel(uint16_t x, uint16_t y, ILIColor col)
{
	mDevice.ColumnAddrSet(x, x+1);
	mDevice.PageAddrSet(y, y+1);

	mDevice.MemoryWrite(col, 1);
}



void ImmediateDriver::FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, ILIColor col)
{
	mDevice.ColumnAddrSet(x, x+w-1);
	mDevice.PageAddrSet(y, y+h);
	
	mDevice.MemoryWrite(col, w*h);
}


}