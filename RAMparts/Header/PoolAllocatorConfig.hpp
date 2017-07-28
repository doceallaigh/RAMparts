/* PoolAllocatorConfig.hpp
 * Class description:
 *     <PoolAllocatorConfig description goes here>
 * * */

#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#include "MemoryPoolConfig.hpp"
#include "AllocatorConfig.hpp"
#pragma endregion

#ifndef PoolAllocatorConfig_hpp
#define PoolAllocatorConfig_hpp

#pragma region Forward Declarations
#pragma endregion

typedef struct PoolAllocatorConfig : AllocatorConfig
{
public:
    MemoryPoolConfig PoolConfig;
} PoolAllocatorConfig;
#endif // !PoolAllocatorConfig_hpp