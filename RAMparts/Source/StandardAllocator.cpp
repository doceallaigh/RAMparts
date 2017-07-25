// INCLUDES
#pragma region Library Includes
#include <cstdlib>
#pragma endregion

#pragma region Local Includes
#include "../Header/StandardAllocator.hpp"
#pragma endregion

#pragma region Public Constructors & Destructor
// DEFAULT CONSTRUCTOR
// StandardAllocator::StandardAllocator (void) { }

// COPY CONSTRUCTOR
// StandardAllocator::StandardAllocator (const StandardAllocator &original) { }

// MOVE CONSTRUCTOR
// StandardAllocator::StandardAllocator (const StandardAllocator &&original) noexcept { }

// DESTRUCTOR
// StandardAllocator::~StandardAllocator (void) noexcept { }
#pragma endregion

#pragma region Operators
// COPY ASSIGNEMENT OPERATOR
// StandardAllocator& StandardAllocator::operator= (const StandardAllocator &original) { }

// MOVE ASSIGNEMENT OPERATOR
// StandardAllocator& StandardAllocator::operator= (StandardAllocator &&original) noexcept { }
#pragma endregion

#pragma region Public Virtual Methods
// PURE VIRTUAL METHODS
// VIRTUAL METHODS
#pragma endregion

#pragma region Public Non-virtual Methods
// NON-VOID METHODS
void * StandardAllocator::Allocate (size_t size)
{
    return malloc (size);
}

// VOID METHODS
void StandardAllocator::Delete (void * pointer)
{
    free (pointer);
}
#pragma endregion

#pragma region Protected Virtual Methods
// PURE VIRTUAL METHODS
// VIRTUAL METHODS
#pragma endregion

#pragma region Protected Non-virtual Methods
// NON-VOID METHODS
// VOID METHODS
#pragma endregion

#pragma region Private Constructors
// DEFAULT CONSTRUCTOR
// StandardAllocator (void);
#pragma endregion

#pragma region Private Virtual Methods
// PURE VIRTUAL METHODS
// VIRTUAL METHODS
#pragma endregion

#pragma region Private Non-virtual Methods
// NON-VOID METHODS
// VOID METHODS
#pragma endregion