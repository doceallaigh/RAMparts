#pragma once

#pragma region Library Includes
#include <cstddef>
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
typedef struct AllocatorConfig
{
public:
    size_t MaximumAlignment = alignof(std::max_align_t);
    size_t DefaultAlignment = alignof(std::max_align_t);
} AllocatorConfig;