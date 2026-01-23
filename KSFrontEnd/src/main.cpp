// ============================================================================
// Include
// ============================================================================
#include <Arduino.h>
#include "USBHost_t36.h"

#include <Midi/NoteMaps.h>



// ============================================================================
// Constants
// ============================================================================
#define SHOW_KEYBOARD_DATA 0





// ============================================================================
// Forward decl
// ============================================================================
void OnPress(int key);
void OnRawPress(uint8_t keycode);
void OnRawRelease(uint8_t keycode);





// ============================================================================
// Globals
// ============================================================================
USBHost gUsbHost;
KeyboardController gUsbKeyboard(gUsbHost);
USBHIDParser gHidParser(gUsbHost);





// ============================================================================
// Private Funcs
// ============================================================================

/// @brief Called on launch
void setup()
{
	gUsbHost.begin();
	Serial3.begin(115200);

	gUsbKeyboard.attachRawPress(OnRawPress);
	gUsbKeyboard.attachRawRelease(OnRawRelease);
	gUsbKeyboard.forceHIDProtocol();
}



/// @brief Called in a loop
void loop()
{
	gUsbHost.Task();
}




/// @brief Called when a key is pressed
void OnRawPress(uint8_t keycode) 
{
#if SHOW_KEYBOARD_DATA
	Serial.print("OnRawPress keycode: ");
	Serial.println(keycode, HEX);
#endif

	uint8_t noteNum = KeyCodeToNoteNum(keycode, NoteLayout::Isometric);

	Serial3.write(0xAB);
	Serial3.write(noteNum);
	Serial3.write(0xBA);
}



/// @brief Called on each key release
void OnRawRelease(uint8_t keycode)
{
#if SHOW_KEYBOARD_DATA
	Serial.print("OnRawRelease keycode: ");
	Serial.println(keycode, HEX);
#endif
}