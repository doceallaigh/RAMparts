#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#include "AllocatorConfig.hpp"
#include "MemoryPoolConfig.hpp"
#pragma endregion

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief A POD object for configuring allocator traits specific to constant memory pool allocators
* */
template <typename TPoolConfig>
class PoolAllocatorConfig : AllocatorConfig
{
public:
    static_assert(std::is_base_of<MemoryPoolConfig, TPoolConfig>(), "Type must inherit from MemoryPoolConfig");
    TPoolConfig PoolConfig;
};