// ============================================================================
// Include
// ============================================================================
#include "SubGeneralPage.h"

#include "Shared\SubParams.h"
#include "LocStrings.h"

// ============================================================================
// SubGeneralPage
// ============================================================================

/// @brief Constructor
SubGeneralPage::SubGeneralPage()
{
	mTuningId = CreateCounterLabel(20, 20, AugNumberParamToString(ASP_TUNING));
	mDriveId = CreateCounterLabel(20, 40, AugNumberParamToString(ASP_DRIVE));
	mGainId = CreateCounterLabel(20, 60, AugNumberParamToString(ASP_GAIN));

	// Setup nav
	LinkUpDown(mGainId, mDriveId);
	LinkUpDown(mDriveId, mTuningId);
	LinkUpDown(mTuningId, mGainId);
}

/// @brief Called once on opening
void SubGeneralPage::OnOpen()
{
	SelectElem(mTuningId);

	LoadSubValueToLabel(mTuningId, ASP_TUNING);
	LoadSubValueToLabel(mDriveId, ASP_DRIVE);
	LoadSubValueToLabel(mGainId, ASP_GAIN);
}

/// @brief Called when updating a frame
void SubGeneralPage::Update()
{
	GuiPage::Update();
}
