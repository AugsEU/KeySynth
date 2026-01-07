// ============================================================================
// Include
// ============================================================================
#include <Arduino.h>
#include "USBHost_t36.h"




// ============================================================================
// Constants
// ============================================================================
#define SHOW_KEYBOARD_DATA





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
uint8_t gHeldModifiers = 0;  // try to keep a reasonable value



// ============================================================================
// Private Funcs
// ============================================================================

/// @brief Called on launch
void setup()
{
#ifdef SHOW_KEYBOARD_DATA
	while (!Serial) ; // wait for Arduino Serial Monitor
	Serial.println("\n\nUSB Host Keyboard forward and Testing");
	Serial.println(sizeof(USBHub), DEC);
#endif
	gUsbHost.begin();

	gUsbKeyboard.attachRawPress(OnRawPress);
	gUsbKeyboard.attachRawRelease(OnRawRelease);
}



/// @brief Called in a loop
void loop()
{
	gUsbHost.Task();
}




/// @brief Called when a key is pressed
void OnRawPress(uint8_t keycode) 
{
#ifdef SHOW_KEYBOARD_DATA
	Serial.print("OnRawPress keycode: ");
	Serial.print(keycode, HEX);
	Serial.print(" Modifiers: ");
	Serial.println(gHeldModifiers, HEX);
#endif
}



/// @brief Called on each key release
void OnRawRelease(uint8_t keycode)
{
#ifdef SHOW_KEYBOARD_DATA
	Serial.print("OnRawRelease keycode: ");
	Serial.print(keycode, HEX);
	Serial.print(" Modifiers: ");
	Serial.println(gUsbKeyboard.getModifiers(), HEX);
#endif
}