// ============================================================================
// Include
// ============================================================================
#include "SubDelayPage.h"


// ============================================================================
// Class
// ============================================================================

SubDelayPage::SubDelayPage()
{
	GuiLabel* pLabel = mElements.push_back<GuiLabel>(50, 50);
	pLabel->mString = "SubDelayPage";
	pLabel->mTextColor = 0xFFFF;
	pLabel->mTextSize = 3;
}

void SubDelayPage::OnOpen()
{

}

void SubDelayPage::Update()
{

}