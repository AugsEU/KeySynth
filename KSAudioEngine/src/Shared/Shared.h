// ============================================================================
// Shared data between the front end and backend
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <Arduino.h>
#include "Shared/SubParams.h"


// ============================================================================
// Constants
// ============================================================================
constexpr int AUDIO_USART_BAUD_RATE = 31250;
constexpr uint8_t MESSAGE_BEGIN = 0xAB;
constexpr uint32_t SAMPLE_RATE = 48000;

constexpr size_t NUM_PARAMETERS = ASP_NUM_PARAMS;



// ============================================================================
// Types
// ============================================================================
enum MessageHeader : uint8_t
{
    NotePress = 0x81,   // Note is pressed (begin playing?)
    NoteRelease = 0x82, // Note is released, do release env
    NoteOff = 0x83,     // Turn this off now!
    SetParam = 0x84,    // Set a parameter
	SetMode = 0x85,		// Change which engine we are using.
    NotifyOnline = 0xFF // We are awake
};

enum class SynthMode : uint8_t
{
	Subtractive = 0x00
};

struct SynthParameter
{
	union
	{
		float mFloatValue;
		uint32_t mIntValue;
	};
};
