// ============================================================================
// Include
// ============================================================================
#include "SubLfoPage.h"


// ============================================================================
// Class
// ============================================================================

SubLfoPage::SubLfoPage()
{
	GuiLabel* pLabel = mElements.push_back<GuiLabel>(50, 50);
	pLabel->mString = "SubLfoPage";
	pLabel->mTextColor = 0xFFFF;
	pLabel->mTextSize = 3;
}

void SubLfoPage::OnOpen(GuiPageType openType)
{

}

void SubLfoPage::Update()
{

}