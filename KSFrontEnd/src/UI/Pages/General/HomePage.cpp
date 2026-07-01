// ============================================================================
// Include
// ============================================================================
#include "HomePage.h"


// ============================================================================
// Class
// ============================================================================

HomePage::HomePage()
{
	GuiLabel* pLabel = mElements.push_back<GuiLabel>(50, 50);
	pLabel->mString = "HomePage";
	pLabel->mTextColor = 0xFFFF;
	pLabel->mTextSize = 3;
}

void HomePage::OnOpen()
{

}

void HomePage::Update()
{

}