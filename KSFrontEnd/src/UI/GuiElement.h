// ============================================================================
// Class for gui element base class
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>
#include <ILI9341_Constants.h>
#include <ILI9341_Types.h>

#include "Gui.h"

// ============================================================================
// GuiElement
// ============================================================================
class GuiElement
{
public:
	struct __attribute__((packed)) Flags
	{
		bool isDirty : 1; // Does need to be redrawn?
		bool changed : 1; // Has the value changed?
	};
	static_assert(sizeof(Flags) == 1, "Check if this changes mysteriously.");

public:
	GuiElement(uint16_t x, uint16_t y);

	/// @brief Render to screen
	/// @param selected Is this selected?
	virtual void Draw(bool selected) = 0;

	/// @brief Update animations and dynamic elements
	/// @param dt Delta time
	/// @param selected Is this selected?
	virtual void Update(uTimeMs dt, bool selected) {};

	/// @brief Called whenever a key is pressed
	/// @param keycode Key code pressed
	/// @return True if the input is stolen
	virtual bool OnKeyPress(uint8_t keycode) { return false; }

	/// @brief Called whenever a key is released
	/// @param keycode Key code released
	/// @return True if the input is stolen
	virtual bool OnKeyRelease(uint8_t keycode) { return false; }

	/// @brief Set element above this one
	/// @param id ID to navigate to when pressing up
	void SetUpNav(ElemId up);

	/// @brief Set element below this one
	/// @param id ID to navigate to when pressing down
	void SetDownNav(ElemId id);

	/// @brief Set element to the left of this one
	/// @param id ID to navigate to when pressing left
	void SetLeftNav(ElemId id);

	/// @brief Set element to the right of this one
	/// @param id ID to navigate to when pressing right
	void SetRightNav(ElemId id);
	
	/// @brief Mark element as dirty
	void SetDirty() { mFlags.isDirty = true; }

	/// @brief Is element dirty
	bool IsDirty() const { return mFlags.isDirty; }

	/// @brief Set element changed flag
	void SetChanged() { mFlags.changed = true; SetDirty(); }

	/// @brief Check change and reset changed flags
	/// @return If the change flag was set
	bool ConsumeChange()
	{
		bool prev = mFlags.changed;
		mFlags.changed = false;
		return prev;
	}

	/// @brief Get element we should navigate to
	/// @param keyPressed Button pressed
	/// @return Element ID we should go to
	ElemId GetNavigatedElement(uint8_t keyPressed);

	// Public attributes
	uint16_t mX;
	uint16_t mY;
	Flags mFlags;

private:
	ElemId mNavDirections[4];
};
