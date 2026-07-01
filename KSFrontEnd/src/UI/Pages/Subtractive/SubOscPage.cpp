// ============================================================================
// Include
// ============================================================================
#include "SubOscPage.h"


// ============================================================================
// Class
// ============================================================================

SubOscPage::SubOscPage()
{
	GuiLabel* pLabel = mElements.push_back<GuiLabel>(50, 50);
	pLabel->mString = "SubOscPage";
	pLabel->mTextColor = 0xFFFF;
	pLabel->mTextSize = 3;
}

void SubOscPage::OnOpen()
{

}

void SubOscPage::Update()
{

}