// ============================================================================
// Include
// ============================================================================
#include <Usart/RxFrontEnd.h>
#include <Shared/Shared.h>
#include <Voice.h>
#include <Parameters.h>

// ============================================================================
// Constants
// ============================================================================
constexpr size_t WRITE_HEAD_DETACHED = size_t(-1);

// ============================================================================
// Globals
// ============================================================================
uint8_t gMsgBuff[16];
size_t gMsgBuffWriteHead = WRITE_HEAD_DETACHED;

// ============================================================================
// Forward decl
// ============================================================================
MessageHeader GetCurrMessageHeader();
size_t GetMessageLength();
void HandleMessage(uint8_t* buf, size_t len);

// ============================================================================
// Public functions
// ============================================================================
void RxFrontEndBegin()
{
    AUSERIAL.begin(AUDIO_USART_BAUD_RATE);
}


void RxFrontEndPoll()
{
    int rxByte = AUSERIAL.read();
	if(rxByte != -1)
	{
		if(gMsgBuffWriteHead == WRITE_HEAD_DETACHED)
		{
			if(rxByte == MESSAGE_BEGIN) // Wait for message begin
			{
				gMsgBuffWriteHead = 0;
			}
		}
		else
		{
			gMsgBuff[gMsgBuffWriteHead++] = (uint8_t)rxByte;
			if(gMsgBuffWriteHead == GetMessageLength() && gMsgBuffWriteHead != 0)
            {
                HandleMessage(gMsgBuff, gMsgBuffWriteHead);
                gMsgBuffWriteHead = WRITE_HEAD_DETACHED;
            }
		}
	}
}

// ============================================================================
// Private functions
// ============================================================================
MessageHeader GetCurrMessageHeader()
{
    return (MessageHeader)gMsgBuff[0];
}

size_t GetMessageLength()
{
    switch (GetCurrMessageHeader())
    {
    case MessageHeader::NotifyOnline:
        return sizeof(MessageHeader);

    case MessageHeader::NotePress:
    case MessageHeader::NoteRelease:
    case MessageHeader::NoteOff:
        return sizeof(MessageHeader) + sizeof(uint8_t);

    case MessageHeader::SetParam:
        return sizeof(MessageHeader) + sizeof(uint8_t) + sizeof(float_t);

    default:
        break;
    }

    return 0;
}

void HandleMessage(uint8_t* buf, size_t len)
{
    float_t value = 0;
	switch (GetCurrMessageHeader())
    {
    case MessageHeader::NotifyOnline:
        // OK
        return;

    case MessageHeader::NotePress:
        BeginVoice(buf[1]);
        return;
    case MessageHeader::NoteRelease:
        ReleaseVoice(buf[1]);
        return;
    case MessageHeader::NoteOff:
        StopVoice(buf[1]);
        return;

    case MessageHeader::SetParam:
        memcpy((void*)&value, &buf[2], sizeof(float_t)); // need to copy because of alignment
        printf("Set [%u] %02x %02x %02x %02x\n", len, buf[2], buf[3], buf[4], buf[5]);
        SetFloatParam(buf[1], value);
        return;

    default: // Invalid header, ignore
        break;
    }
}