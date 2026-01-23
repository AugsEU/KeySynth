// ============================================================================
// Include
// ============================================================================
#include "TxBackend.h"
#include "Shared/Shared.h"




// ============================================================================
// Constants
// ============================================================================

// ============================================================================
// Globals
// ============================================================================

// ============================================================================
// Forward decl
// ============================================================================
void BeginMessage(MessageHeader header);
void EndMessage();

// ============================================================================
// Public functions
// ============================================================================
void TxBackendBegin()
{
    AUSERIAL.begin(AUDIO_USART_BAUD_RATE);
    BeginMessage(MessageHeader::NotifyOnline);
    EndMessage();
}

void TxBackendNotePress(uint8_t noteNum)
{
    BeginMessage(MessageHeader::NotePress);

    AUSERIAL.write(noteNum);

    EndMessage();
}

void TxBackendNoteRelease(uint8_t noteNum)
{
    BeginMessage(MessageHeader::NoteRelease);
 
    AUSERIAL.write(noteNum);

    EndMessage();
}

void TxBackendNoteOff(uint8_t noteNum)
{
    BeginMessage(MessageHeader::NoteOff);
    
    AUSERIAL.write(noteNum);

    EndMessage();
}

void TxBackendSetParam(uint8_t paramNum, float_t paramValue)
{
    const uint8_t* paramBytes = reinterpret_cast<const uint8_t*>(&paramValue);
    
    BeginMessage(MessageHeader::SetParam);
    
    AUSERIAL.write(paramNum);
    AUSERIAL.write(paramBytes, sizeof(float_t));

    EndMessage();
}





// ============================================================================
// Private functions
// ============================================================================
void BeginMessage(MessageHeader header)
{
    AUSERIAL.write(MESSAGE_BEGIN);
    AUSERIAL.write(header);
}

void EndMessage()
{
    // ToDo: Send finaliser?

    // Wait a bit so the backend can digest and avoid clobbering it.
    delayMicroseconds(10);
}

// ============================================================================
// Class
// ============================================================================