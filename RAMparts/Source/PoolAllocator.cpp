#pragma region Library Includes
#include <limits>
#include <memory>
#pragma endregion

#pragma region Local Includes
#include "../Header/Interfaces/IMemoryBlock.hpp"
#include "../Header/Interfaces/IMemorySelector.hpp"
#include "../Header/Interfaces/IMemoryReservationTracker.hpp"
#include "../Header/MemoryConstraints.hpp"
#include "../Header/PoolAllocator.hpp"
#include "../Header/PoolAllocatorConfig.hpp"
#pragma endregion

#pragma region Constants
const size_t tombstoneFlag = (std::numeric_limits<size_t>::max() / 2) + 1;
#pragma endregion

#pragma region Static Fields
#pragma endregion

#pragma region Operators
#pragma endregion

#pragma region Custom Constructors
PoolAllocator::PoolAllocator(const std::shared_ptr<PoolAllocatorConfig> config, std::shared_ptr<PoolAllocatorDependencyPack> dependencyPack)
    : ConfiguredAllocator(config),
    dependencyPack(dependencyPack)
{
}
#pragma endregion

#pragma region Standard Constructors & Destructor
#pragma endregion

#pragma region Private Constructors
#pragma endregion

#pragma region Public Methods
void * PoolAllocator::Allocate(const MemoryConstraints& constraints) throw(std::bad_alloc)
{
    auto memoryPool = this->dependencyPack->MemoryPool;
    auto memorySelector = this->dependencyPack->MemorySelector;
    auto memoryReservationTracker = this->dependencyPack->ReservationTracker;

    auto memoryBlock = memorySelector->SelectMemorySatisfyingConstraints(constraints);
    
    if(memoryReservationTracker->TryReserve(*memoryBlock))
    {
        return memoryBlock->GetAddress();
    }

    return nullptr;
}

bool PoolAllocator::TryDelete(void * pointer) noexcept
{
    auto memoryPool = this->dependencyPack->MemoryPool;
    auto memorySelector = this->dependencyPack->MemorySelector;
    auto memoryReservationTracker = this->dependencyPack->ReservationTracker;

    auto memoryReservationMap = memoryReservationTracker->GetReservedMemoryMap();
    auto memoryBlock = memoryReservationMap[pointer];

    if (memoryBlock)
    {
        return memoryReservationTracker->TryUnreserve(*memoryBlock);
    }

    return false;
}
#pragma endregion

#pragma region Protected Methods
#pragma endregion

#pragma region Private Methods
#pragma endregion