// ============================================================================
// Include
// ============================================================================
#include "GuiLabelCounter.h"
#include <Screen\ScreenDisplay.h>
#include "Lib/AugMath.h"

// ============================================================================
// GuiLabelCounter
// ============================================================================

void GuiLabelCounter::Update(uTimeMs dt, bool selected)
{
	if(!selected)
	{
		mWriteCursor = 0xff;
	}
}

void GuiLabelCounter::Draw(bool selected)
{
	Display_t& screen = GetScreen();
	screen.SetCursor(mX, mY);
	screen.SetTextColor(selected ? mHighlightColor : mTextColor);
	screen.SetTextSize(mTextSize);

	// Hack: add space at the end to deal with changing numbers
	char strBuf[64];
	snprintf(strBuf, KS_ARRAY_SIZE(strBuf), "%s <%d> ", mString, mValue);

	screen.DrawText(strBuf, ILI9341_BLACK);
}


bool GuiLabelCounter::OnKeyPress(uint8_t keycode)
{
	if(keycode == mAddKeycode)
	{
		mValue += 1;
		if(mValue > mMaxValue) 
			mValue = mMaxValue;

		SetChanged();
		return true;
	}
	else if(keycode == mMinusKeycode)
	{
		mValue -= 1;
		if(mValue < mMinValue)
			mValue = mMinValue;
			
		SetChanged();
		return true;
	}

	if(HandleNumpadInput(keycode))
	{
		return true;
	}

	return false;
}

bool GuiLabelCounter::HandleNumpadInput(uint8_t keycode)
{
	switch (keycode)
	{
	case KS_KEYCODE_NUM_0:
		AddNumpadInput(0);
		return true;
	case KS_KEYCODE_NUM_1:
		AddNumpadInput(1);
		return true;
	case KS_KEYCODE_NUM_2:
		AddNumpadInput(2);
		return true;
	case KS_KEYCODE_NUM_3:
		AddNumpadInput(3);
		return true;
	case KS_KEYCODE_NUM_4:
		AddNumpadInput(4);
		return true;
	case KS_KEYCODE_NUM_5:
		AddNumpadInput(5);
		return true;
	case KS_KEYCODE_NUM_6:
		AddNumpadInput(6);
		return true;
	case KS_KEYCODE_NUM_7:
		AddNumpadInput(7);
		return true;
	case KS_KEYCODE_NUM_8:
		AddNumpadInput(8);
		return true;
	case KS_KEYCODE_NUM_9:
		AddNumpadInput(9);
		return true;
	case KS_KEYCODE_NUM_ENTER:
		SubmitNumpad();
		return true;
	default:
		break;
	}

	return false;
}

void GuiLabelCounter::AddNumpadInput(uint8_t nextDigit)
{
	bool isNegative = mValue < 0;
	int valueToAdd = isNegative ? -(int)nextDigit : (int)nextDigit;
	if(mWriteCursor == 0xff)
	{
		mWriteCursor = 1;
		mValue = valueToAdd;
	}
	else
	{
		mValue *= 10;
		mValue += valueToAdd;
		mWriteCursor++;
	}

	uint8_t maxDigits = NumDigits(mMaxValue);

	if(maxDigits == mWriteCursor)
	{
		SubmitNumpad();
	}

	SetDirty();

	if(mValue > mMaxValue) 
		mValue = mMaxValue;
	else if(mValue < mMinValue)
		mValue = mMinValue;
}

void GuiLabelCounter::SubmitNumpad()
{
	mWriteCursor = 0xff;
}