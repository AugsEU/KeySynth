// ============================================================================
// Include
// ============================================================================
#include "GuiPage.h"



// ============================================================================
// GuiPage
// ============================================================================

// ============================================================================
// Core interface
// ============================================================================

void GuiPage::Update()
{
	uTimeMs start = millis();
	uTimeMs delta = start - mPrevUpdate;

	if(delta == 0)
	{
		return;
	}

	for(size_t i = 0; i < mElements.size(); ++i)
	{
		GuiElement* pElement = mElements[i];
		pElement->Update(start - mPrevUpdate, i == mSelectedElem);
	}

	mPrevUpdate = start;
}

void GuiPage::Draw()
{
	for(size_t i = 0; i < mElements.size(); ++i)
	{
		GuiElement* pElement = mElements[i];

		if(pElement->mFlags.isDirty)
		{
			pElement->Draw(i == mSelectedElem);
			pElement->mFlags.isDirty = false;
		}
	}
}

bool GuiPage::OnKeyPress(uint8_t keycode)
{
	bool elemStole = false;
	GuiElement* pElem = GetSelectedElement();
	if(pElem)
	{
		elemStole = pElem->OnKeyPress(keycode);
		if(!elemStole) // If the element didn't steal it try navigation
		{
			ElemId nextElem = pElem->GetNavigatedElement(keycode);
			if(nextElem != EMPTY_ID)
			{
				elemStole = true;
				SelectElem(nextElem);
				pElem->mFlags.isDirty = true;
			}
		}
	}

	return elemStole;
}

void GuiPage::InvalidateAll()
{
	// Force all elements to be dirty
	for(auto it : mElements)
	{
		it->mFlags.isDirty = true;
	}
}

// ============================================================================
// Utility
// ============================================================================

GuiElement* GuiPage::GetSelectedElement()
{
	if(mSelectedElem == EMPTY_ID)
	{
		return nullptr;
	}

	return mElements[mSelectedElem];
}

// ============================================================================
// Navigation
// ============================================================================

void GuiPage::SelectElem(ElemId id)
{
	// Need to mark these as dirty because they might have a different visual effect
	GuiElement* pCurr = GetElement(mSelectedElem);
	if(pCurr)
		pCurr->SetDirty();

	GuiElement* pNext = GetElement(id);
	if(pNext)
		pNext->SetDirty();

	mSelectedElem = id;
}

void GuiPage::LinkUpDown(ElemId low, ElemId high)
{
	GetElement(low)->SetUpNav(high);
	GetElement(high)->SetDownNav(low);
}

void GuiPage::LinkLeftRight(ElemId left, ElemId right)
{
	GetElement(left)->SetRightNav(right);
	GetElement(right)->SetLeftNav(left);
}

// ============================================================================
// Element creation
// ============================================================================
	
ElemId GuiPage::CreateCounterLabel(uint16_t x, uint16_t y, const char* text)
{
	GuiLabelCounter* newCounter =
		mElements.push_back<GuiLabelCounter>(x , y);
	AUG_ASSERT(newCounter, "GuiLblCter Fail");

	newCounter->mString = text;
	newCounter->mTextSize = 2;
	newCounter->mTextColor = 0x5555;

	return (uint8_t)(mElements.size()-1);
}