// ============================================================================
// ILI9341 deferred display driver. Writes pixels directly to screen. Very slow
// but saves on memory compared to deferred drivers.
// ----------------------------------------------------------------------------
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>
#include "ILI9341_DisplayDriver.h"

#ifndef ILI9341_IMMEDIATE_DRIVER_H
#define ILI9341_IMMEDIATE_DRIVER_H

namespace ILI9341
{
// ============================================================================
// ImmediateDriver. ILI9341 driver that writes pixels directly to screen. Very
// slow but saves on memory compared to deferred drivers.
// ============================================================================
class ImmediateDriver final : public DisplayDriver
{
public:
	/// @brief Create ILI9341 driver that writes pixels directly to screen.
	/// @param device TFT screen device.
	ImmediateDriver(Device device);



	/// @brief Draw a single pixel
	/// @param x x-coordinate
	/// @param y y-coordinate
	/// @param col packed 16-bit color
	void DrawPixel(uint16_t x, uint16_t y, ILIColor col) final;



	/// @brief Draw rectangle
	/// @param x top-left x-coordinate
	/// @param y top-left y-coordinate
	/// @param w width
	/// @param h height
	/// @param col packed 16-bit color
	void FillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, ILIColor col) final;



	/// @brief Nop. For compat with Defer drivers
	inline void RenderPixels(uint16_t numBlocks=0) { (void)numBlocks; }



	/// @brief Nop. For compat with Defer drivers
	inline void RenderAllPixels() {}
};

}

#endif // ILI9341_IMMEDIATE_DRIVER_H
