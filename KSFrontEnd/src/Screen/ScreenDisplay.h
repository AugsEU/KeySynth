// ============================================================================
// Functions to display things on the screen.
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <Arduino.h>

#define USE_ADAFRUIT_LIBRARY 0

#if USE_ADAFRUIT_LIBRARY
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#else // USE_ADAFRUIT_LIBRARY
#include <ILI9341_Constants.h>
#include <ILI9341_DeferDriver.h>
#include <ILI9341_ImmediateDriver.h>
#endif // USE_ADAFRUIT_LIBRARY

// ============================================================================
// Public constants
// ============================================================================
constexpr uint16_t SC_BLACK   = 0x0000;
constexpr uint16_t SC_BLUE    = 0x001F;
constexpr uint16_t SC_RED     = 0xF800;
constexpr uint16_t SC_GREEN   = 0x07E0;
constexpr uint16_t SC_CYAN    = 0x07FF;
constexpr uint16_t SC_MAGENTA = 0xF81F;
constexpr uint16_t SC_YELLOW  = 0xFFE0;
constexpr uint16_t SC_WHITE   = 0xFFFF;

#define Display_t ILI9341::DeferDriver


// ============================================================================
// Public functions
// ============================================================================

/// @brief Call once on init
void SetupScreenDisplay();

/// @brief Call each "frame". Renders some pixels
void ScreenDisplayUpdate();

/// @brief Get main screen driver
/// @return Screen driver
Display_t& GetScreen();
