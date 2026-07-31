#include <stddef.h>

namespace AugCLib {

/// @brief Get size of consecutive enum
/// @tparam T Enum type
/// @return Size of consecutive enum
template<typename T>
constexpr size_t Count()
{
    return static_cast<size_t>(T::Count);
}

}