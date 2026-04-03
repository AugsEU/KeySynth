// ============================================================================
// Utilities to transmit to the audio backend
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <Arduino.h>



// ============================================================================
// Public globals
// ============================================================================
#define AUSERIAL Serial3

// ============================================================================
// Public functions
// ============================================================================
void TxBackendBegin();

void TxBackendNotePress(uint8_t noteNum);
void TxBackendNoteRelease(uint8_t noteNum);
void TxBackendNoteOff(uint8_t noteNum);
void TxBackendSetParam(uint8_t paramNum, float_t paramValue);
