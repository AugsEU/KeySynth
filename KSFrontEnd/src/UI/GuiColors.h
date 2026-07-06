// ============================================================================
// Colors for the gui
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <ILI9341_Types.h>

// ============================================================================
// Types
// ============================================================================
using GuiColor = ILI9341::ILIColor;




// ============================================================================
// Macros
// ============================================================================

// Convert rgb to packed R5G6B5
#define GUI_COLOR(r, g, b) (GuiColor)((((b>>3) & 0x1F) << 11) | (((g>>2) & 0x3F) << 5) | ((r>>3) & 0x1F))

// ============================================================================
// Public constants
// ============================================================================
constexpr GuiColor SC_BLACK   		= GUI_COLOR(0x00, 0x00, 0x00); // #000000
constexpr GuiColor SC_MARBLE_WHITE	= GUI_COLOR(0xf2, 0xf0, 0xe5); // #f2f0e5
constexpr GuiColor SC_SILVER 		= GUI_COLOR(0xb8, 0xb5, 0xb9); // #b8b5b9
constexpr GuiColor SC_LIGHT_MAUVE 	= GUI_COLOR(0x86, 0x81, 0x88); // #868188
constexpr GuiColor SC_GREY 			= GUI_COLOR(0x64, 0x63, 0x65); // #646365
constexpr GuiColor SC_NIGHT_GREY 	= GUI_COLOR(0x45, 0x44, 0x4f); // #45444f
constexpr GuiColor SC_MAGIC_NIGHT 	= GUI_COLOR(0x3a, 0x38, 0x58); // #3a3858
constexpr GuiColor SC_NOBLE_BLACK 	= GUI_COLOR(0x21, 0x21, 0x23); // #212123
constexpr GuiColor SC_OBSIDIAN 		= GUI_COLOR(0x35, 0x2b, 0x42); // #352b42
constexpr GuiColor SC_PALACE 		= GUI_COLOR(0x43, 0x43, 0x6a); // #43436a
constexpr GuiColor SC_BLUE 			= GUI_COLOR(0x4b, 0x80, 0xca); // #4b80ca
constexpr GuiColor SC_ARCTIC_OCEAN 	= GUI_COLOR(0x68, 0xc2, 0xd3); // #68c2d3
constexpr GuiColor SC_YUCCA 		= GUI_COLOR(0xa2, 0xdc, 0xc7); // #a2dcc7
constexpr GuiColor SC_GOLD 			= GUI_COLOR(0xed, 0xe1, 0x9e); // #ede19e
constexpr GuiColor SC_DESERT 		= GUI_COLOR(0xd3, 0xa0, 0x68); // #d3a068
constexpr GuiColor SC_RED 			= GUI_COLOR(0xb4, 0x52, 0x52); // #b45252
constexpr GuiColor SC_MAUVE 		= GUI_COLOR(0x6a, 0x53, 0x6e); // #6a536e
constexpr GuiColor SC_FADED_PURPLE 	= GUI_COLOR(0x4b, 0x41, 0x58); // #4b4158
constexpr GuiColor SC_NUTMEG 		= GUI_COLOR(0x80, 0x49, 0x3a); // #80493a
constexpr GuiColor SC_TUSCAN 		= GUI_COLOR(0xa7, 0x7b, 0x5b); // #a77b5b
constexpr GuiColor SC_CROISSANT 	= GUI_COLOR(0xe5, 0xce, 0xb4); // #e5ceb4
constexpr GuiColor SC_SOFT_FERN 	= GUI_COLOR(0xc2, 0xd3, 0x68); // #c2d368
constexpr GuiColor SC_GREEN 		= GUI_COLOR(0x8a, 0xb0, 0x60); // #8ab060
constexpr GuiColor SC_STREAM 		= GUI_COLOR(0x56, 0x7b, 0x79); // #567b79
constexpr GuiColor SC_VERDANT 		= GUI_COLOR(0x4e, 0x58, 0x4a); // #4e584a
constexpr GuiColor SC_TREE_HUGGER 	= GUI_COLOR(0x7b, 0x72, 0x43); // #7b7243
constexpr GuiColor SC_NILE 			= GUI_COLOR(0xb2, 0xb4, 0x7e); // #b2b47e
constexpr GuiColor SC_LIGHT_PINK 	= GUI_COLOR(0xed, 0xc8, 0xc4); // #edc8c4
constexpr GuiColor SC_PINK 			= GUI_COLOR(0xcf, 0x8a, 0xcb); // #cf8acb
constexpr GuiColor SC_FEDORA 		= GUI_COLOR(0x5f, 0x55, 0x6a); // #5f556a 
constexpr GuiColor SC_WHITE   		= GUI_COLOR(0xFF, 0xFF, 0xFF); // #ffffff


// ============================================================================
// Public globals
// ============================================================================
extern GuiColor gGuiColorPrimary;
extern GuiColor gGuiColorSecondary;
extern GuiColor gGuiColorHighlight;
extern GuiColor gGuiColorShadow;
extern GuiColor gGuiColorBackground;
