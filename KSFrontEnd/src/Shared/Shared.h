// ============================================================================
// Shared data between the front end and backend
// ----------------------------------------------------------------------------
// ============================================================================
// Include
// ============================================================================
#include <Arduino.h>


#ifndef SHARED_H
#define SHARED_H
// ============================================================================
// Constants
// ============================================================================
constexpr int AUDIO_USART_BAUD_RATE = 115200;
constexpr uint8_t MESSAGE_BEGIN = 0xAB;





// ============================================================================
// Types
// ============================================================================
enum MessageHeader : uint8_t
{
    NotePress = 0x81,   // Note is pressed (begin playing?)
    NoteRelease = 0x82, // Note is released, do release env
    NoteOff = 0x83,     // Turn this off now!
    SetParam = 0x84,    // Set a parameter
    NotifyOnline = 0xFF // We are awake
};

#endif // SHARED_H