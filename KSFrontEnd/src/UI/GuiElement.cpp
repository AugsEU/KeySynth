// ============================================================================
// Include
// ============================================================================
#include "GuiElement.h"





// ============================================================================
// GuiElement
// ============================================================================
GuiElement::GuiElement(uint16_t x, uint16_t y) :
	mX(x),
	mY(y)
{
	mNavDirections[0] = EMPTY_ID;
	mNavDirections[1] = EMPTY_ID;
	mNavDirections[2] = EMPTY_ID;
	mNavDirections[3] = EMPTY_ID;

	// All elements start dirty since they need to be drawn at least once
	mFlags.isDirty = true;
	
	mFlags.changed = false;
}


void GuiElement::SetUpNav(ElemId id)
{
	mNavDirections[3] = id;
}

void GuiElement::SetDownNav(ElemId id)
{
	mNavDirections[2] = id;
}

void GuiElement::SetLeftNav(ElemId id)
{
	mNavDirections[1] = id;
}

void GuiElement::SetRightNav(ElemId id)
{
	mNavDirections[0] = id;
}

ElemId GuiElement::GetNavigatedElement(uint8_t keyPressed)
{
	// We assume these are in this exact order
	static_assert(KS_KEYCODE_RIGHT_ARROW == 0x4F);
	static_assert(KS_KEYCODE_LEFT_ARROW == 0x50);
	static_assert(KS_KEYCODE_DOWN_ARROW == 0x51);
	static_assert(KS_KEYCODE_UP_ARROW == 0x52);

	if(KS_KEYCODE_RIGHT_ARROW <= keyPressed && keyPressed <= KS_KEYCODE_UP_ARROW)
	{
		return mNavDirections[keyPressed - KS_KEYCODE_RIGHT_ARROW];
	}

	return EMPTY_ID;
}