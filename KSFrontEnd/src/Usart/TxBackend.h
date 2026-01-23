// ============================================================================
// Utilities to transmit to the audio backend
// ----------------------------------------------------------------------------
// ============================================================================
// Include
// ============================================================================
#include <Arduino.h>


#ifndef TX_BACKEND_H
#define TX_BACKEND_H
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

#endif // TX_BACKEND_H