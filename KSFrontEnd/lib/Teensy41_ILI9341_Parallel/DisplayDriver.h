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

protected:

	/// @brief Attempt to connect to device
	/// @return Error code
	int EstablishConnection();

	T4_ILI9341 mDevice;
	Status mStatus;
};

}

#endif // ILI9341_DISPLAY_DRIVER_H