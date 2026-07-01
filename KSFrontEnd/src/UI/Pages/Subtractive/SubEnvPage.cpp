// ============================================================================
// Include
// ============================================================================
#include "SubEnvPage.h"


// ============================================================================
// Class
// ============================================================================

SubEnvPage::SubEnvPage()
{
	GuiLabel* pLabel = mElements.push_back<GuiLabel>(50, 50);
	pLabel->mString = "SubEnvPage";
	pLabel->mTextColor = 0xFFFF;
	pLabel->mTextSize = 3;
}

void SubEnvPage::OnOpen()
{

}

void SubEnvPage::Update()
{

}