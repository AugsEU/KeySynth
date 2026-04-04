// ============================================================================
// Class for label with number
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include "GuiElement.h"


// ============================================================================
// GuiLabelCounter
// ============================================================================
class GuiLabelCounter final : public GuiElement
{
public:
	GuiLabelCounter(uint16_t x, uint16_t y) : GuiElement(x, y) {}
	void Draw(bool selected) final;
	bool OnKeyPress(uint8_t keycode) final;

	// Text
	const char* mString = nullptr;
	uint16_t mTextSize = 2;
	ILI9341::ILIColor mTextColor = ILI9341_GREY;
	ILI9341::ILIColor mHighlightColor = ILI9341_WHITE;

	// Value
	int mValue = 0;
	int mMaxValue = 10;
	int mMinValue = 0;

	// Keybinds
	uint8_t mAddKeycode = KS_KEYCODE_NUM_PLUS;
	uint8_t mMinusKeycode = KS_KEYCODE_NUM_MINUS;
};