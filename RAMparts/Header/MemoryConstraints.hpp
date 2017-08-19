#pragma once

#pragma region Library Includes
#include <limits>
#pragma endregion

#pragma region Local Includes
#pragma endregion

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief A POD wrapper for memory allocation requirement parameters
* */
typedef struct MemoryConstraints
{
public:
    size_t MinimumSize = 1U;
    size_t MinimumAlignment = alignof(std::max_align_t);
    size_t MaximumSize = std::numeric_limits<size_t>::max();
    size_t MaximumAlignment = alignof(std::max_align_t);

    bool operator ==(const MemoryConstraints& other) const
    {
        return this->MinimumSize == other.MinimumSize &&
            this->MinimumAlignment == other.MinimumAlignment &&
            this->MaximumSize == other.MaximumSize &&
            this->MaximumAlignment == other.MaximumAlignment;
    }
} MemoryConstraints;

namespace std
{
    template<>
    struct hash<const MemoryConstraints>
    {
        std::size_t operator()(const MemoryConstraints& constraints) const
        {
            // TODO Implement this
            return 0;
        }
    };
}