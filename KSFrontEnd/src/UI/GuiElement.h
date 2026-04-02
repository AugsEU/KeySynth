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


#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H

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
	virtual void OnKeyPress(uint8_t keycode) {};

	/// @brief Called whenever a key is released
	/// @param keycode Key code released
	virtual void OnKeyRelease(uint8_t keycode) {};

	uint16_t mX;
	uint16_t mY;
};

#endif // GUI_ELEMENT_H