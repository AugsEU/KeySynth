// ============================================================================
// Home page for GUI
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <UI/GuiPage.h>

// ============================================================================
// HomePage
// ============================================================================
class HomePage final : public GuiPage
{
public:
	/// @brief Constructor
	HomePage();

	/// @brief Called once on opening
	void OnOpen(GuiPageType openType) final;
	
	/// @brief Called when updating a frame
	void Update() final;

private:
	
};