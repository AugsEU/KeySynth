// ============================================================================
// Include
// ============================================================================
#include "GuiLabelCounter.h"
#include <Screen\ScreenDisplay.h>


// ============================================================================
// GuiLabelCounter
// ============================================================================
void GuiLabelCounter::Draw(bool selected)
{
	Display_t& screen = GetScreen();
	screen.SetCursor(mX, mY);
	screen.SetTextColor(selected ? mHighlightColor : mTextColor);
	screen.SetTextSize(mTextSize);

	char strBuf[64];
	snprintf(strBuf, KS_ARRAY_SIZE(strBuf), "%s <%d>", mString, mValue);

	screen.DrawText(strBuf, ILI9341_BLACK);
}


bool GuiLabelCounter::OnKeyPress(uint8_t keycode)
{
	if(keycode == mAddKeycode)
	{
		mValue += 1;
		if(mValue > mMaxValue) 
			mValue = mMaxValue;

		return true;
	}
	else if(keycode == mMinusKeycode)
	{
		mValue -= 1;
		if(mValue < mMinValue)
			mValue = mMinValue;
			
		return true;
	}

	return false;
}