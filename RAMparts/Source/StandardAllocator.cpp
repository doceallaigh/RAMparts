#pragma region Library Includes
#include <cstdlib>
#pragma endregion

#pragma region Local Includes
#include "../Header/MemoryConstraints.hpp"
#include "../Header/StandardAllocator.hpp"
#pragma endregion

#pragma region Constants
#pragma endregion

#pragma region Static Fields
#pragma endregion

#pragma region Operators
#pragma endregion

#pragma region Custom Constructors
#pragma endregion

#pragma region Standard Constructors & Destructor
#pragma endregion

#pragma region Private Constructors
#pragma endregion

#pragma region Public Methods
void * StandardAllocator::Allocate(const MemoryConstraints& constraints) throw(std::bad_alloc)
{
    // TODO This should respect the other constraints set by the caller (or throw bad_alloc if they cannot be enforced)
    return malloc(constraints.MinimumSize);
}

bool StandardAllocator::TryDelete(void * pointer) noexcept
{
    try
    {
        free(pointer);
        return true;
    }
    catch (std::exception e)
    {
        return false;
    }
}
#pragma endregion

#pragma region Protected Methods
#pragma endregion

#pragma region Private Methods
#pragma endregion