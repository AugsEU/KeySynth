// ============================================================================
// Include
// ============================================================================
#include "Screen/ScreenDisplay.h"
#include "Screen/ScreenTest.h"

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library

// ============================================================================
// Constants
// ============================================================================
#define LCD_CS 9 // Chip Select
#define LCD_CD 10 // Command/Data
#define LCD_WR 11 // LCD Write
#define LCD_RD 12 // LCD Read
#define LCD_RESET 0 // Reset (disabled)





// ============================================================================
// Global variables
// ============================================================================
Adafruit_TFTLCD gTftScreen(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);





// ============================================================================
// Public functions
// ============================================================================
void SetupScreenDisplay(void) 
{
	gTftScreen.reset();

	uint16_t identifier = gTftScreen.readID();
	gTftScreen.begin(identifier);

#if SCREEN_TEST_ENABLE
	RunScreenTest();
#endif // SCREEN_TEST_ENABLE
}

void ScreenDisplayUpdate()
{

}

