// ============================================================================
// Include
// ============================================================================
#include "Screen/ScreenDisplay.h"
#include "Screen/ScreenTest.h"

#include "UI/Pages/General/HomePage.h"

#include "UI/Pages/Subtractive/SubGeneralPage.h"
#include "UI/Pages/Subtractive/SubOscPage.h"
#include "UI/Pages/Subtractive/SubEnvPage.h"
#include "UI/Pages/Subtractive/SubFiltPage.h"
#include "UI/Pages/Subtractive/SubLfoPage.h"
#include "UI/Pages/Subtractive/SubDelayPage.h"


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
static GuiPageType gCurrPageType = GuiPageType::Home;

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
	gDevice.MemoryAccessCtrl(ILI9341::RowOrder::TopToBottom,
		ILI9341::ColOrder::LeftToRight,
		ILI9341::RowColExchange::Reverse,
		ILI9341::RowOrder::TopToBottom,
		ILI9341::RgbOrder::RGB,
		ILI9341::ColOrder::LeftToRight);
	gDriver.ForceClear(gGuiColorBackground);
	if(err != ILI9341_OK)
	{
		Serial.printf("Display error. %x", (uint32_t)err);
	}
#endif // USE_ADAFRUIT_LIBRARY

#if SCREEN_TEST_ENABLE
	RunScreenTest();
#endif // SCREEN_TEST_ENABLE

	SelectUiPage(GuiPageType::Home);
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

ILI9341::Device& GetScreenDevice()
{
	return gDevice;
}

GuiPage* GetCurrentUiPage()
{
	static HomePage sHomePage;

	static SubGeneralPage sSubGeneralPage;
	static SubOscPage sSubOscPage;
	static SubEnvPage sSubEnvPage;
	static SubFiltPage sSubFiltPage;
	static SubLfoPage sSubLfoPage;
	static SubDelayPage sSubDelayPage;

	switch (gCurrPageType)
	{
	case GuiPageType::Home:
		return &sHomePage;
	case GuiPageType::SubGeneral:
		return &sSubGeneralPage;
	case GuiPageType::SubOsc1:
	case GuiPageType::SubOsc2:
		return &sSubOscPage;
	case GuiPageType::SubEnv1:
	case GuiPageType::SubEnv2:
		return &sSubEnvPage;
	case GuiPageType::SubFilt:
		return &sSubFiltPage;
	case GuiPageType::SubLfo:
		return &sSubLfoPage;
	case GuiPageType::SubDelay:
		return &sSubDelayPage;
	case GuiPageType::NumGuiPages:
		break;
	}

	return nullptr;
}

GuiPageType GetCurrentUiPageType()
{
	return gCurrPageType;
}

void SelectUiPage(GuiPageType type)
{
	GuiPage* currPage = GetCurrentUiPage();
	if(currPage)
	{
		currPage->OnClose();
	}
	
	gDriver.ForceClear(gGuiColorBackground);
	gCurrPageType = type;

	GuiPage* newPage = GetCurrentUiPage();

	if(newPage)
	{
		newPage->InvalidateAll();
		newPage->OnOpen(type);
	}
}