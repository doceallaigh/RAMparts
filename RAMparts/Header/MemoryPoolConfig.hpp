/* MemoryPoolConfig.hpp
 * Class description:
 *     <MemoryPoolConfig description goes here>
 * * */

#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#pragma endregion

#ifndef MemoryPoolConfig_hpp
#define MemoryPoolConfig_hpp

#pragma region Forward Declarations
#pragma endregion

typedef struct MemoryPoolConfig 
{
public:
    size_t PoolSize;
    size_t PageSize;
} MemoryPoolConfig;
#endif // !MemoryPoolConfig_hpp