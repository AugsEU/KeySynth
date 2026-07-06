// ============================================================================
// Class for gui section base class
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <Lib\VariantVector.h>

#include "GuiElement.h"
#include "GuiElementSize.h"
#include "GuiColors.h"

#include "Gui.h"

// ============================================================================
// Macros
// ============================================================================

// Do statement on change
#define ON_ELEM_CHANGE(id, T, statement) \
	do \
	{ \
		T* elem = GetElement<T>(id); \
		if(elem->ConsumeChange()) statement \
	} while (false)





// ============================================================================
// Types
// ============================================================================
enum GuiPageType : size_t
{
	Home,
	// Subtractive synth editing pages
	SubGeneral,
	SubOsc1,
	SubOsc2,
	SubEnv1,
	SubEnv2,
	SubFilt,
	SubLfo,
	SubDelay,
	NumGuiPages,
};





// ============================================================================
// GuiPage
// ============================================================================
class GuiPage
{
public:
	// ========================================================================
	// Core interface
	// ========================================================================

	/// @brief Called once when opening
	virtual void OnOpen(GuiPageType openType) {}

	/// @brief Called once when closing
	virtual void OnClose() {}

	/// @brief Update page and all elements, call this regularly
	virtual void Update();

	/// @brief Draw all elemetns, call this each frame.
	void Draw();

	/// @brief Called once a key is pressed
	/// @param keycode Key code pressed
	/// @return If the input is stolen or not
	virtual bool OnKeyPress(uint8_t keycode);

	/// @brief Invalidate screen and force redraw
	void InvalidateAll();

	// ========================================================================
	// Utility
	// ========================================================================

	/// @brief Get element currently selected
	GuiElement* GetSelectedElement();

	/// @brief Get an element of type T (unsafe)
	/// @tparam T Type of element
	/// @param id element ID
	template <typename T>
	T* GetElement(ElemId id)
	{
		if(id == EMPTY_ID) return nullptr;
		return static_cast<T*>(mElements[id]);
	}

	/// @brief Get element base class pointer
	/// @param id element ID
	GuiElement* GetElement(ElemId id)
	{
		if(id == EMPTY_ID) return nullptr;
		return mElements[id];
	}

	// ========================================================================
	// Navigation
	// ========================================================================

	/// @brief Select element
	/// @param id ID to select
	void SelectElem(ElemId id);

	/// @brief Link two elements so low navigates to high by pressing up and
	/// vice versa
	/// @param low Lower element 
	/// @param high Higher element
	void LinkUpDown(ElemId low, ElemId high);

	/// @brief Link two elements so left navigates to right by pressing right and
	/// vice versa
	/// @param low Leftmost element 
	/// @param high Rightmost element
	void LinkLeftRight(ElemId left, ElemId right);

	// ========================================================================
	// Element creation
	// ========================================================================
	
	/// @brief Create label with default styling
	ElemId CreateLabel(uint16_t x, uint16_t y, const char* text);

	/// @brief Create counter label with default styling
	ElemId CreateCounterLabel(uint16_t x, uint16_t y, const char* text);

protected:
	VariantVector<GuiElement, ELEMENT_MAX_SIZE, 32> mElements;
	uTimeMs mPrevUpdate = 0;
private:
	ElemId mSelectedElem = EMPTY_ID;
};
