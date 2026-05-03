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
public:
	/// @brief Called once when opening
	virtual void OnOpen() {}

	/// @brief Called once when closing
	virtual void OnClose() {}

	/// @brief Update page and all elements, call this regularly
	virtual void Update();

	/// @brief Draw all elemetns, call this each frame.
	void Draw();

	/// @brief Get element currently selected
	GuiElement* GetSelectedElement();

	/// @brief Called once a key is pressed
	/// @param keycode Key code pressed
	/// @return If the input is stolen or not
	virtual bool OnKeyPress(uint8_t keycode) { return false; }

protected:
	VariantVector<GuiElement, ELEMENT_MAX_SIZE, 64> mElements;
	size_t mSelectedElementIndex = size_t(-1);
	uTimeMs mPrevUpdate = 0;
};
