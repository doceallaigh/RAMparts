// INCLUDES
#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#include "../Header/Interfaces/IMemoryBlock.hpp"
#include "../Header/Interfaces/IMemoryIterator.hpp"
#include "../Header/MemoryConstraints.hpp"
#include "../Header/PartitionedMemoryPool.hpp"
#pragma endregion

#pragma region Constants
#pragma endregion

#pragma region Operators
#pragma endregion

#pragma region Custom Constructors
PartitionedMemoryPool::PartitionedMemoryPool(const std::shared_ptr<MemoryPoolConfig> config)
    : MemoryPool(config)
{
}
#pragma endregion

#pragma region Standard Constructors & Destructor
#pragma endregion

#pragma region Private Constructors
#pragma endregion

#pragma region Public Methods
std::shared_ptr<IMemoryIterator> PartitionedMemoryPool::GetMemoryIterator(void) const
{
    return std::shared_ptr<IMemoryIterator>();
}

std::vector<IMemoryBlock> PartitionedMemoryPool::GetOverlappingBlocks(const IMemoryBlock & pointer) const
{
    return std::vector<IMemoryBlock>();
}
#pragma endregion

#pragma region Protected Methods
#pragma endregion

#pragma region Private Methods
#pragma endregion