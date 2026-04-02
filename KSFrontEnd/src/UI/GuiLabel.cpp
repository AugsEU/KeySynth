// ============================================================================
// Include
// ============================================================================
#include "GuiLabel.h"
#include <Screen\ScreenDisplay.h>

// ============================================================================
// GuiLabel
// ============================================================================
void GuiLabel::Draw(bool selected)
{
	Display_t& screen = GetScreen();
	screen.SetCursor(mX, mY);
	screen.SetTextColor(selected ? mHighlightColor : mTextColor);
	screen.SetTextSize(mTextSize);

	screen.DrawText(mString);
}