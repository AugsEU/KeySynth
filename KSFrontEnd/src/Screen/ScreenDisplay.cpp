// ============================================================================
// Include
// ============================================================================
#include "Screen/ScreenDisplay.h"
#include "Screen/ScreenTest.h"

#include "UI/Pages/DebugSubPage.h"





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
#if USE_ADAFRUIT_LIBRARY
Adafruit_TFTLCD gTftScreen(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
#else // USE_ADAFRUIT_LIBRARY
ILI9341::Device gDevice(LCD_CS, LCD_CD, LCD_WR, LCD_RD);
Display_t gDriver(gDevice);
#endif // USE_ADAFRUIT_LIBRARY

// Screen pages
static GuiPageType gCurrPageType = GuiPageType::None;
static DebugSubPage gSubPage;





// ============================================================================
// Private functions
// ============================================================================





// ============================================================================
// Public functions
// ============================================================================
void SetupScreenDisplay(void) 
{
#if USE_ADAFRUIT_LIBRARY
 	gTftScreen.reset();
	gTftScreen.begin(0x9341);
#else // USE_ADAFRUIT_LIBRARY
	int err = gDriver.Begin();
	if(err != ILI9341_OK)
	{
		Serial.printf("Display error. %x", (uint32_t)err);
	}
#endif // USE_ADAFRUIT_LIBRARY

#if SCREEN_TEST_ENABLE
	RunScreenTest();
#endif // SCREEN_TEST_ENABLE

	SelectUiPage(GuiPageType::DebugSubtractive);
}

void ScreenDisplayUpdate()
{
	static int sPageUpdateCounter = 0;
	GuiPage* currPage = GetCurrentUiPage();
	if(currPage)
	{
		if(sPageUpdateCounter-- < 0)
		{
			sPageUpdateCounter = 5;
			currPage->Update();
		}

		currPage->Draw();
	}

	gDriver.RenderAllPixels();
}

Display_t& GetScreen()
{
	return gDriver;
}

GuiPage* GetCurrentUiPage()
{
	switch (gCurrPageType)
	{
	case GuiPageType::DebugSubtractive:
		return &gSubPage;
	default:
		break;
	}

	return nullptr;
}

void SelectUiPage(GuiPageType type)
{
	GuiPage* currPage = GetCurrentUiPage();
	if(currPage)
	{
		currPage->OnClose();
	}

	gCurrPageType = type;

	GuiPage* newPage = GetCurrentUiPage();

	if(newPage)
	{
		newPage->OnOpen();
	}
}