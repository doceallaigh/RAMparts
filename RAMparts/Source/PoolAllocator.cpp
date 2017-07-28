// INCLUDES
#pragma region Library Includes
#include <limits>
#include <memory>
#pragma endregion

#pragma region Local Includes
#include "../Header/PoolAllocator.hpp"
#pragma endregion

#pragma region Constants
const size_t tombstoneFlag = (std::numeric_limits<size_t>::max () / 2) + 1;
#pragma endregion

#pragma region Public Constructors & Destructor
// DEFAULT CONSTRUCTOR

// COPY CONSTRUCTOR
// PoolAllocator::PoolAllocator (const PoolAllocator &original) { }

// MOVE CONSTRUCTOR
// PoolAllocator::PoolAllocator (const PoolAllocator &&original) noexcept { }

// CUSTOM CONSTRUCTORS
PoolAllocator::PoolAllocator(const std::shared_ptr<PoolAllocatorConfig> config, std::shared_ptr<IMemoryPool> memoryPool) 
    : ConfiguredAllocator (config), 
    memoryPool (memoryPool)
{
    // TODO HIGH The memory pool should be made here (possibly with a generator) rather than passed in
}

// DESTRUCTOR
PoolAllocator::~PoolAllocator (void) noexcept 
{
    this->memoryPool.reset ();
}
#pragma endregion

#pragma region Operators
// COPY ASSIGNEMENT OPERATOR
// PoolAllocator& PoolAllocator::operator= (const PoolAllocator &original) { }

// MOVE ASSIGNEMENT OPERATOR
// PoolAllocator& PoolAllocator::operator= (PoolAllocator &&original) noexcept { }
#pragma endregion

#pragma region Public Virtual Methods
// PURE VIRTUAL METHODS
// VIRTUAL METHODS
#pragma endregion

#pragma region Public Non-virtual Methods
// NON-VOID METHODS
void * PoolAllocator::Allocate (size_t size) throw (std::bad_alloc)
{
    // TODO Implement
    return nullptr;
}

// VOID METHODS
void PoolAllocator::Delete (void * object)
{
    // TODO Implement
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
// PoolAllocator (void);
#pragma endregion

#pragma region Private Virtual Methods
// PURE VIRTUAL METHODS
// VIRTUAL METHODS
#pragma endregion

#pragma region Private Non-virtual Methods
// NON-VOID METHODS
// VOID METHODS
#pragma endregion