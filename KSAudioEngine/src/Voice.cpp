// ============================================================================
// Include
// ============================================================================
#include <Voice.h>
#include <Tuning.h>
#include <I2S/AudioConfig.h>

// ============================================================================
// Globals
// ============================================================================
Voice gVoices[VOICE_POLYPHONY];
size_t gFreeNoteSearchStart = 0;




// ============================================================================
// Forward decl
// ============================================================================





// ============================================================================
// Voice
// ============================================================================
bool Voice::CanBeAllocated()
{
    return mNoteNum == INVALID_NOTE;
}





// ============================================================================
// Public functions
// ============================================================================
void BeginVoice(uint8_t note)
{
    for(size_t i = gFreeNoteSearchStart; i < VOICE_POLYPHONY; i++)
    {
        Voice& newVoice = gVoices[i];
        if(newVoice.mNoteNum == INVALID_NOTE)
        {
            newVoice.mPhaseShift = NoteToFreq(note + 48) / SAMPLERATE;
            newVoice.mNoteNum = note;
            gFreeNoteSearchStart = i + 1;
            break;
        }       
    }
}

void ReleaseVoice(uint8_t note)
{
    for(int i = 0; i < VOICE_POLYPHONY; i++)
    {
        if(gVoices[i].mNoteNum == note)
        {
            // ToDo Release correctly
            gVoices[i].mNoteNum = INVALID_NOTE;
            gFreeNoteSearchStart = min(i, gFreeNoteSearchStart);
            return;
        }       
    }
}

void StopVoice(uint8_t note)
{
    for(int i = 0; i < VOICE_POLYPHONY; i++)
    {
        if(gVoices[i].mNoteNum == note)
        {
            // ToDo Release correctly
            gVoices[i].mNoteNum = INVALID_NOTE;
            gFreeNoteSearchStart = min(i, gFreeNoteSearchStart);
            return;
        }       
    }
}

// ============================================================================
// Private functions
// ============================================================================
