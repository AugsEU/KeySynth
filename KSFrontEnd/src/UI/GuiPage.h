// ============================================================================
// Class for gui section base class
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>
#include <Lib\VariantVector.h>

#include "GuiElement.h"
#include "GuiElementSize.h"


#ifndef GUI_PAGE_H
#define GUI_PAGE_H

// ============================================================================
// GuiPage
// ============================================================================
class GuiPage
{
	void Update();
	void Draw();

protected:
	VariantVector<GuiElement, ELEMENT_MAX_SIZE, 32> mElements;
	int mSelectedElementIndex = -1;
	uTimeMs mPrevUpdate = 0;
};

#endif // GUI_PAGE_H