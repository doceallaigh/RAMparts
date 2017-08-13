#pragma once

#pragma region Library Includes
#include <map>
#pragma endregion

#pragma region Local Includes
#include "MemoryConstraints.hpp"
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
typedef struct PartitionedMemoryPoolConfig : MemoryPoolConfig
{
public:
    std::map<const MemoryConstraints, float> PartitionRatios;
} PartitionedMemoryPoolConfig;