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



// ============================================================================
// GuiElement
// ============================================================================
class GuiElement
{
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

	uint16_t mX;
	uint16_t mY;
};
