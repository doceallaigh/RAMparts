#pragma region Library Includes
#include <limits>
#include <memory>
#pragma endregion

#pragma region Local Includes
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
    // TODO Implement
    return nullptr;
}

bool PoolAllocator::TryDelete(void * object) noexcept
{
    // TODO Implement
    return false;
}
#pragma endregion

#pragma region Protected Methods
#pragma endregion

#pragma region Private Methods
#pragma endregion