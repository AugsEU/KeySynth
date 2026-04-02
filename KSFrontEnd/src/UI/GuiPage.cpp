// ============================================================================
// Include
// ============================================================================
#include "GuiPage.h"



// ============================================================================
// GuiPage
// ============================================================================
void GuiPage::Update()
{
	uTimeMs start = millis();
	uTimeMs delta = start - mPrevUpdate;

	if(delta == 0)
	{
		return;
	}

	for(int i = 0; i < mElements.size(); ++i)
	{
		GuiElement* pElement = mElements[i];
		pElement->Update(start - mPrevUpdate, i == mSelectedElementIndex);
	}

	mPrevUpdate = start;
}


void GuiPage::Draw()
{
	for(int i = 0; i < mElements.size(); ++i)
	{
		GuiElement* pElement = mElements[i];
		pElement->Draw(i == mSelectedElementIndex);
	}
}