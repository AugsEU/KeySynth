// ============================================================================
// Stores max size of gui elements
// ----------------------------------------------------------------------------
// ============================================================================
// Include
// ============================================================================
#include <stdint.h>
#include <stddef.h>

#include "GuiLabel.h"


#ifndef GUI_ELEMENT_SIZE_H
#define GUI_ELEMENT_SIZE_H

constexpr size_t ELEMENT_MAX_SIZE = sizeof(GuiLabel);

// Add to this list
static_assert(ELEMENT_MAX_SIZE >= sizeof(GuiLabel));

#endif // GUI_ELEMENT_SIZE_H