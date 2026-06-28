// ============================================================================
// Include
// ============================================================================
#include "DebugSubPage.h"

#include <Usart\SynthParams.h>
#include "ILI9341_Device.h"
#include "Shared\SubParams.h"
#include "LocStrings.h"

// ============================================================================
// DebugSubPage
// ============================================================================
DebugSubPage::DebugSubPage()
{
	uint16_t x = 30, y = 20;
	for(size_t i = 0; i < ASP_NUM_PARAMS; ++i)
	{
		GuiLabelCounter* newCounter =
			mElements.push_back<GuiLabelCounter>(x , y);
		AUG_ASSERT(newCounter, "GuiLblCter Fail");

		newCounter->mString = AugNumberParamToString((uint8_t)i);
		newCounter->mTextSize = 2;
		newCounter->mTextColor = 0x5555;

		newCounter->mAddKeycode = KS_KEYCODE_RIGHT_ARROW;
		newCounter->mMinusKeycode = KS_KEYCODE_LEFT_ARROW;

		y += 20;
		if (y > ILI9341::Device::HEIGHT - 30)
		{
			y = 20;
			x += 170;
		}
	}
}

void DebugSubPage::OnOpen()
{
	SelectElem(0);

	for(size_t i = 0; i < ASP_NUM_PARAMS; ++i)
	{
		GuiLabelCounter* pCounter = GetElement<GuiLabelCounter>(i);
		pCounter->mMaxValue = gSynthParamBounds[i].GetMaxValue();
		pCounter->mMinValue = gSynthParamBounds[i].GetMinValue();
		pCounter->mValue = gSynthParamValues[i];
	}
}



void DebugSubPage::Update()
{
	// Send some params
	for(int i = 0; i < 4; ++i)
	{
		GuiLabelCounter* pCounter = GetElement<GuiLabelCounter>(mParamWriteHead);
		int value = pCounter->mValue;

		gSynthParamValues[mParamWriteHead] = (int8_t)value;
		SendParamForSubtractive(mParamWriteHead);

		mParamWriteHead++;
		if(mParamWriteHead >= ASP_NUM_PARAMS)
		{
			mParamWriteHead = 0;
		}
	}
	 
	// Do basic update
	GuiPage::Update();
}
