// INCLUDES
#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#include "../Header/PartitionedMemoryPool.hpp"
#pragma endregion

#pragma region Public Constructors & Destructor
// DEFAULT CONSTRUCTOR
// PartitionedMemoryPool::PartitionedMemoryPool (void) { }

// CUSTOM CONSTRUCTORS
PartitionedMemoryPool::PartitionedMemoryPool (const std::shared_ptr<MemoryPoolConfig> config) 
: MemoryPool(config)
{
    
}

// COPY CONSTRUCTOR
// PartitionedMemoryPool::PartitionedMemoryPool (const PartitionedMemoryPool &original) { }

// MOVE CONSTRUCTOR
// PartitionedMemoryPool::PartitionedMemoryPool (const PartitionedMemoryPool &&original) noexcept { }

// DESTRUCTOR
PartitionedMemoryPool::~PartitionedMemoryPool (void) noexcept { }
#pragma endregion

#pragma region Operators
// COPY ASSIGNEMENT OPERATOR
// PartitionedMemoryPool& PartitionedMemoryPool::operator= (const PartitionedMemoryPool &original) { }

// MOVE ASSIGNEMENT OPERATOR
// PartitionedMemoryPool& PartitionedMemoryPool::operator= (PartitionedMemoryPool &&original) noexcept { }
#pragma endregion

#pragma region Public Virtual Methods
// PURE VIRTUAL METHODS
// VIRTUAL METHODS
void * PartitionedMemoryPool::GetMemory (size_t size)
{
    // TODO Implement
    return nullptr;
}

void PartitionedMemoryPool::FreeMemory (void * pointer, size_t size)
{
    // TODO Implement    
}
#pragma endregion

#pragma region Public Non-virtual Methods
// NON-VOID METHODS
// VOID METHODS
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
// PartitionedMemoryPool (void);
#pragma endregion

#pragma region Private Virtual Methods
// PURE VIRTUAL METHODS
// VIRTUAL METHODS
#pragma endregion

#pragma region Private Non-virtual Methods
// NON-VOID METHODS
// VOID METHODS
#pragma endregion