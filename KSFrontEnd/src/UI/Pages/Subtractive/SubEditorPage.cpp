// ============================================================================
// Include
// ============================================================================
#include "SubEditorPage.h"
#include <Usart\SynthParams.h>



// ============================================================================
// SubEditorPage
// ============================================================================

void SubEditorPage::LoadSubValueToLabel(ElemId id, AugCSynth::Subtractive::SubParameter param)
{
	auto* pCounter = GetElement<GuiLabelCounter>(id);

	AugCSynth::SynthParamBounds bounds = AugCSynth::Subtractive::GetSubParamBounds(param);
	pCounter->mMaxValue = bounds.GetMaxValue();
	pCounter->mMinValue = bounds.GetMinValue();
	pCounter->mValue = GetSynthParamValue((size_t)param);
}
