/* PartitionedMemoryPool.hpp
 * Class description:
 *     <PartitionedMemoryPool description goes here>
 * * */

#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#include "MemoryPool.hpp"
#pragma endregion

#ifndef PartitionedMemoryPool_hpp
#define PartitionedMemoryPool_hpp

#pragma region Forward Declarations
#pragma endregion

class PartitionedMemoryPool : public virtual MemoryPool
{
public:
#pragma region Public Constructors & Destructor
    // DEFAULT CONSTRUCTOR
    // PartitionedMemoryPool (void);

    // CUSTOM CONSTRUCTORS
    PartitionedMemoryPool (const std::shared_ptr<MemoryPoolConfig> config);

    // COPY CONSTRUCTOR
    // PartitionedMemoryPool (const PartitionedMemoryPool &original);

    // MOVE CONSTRUCTOR
    // PartitionedMemoryPool (const PartitionedMemoryPool &&original) noexcept;

    // DESTRUCTOR
    // ~PartitionedMemoryPool (void) noexcept;
#pragma endregion

#pragma region Operators
    // COPY ASSIGNEMENT OPERATOR
    // PartitionedMemoryPool& operator= (const PartitionedMemoryPool &original);

    // MOVE ASSIGNEMENT OPERATOR
    // PartitionedMemoryPool& operator= (PartitionedMemoryPool &&original) noexcept;
#pragma endregion

#pragma region Public Virtual Methods
    // PURE VIRTUAL METHODS
    // VIRTUAL METHODS
    virtual void * GetMemory (size_t size) override;

    virtual void FreeMemory (void * pointer, size_t size) override;
#pragma endregion

#pragma region Public Non-virtual Methods
    // NON-VOID METHODS
    // VOID METHODS
#pragma endregion

#pragma region Public Fields
    // SERVICES
    // COLLECTIONS
    // OBJECTS
    // PRIMITIVES
#pragma endregion

protected:
#pragma region Protected Virtual Methods
    // PURE VIRTUAL METHODS
    // VIRTUAL METHODS
#pragma endregion

#pragma region Protected Non-virtual Methods
    // NON-VOID METHODS
    // VOID METHODS
#pragma endregion

#pragma region Protected Fields
    // SERVICES
    // COLLECTIONS
    // OBJECTS
    // PRIMITIVES
#pragma endregion

private:
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

#pragma region Private Fields
    // SERVICES
    // COLLECTIONS
    // OBJECTS
    // PRIMITIVES
#pragma endregion
};
#endif // !PartitionedMemoryPool_hpp