// ============================================================================
// Stores max size of gui elements
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>

#include "GuiElement.h"





// ============================================================================
// GuiLabel
// ============================================================================
class GuiLabel final : public GuiElement
{
public:
	void Draw(bool selected) final;

	const char* mString = nullptr;
	uint16_t mTextSize = 2;
	ILI9341::ILIColor mTextColor = ILI9341_GREY;
	ILI9341::ILIColor mHighlightColor = ILI9341_WHITE;
};
