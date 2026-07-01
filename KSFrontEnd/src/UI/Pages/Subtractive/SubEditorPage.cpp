// ============================================================================
// Include
// ============================================================================
#include "SubEditorPage.h"
#include <Usart\SynthParams.h>

// ============================================================================
// SubEditorPage
// ============================================================================

void SubEditorPage::LoadSubValueToLabel(ElemId id, uint8_t paramNum)
{
	auto* pCounter = GetElement<GuiLabelCounter>(id);

	pCounter->mMaxValue = gSynthParamBounds[paramNum].GetMaxValue();
	pCounter->mMinValue = gSynthParamBounds[paramNum].GetMinValue();
	pCounter->mValue = GetSynthParamValue(paramNum);
}
