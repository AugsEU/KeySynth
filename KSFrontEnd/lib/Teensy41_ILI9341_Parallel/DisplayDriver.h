// ============================================================================
// ILI9341 display driver. Use to abstract functions from the raw device 
// commands.
// ----------------------------------------------------------------------------
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>
#include "T4_ILI9341.h"

#ifndef ILI9341_DISPLAY_DRIVER_H
#define ILI9341_DISPLAY_DRIVER_H

namespace ILI9341
{

// ============================================================================
// DisplayDriver - Abstract display driver.
// ============================================================================
class DisplayDriver
{
public:
	enum class Status
    {
        Offline,
        Online // Device successfully setup and ready to use.
    };



	/// @brief Create new display driver
	/// @param device ILI device to interface with.
	DisplayDriver(T4_ILI9341 device);



	/// @brief Begin driver after the screen has been created
    /// @return Error code.
    int Begin();



	/// @brief Draw a single pixel
	/// @param x x-coordinate
	/// @param y y-coordinate
	/// @param col packed 16-bit color
	virtual void DrawPixel(uint16_t x, uint16_t y, ILIColor col) = 0;



	/// @brief Directly write color to every pixel in LCD.
	/// @param col Color to write
	/// @return Error code.
	virtual void ForceClear(ILIColor col);



	/// @brief Draw 1px line between sx and sy
	/// @param sx start x
	/// @param sy stary y
	/// @param ex end x
	/// @param ey end y
	/// @param col line color
	void DrawLine(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, ILIColor col);



	/// @brief Draw rectangle outline
	/// @param x top-left x-coordinate
	/// @param y top-left y-coordinate
	/// @param w width
	/// @param h height
	/// @param col packed 16-bit color
	void DrawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, ILIColor col);



	/// @brief Draw rectangle fill
	/// @param x top-left x-coordinate
	/// @param y top-left y-coordinate
	/// @param w width
	/// @param h height
	/// @param col packed 16-bit color
	virtual void FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, ILIColor col);



	/// @brief Draw circle outline
	/// @param x center x-coordinate
	/// @param y center y-coordinate
	/// @param r radius
	/// @param color outline color
	void DrawCircle(uint16_t x, uint16_t y, uint16_t r, ILIColor color);



	/// @brief Fill circle
	/// @param x center x-coordinate
	/// @param y center y-coordinate
	/// @param r radius
	/// @param color fill color
	void FillCircle(uint16_t x, uint16_t y, uint16_t r, ILIColor color);



	/// @brief Set text cursor to absolute position.
	/// @param x cursor x-coordinate
	/// @param y cursor y-coordinate
	inline void SetCursor(uint16_t x, uint16_t y) { mCursorX = x; mCursorY = y; }



	/// @brief Set the font's color for subsequent draws
	/// @param col Font's color
	inline void SetTextColor(ILIColor col) { mFontColor = col; }



	/// @brief Set the font's size for subsquent draws
	/// @param mult Multiplier to apply to the font's size.
	inline void SetTextSize(uint16_t mult) { mFontSize = mult; }



	/// @brief Set pixel data for font.
	/// @param data Pixel data where each byte is one 8-pixel column. Chars 
	///             assumed to be 5 pixels wide. Begin data at 0x21 to 0x7F
	inline void SetFont(const uint8_t* data) { mFontData = data; }



	/// @brief Draw a string using previously set parameters.
	/// @param string String to draw.
	void DrawText(const char* string);



	/// @brief Draw a character at a point using previously set font params.
	///        Does not move cursor.
	/// @param x char x-coordinate
	/// @param y char y-coordinate
	/// @param c character to draw. Must be 0x21 to 0x7F
	void DrawChar(uint16_t x, uint16_t y, char c);

protected:

	/// @brief Attempt to connect to device
	/// @return Error code
	int EstablishConnection();

	T4_ILI9341 mDevice;
	Status mStatus;
	uint16_t mCursorX;
	uint16_t mCursorY;
	uint16_t mFontSize;
	ILIColor mFontColor;
	const uint8_t* mFontData;
};

}

#endif // ILI9341_DISPLAY_DRIVER_H