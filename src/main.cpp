#include <Arduino.h>

constexpr uint8_t LED_PIN = 13;

void setup()
{
	pinMode(LED_PIN, OUTPUT);
}

bool gLedOn = false;
void loop()
{
	delay(20);
	digitalWrite(LED_PIN, gLedOn);
	gLedOn = !gLedOn;
}
