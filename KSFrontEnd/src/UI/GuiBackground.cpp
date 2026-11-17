// ============================================================================
// Include
// ============================================================================
#include "GuiBackgroud.h"

#include <Screen\ScreenDisplay.h>

#include "GuiColors.h"
// ============================================================================
// Constants
// ============================================================================


// ============================================================================
// Public functions
// ============================================================================

/// @brief Draw box with fancy drop shadow and tasteful corner cut
void GuiBgFancyBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
	constexpr uint16_t OFFSET = 7;
	Display_t& driver = GetScreen();



	// == Blank
	driver.FillRect(x, y, w, h, gGuiColorBackground);
	
	// == Main box
	// Top
	ILI9341::ILIColor col = gGuiColorSecondary;
	driver.DrawLine(x,   y,
					x+w, y, 
					col);
	// Right
	driver.DrawLine(x+w, y,
					x+w, y+h-OFFSET, 
					col);
	// Bot right corner
	driver.DrawLine(x+w,        y+h-OFFSET,
					x+w-OFFSET, y+h, 
					col);
	// Bottom
	driver.DrawLine(x+w-OFFSET, y+h,
					x, 			y+h,
					col);
	// Left
	driver.DrawLine(x, y+h,
					x, y,
					col);

	// == Shadow box
	ILI9341::ILIColor darkCol = gGuiColorShadow;

	// Top
	driver.DrawLine(x+w+1,      y+OFFSET,
					x+w+OFFSET, y+OFFSET, 
					darkCol);
	// Right
	driver.DrawLine(x+w+OFFSET, y+OFFSET, 
					x+w+OFFSET, y+h, 
					darkCol);
	// Bot right corner
	driver.DrawLine(x+w+OFFSET, y+h,
					x+w,        y+h+OFFSET, 
					darkCol);
	// Bottom
	driver.DrawLine(x+w,        y+h+OFFSET,
					x+OFFSET,	y+h+OFFSET,
					darkCol);
	// Left
	driver.DrawLine(x+OFFSET,	y+h+OFFSET,
					x+OFFSET, 	y+h+1,
					darkCol);
}