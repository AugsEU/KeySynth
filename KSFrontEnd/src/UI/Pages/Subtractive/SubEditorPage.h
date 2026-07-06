// ============================================================================
// Base class for subtractive synth edit pages
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <UI/GuiPage.h>
#include <Usart/SynthParams.h>

// ============================================================================
// Macros
// ============================================================================

#define SEND_COUNTER_TO_SYNTH(id, param) \
	ON_ELEM_CHANGE(id, GuiLabelCounter, \
	{ \
		SendParamForSubtractive(param, elem->mValue); \
	});

// ============================================================================
// SubEditorPage
// ============================================================================
class SubEditorPage : public GuiPage
{
protected:
	/// @brief Load a subtractive synth param into label
	/// @param id 
	/// @param paramNum 
	void LoadSubValueToLabel(ElemId id, uint8_t paramNum);
};