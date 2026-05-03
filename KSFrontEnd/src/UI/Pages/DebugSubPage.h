// ============================================================================
// Debug page to demo subtractive synth
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <UI/GuiPage.h>

// ============================================================================
// DebugSubPage
// ============================================================================
class DebugSubPage final : public GuiPage
{
public:
	/// @brief Constructor
	DebugSubPage();

	/// @brief Called once on opening
	void OnOpen() final;
	
	/// @brief Called when updating a frame
	void Update() final;

	/// @brief Called once a key is pressed
	/// @param keycode Key code pressed
	/// @return If the input is stolen or not
	bool OnKeyPress(uint8_t keycode);

private:
	size_t mParamWriteHead = 0;
};