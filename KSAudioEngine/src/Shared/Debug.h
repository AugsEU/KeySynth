// ============================================================================
// Debug macros
// ----------------------------------------------------------------------------
#pragma once

#define AUG_DEBUG_ENABLED 1

#if AUG_DEBUG_ENABLED

#define AUG_LOG(fmt, ...) \
	printf("AUG_LOG[%x] " fmt "\n", (unsigned int)__LINE__, ##__VA_ARGS__)

#define AUG_ASSERT(cond, fmt, ...) \
	do { \
		if(!cond) \
			AUG_LOG("Condtion failed" #cond fmt, ##__VA_ARGS__); \
	} while(false) \

#else // AUG_DEBUG_ENABLED
#define AUG_ASSERT(...) do{}while(false)
#endif // AUG_DEBUG_ENABLED

