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

/*! \brief <Brief description goes here>
*
* <Detailed description goes here>
* */
typedef struct PoolAllocatorConfig : AllocatorConfig
{
public:
    MemoryPoolConfig PoolConfig;
} PoolAllocatorConfig;