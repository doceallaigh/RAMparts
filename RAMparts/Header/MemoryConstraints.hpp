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

/*! \brief <Brief description goes here>
*
* <Detailed description goes here>
* */
typedef struct MemoryConstraints
{
public:
    size_t MinimumSize = 1U;
    size_t MaximumSize = std::numeric_limits<size_t>::max();
    size_t MinimumAlignment = alignof(std::max_align_t);
    size_t MaximumAlignment = alignof(std::max_align_t);
} MemoryConstraints;