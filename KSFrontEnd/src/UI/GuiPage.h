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
