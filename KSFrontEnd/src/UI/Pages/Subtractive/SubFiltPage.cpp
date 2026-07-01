// ============================================================================
// Include
// ============================================================================
#include "SubFiltPage.h"


// ============================================================================
// Class
// ============================================================================

SubFiltPage::SubFiltPage()
{
	GuiLabel* pLabel = mElements.push_back<GuiLabel>(50, 50);
	pLabel->mString = "SubFiltPage";
	pLabel->mTextColor = 0xFFFF;
	pLabel->mTextSize = 3;
}

void SubFiltPage::OnOpen()
{

}

void SubFiltPage::Update()
{

}