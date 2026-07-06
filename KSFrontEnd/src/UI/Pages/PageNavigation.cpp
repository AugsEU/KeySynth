// ============================================================================
// Include
// ============================================================================
#include "PageNavigation.h"

#include <Screen/ScreenDisplay.h>

// ============================================================================
// Macros
// ============================================================================
#define SET_START_PAGE(cat, page) gActivePageTypes[(size_t)cat] = page;

// ============================================================================
// Private types
// ============================================================================

enum class PageCategory : size_t
{
	General = 0,
	Subtractive,
	NumCategories
};


// ============================================================================
// Global variables
// ============================================================================
PageCategory gCurrCategory = PageCategory::General;
GuiPageType gActivePageTypes[(size_t)PageCategory::NumCategories];


// ============================================================================
// Pre decl
// ============================================================================
bool NavigateCategory(uint8_t keycode);
bool SwitchCategory(PageCategory category);
PageCategory GetCategory(GuiPageType pageType);

// ============================================================================
// Public functions
// ============================================================================

void InitialisePageNavigation()
{
	SET_START_PAGE(PageCategory::General, GuiPageType::Home);
	SET_START_PAGE(PageCategory::Subtractive, GuiPageType::SubGeneral);

	gCurrCategory = PageCategory::General;
	SelectUiPage(GuiPageType::Home);
}

bool NavigatePage(uint8_t keycode)
{
	bool pageUp = keycode == KS_KEYCODE_PG_UP;
	bool pageDown = keycode == KS_KEYCODE_PG_DOWN;

	// Check if we steal the category
	if(NavigateCategory(keycode))
	{
		return true;
	}

	GuiPageType currPage = GetCurrentUiPageType();
	size_t currPageIdx = (size_t)currPage;
	if(pageUp)
	{
		GuiPageType nextPage = (GuiPageType)(currPageIdx + 1);
		if (nextPage != GuiPageType::NumGuiPages)
		{
			PageCategory nextCat = GetCategory(nextPage);
			if(nextCat == gCurrCategory) // Make sure we stay in the category
			{
				SelectUiPage(nextPage);
				return true;
			}
		}
	}
	else if(pageDown)
	{
		if(currPageIdx > 0)
		{
			GuiPageType prevPage = (GuiPageType)(currPageIdx - 1);
			PageCategory prevCat = GetCategory(prevPage);
			if(prevCat == gCurrCategory) // Make sure we stay in the category
			{
				SelectUiPage(prevPage);
				return true;
			}
		}
	}

	return false;
}


// ============================================================================
// Private functions
// ============================================================================

bool NavigateCategory(uint8_t keycode)
{
	switch (keycode)
	{
	case KS_KEYCODE_F1:
		return SwitchCategory(PageCategory::General);
	case KS_KEYCODE_F2:
		return SwitchCategory(PageCategory::Subtractive);
	default:
		break;
	}

	return false;
}

bool SwitchCategory(PageCategory category)
{
	if(category != gCurrCategory)
	{
		gCurrCategory = category;

		GuiPageType nextPage = gActivePageTypes[(size_t)gCurrCategory];
		SelectUiPage(nextPage);
	}

	return true;
}

PageCategory GetCategory(GuiPageType pageType)
{
	switch (pageType)
	{
	case GuiPageType::Home:
		return PageCategory::General;
	case GuiPageType::SubGeneral:
	case GuiPageType::SubOsc1:
	case GuiPageType::SubOsc2:
	case GuiPageType::SubEnv1:
	case GuiPageType::SubEnv2:
	case GuiPageType::SubFilt:
	case GuiPageType::SubLfo:
	case GuiPageType::SubDelay:
		return PageCategory::Subtractive;
	case GuiPageType::NumGuiPages:
		break;
	}

	AUG_LOG("Nocat%d", pageType);
	return (PageCategory)-1;
}