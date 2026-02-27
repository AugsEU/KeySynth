// ============================================================================
// ILI9341 display driver code parallel interface meant for teensy 4.1
// ----------------------------------------------------------------------------
// ============================================================================
// Include
// ============================================================================
#include <Arduino.h>
#include <optional>

#ifndef ILI9341_PARALLEL_H
#define ILI9341_PARALLEL_H
// ============================================================================
// Public constants
// ============================================================================
#define ILI9341_WIDTH 240
#define ILI9341_HEIGHT 320



// ============================================================================
// T4_ILI9341
// ============================================================================
class T4_ILI9341
{
public:
    constexpr static int WIDTH = 240;
    constexpr static int HEIGHT = 320;

    // Init
    T4_ILI9341(uint8_t cs, uint8_t cd, uint8_t wr, uint8_t rd);

    // Command functions are named based off the datasheet. Many of this inconsistent but oh well...
    // e.g. some are "get" some are "read", some have "read" at the start, others at the end...
    // Level 1 commands
    

private:
    void BeginData();
    void BeginCommand();
    void SelectChip();
    void UnselectChip();

    void WriteBus8(uint8_t wr);
    void Cmd8Data24(uint8_t cmd, uint32_t data);
    void Cmd8Data32(uint8_t cmd, uint32_t data);

    uint8_t mPinCS = 0xFF; // Chip select
    uint8_t mPinCD = 0xFF; // Data/Command pin
    uint8_t mPinWrite = 0xFF;
    uint8_t mPinRead = 0xFF;
};
#endif //ILI9341_PARALLEL_H
