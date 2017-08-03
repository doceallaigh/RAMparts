#pragma region Library Includes
#include <cstdlib>
#pragma endregion

#pragma region Local Includes
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
void * StandardAllocator::Allocate(size_t size)
{
    return malloc(size);
}

void StandardAllocator::Delete(void * pointer)
{
    free(pointer);
}
#pragma endregion

#pragma region Protected Methods
#pragma endregion

#pragma region Private Methods
#pragma endregion