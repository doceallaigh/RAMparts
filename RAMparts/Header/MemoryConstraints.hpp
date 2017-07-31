/* MemoryConstraints.hpp
 * Class description:
 *     <MemoryConstraints description goes here>
 * * */

#pragma once

#pragma region Library Includes
#include <limits>
#pragma endregion

#pragma region Local Includes
#pragma endregion

#ifndef MemoryConstraints_hpp
#define MemoryConstraints_hpp

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

struct MemoryConstraints 
{
public:
    size_t MinimumSize = 1U;
    size_t MaximumSize = std::numeric_limits<size_t>::max();
    size_t MinimumAlignment = alignof(std::max_align_t);
    size_t MaximumAlignment = alignof(std::max_align_t);
};
#endif // !MemoryConstraints_hpp