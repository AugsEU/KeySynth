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
		newCounter->mTextSize = 1;
		newCounter->mTextColor = 0x2222;

		newCounter->mAddKeycode = KS_KEYCODE_RIGHT_ARROW;
		newCounter->mMinusKeycode = KS_KEYCODE_LEFT_ARROW;

		y += 10;
		if (y > ILI9341::Device::HEIGHT - 30)
		{
			y = 20;
			x += 70;
		}
	}
}

void DebugSubPage::OnOpen()
{
	mSelectedElementIndex = 0;

	for(size_t i = 0; i < ASP_NUM_PARAMS; ++i)
	{
		GuiLabelCounter* pCounter = (GuiLabelCounter*)mElements[i];
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
		GuiLabelCounter* pCounter = (GuiLabelCounter*)mElements[mParamWriteHead];
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



bool DebugSubPage::OnKeyPress(uint8_t keycode)
{
	if(keycode == KS_KEYCODE_UP_ARROW)
	{
		if(mSelectedElementIndex > 0)
			mSelectedElementIndex--;
		
		return true;
	}
	else if(keycode == KS_KEYCODE_DOWN_ARROW)
	{
		if(mSelectedElementIndex < mElements.size() - 1)
			mSelectedElementIndex++;
		
		return true;
	}
	
	bool elemStole = false;
	GuiElement* pElem = GetSelectedElement();
	if(pElem)
		elemStole = pElem->OnKeyPress(keycode);	

	return elemStole;
}