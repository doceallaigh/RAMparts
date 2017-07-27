/* PoolAllocator.hpp
* Class description:
*     This file defines a basic allocator object which maintains a statically sized pool of memory which it partitions as needed.
* * */

#pragma once

#pragma region Library Includes
#include <memory>
#pragma endregion

#pragma region Local Includes
#include "Interfaces/IAllocator.hpp"
#include "AllocatorConfig.hpp"
#pragma endregion

#ifndef PoolAllocator_hpp
#define PoolAllocator_hpp

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
typedef unsigned char byte;
#pragma endregion

class PoolAllocator : public virtual IAllocator
{
public:
#pragma region Public Constructors & Destructor
    // DEFAULT CONSTRUCTOR
    // PoolAllocator (void);

    // COPY CONSTRUCTOR
    // PoolAllocator (const PoolAllocator &original);

    // MOVE CONSTRUCTOR
    // PoolAllocator (const PoolAllocator &&original) noexcept;

    // CUSTOM CONSTRUCTORS
    PoolAllocator (const AllocatorConfig& config);

    // DESTRUCTOR
    virtual ~PoolAllocator (void) noexcept;
#pragma endregion

#pragma region Operators
    // COPY ASSIGNEMENT OPERATOR
    // PoolAllocator& operator= (const PoolAllocator &original);

    // MOVE ASSIGNEMENT OPERATOR
    // PoolAllocator& operator= (PoolAllocator &&original) noexcept;
#pragma endregion

#pragma region Public Virtual Methods
    // PURE VIRTUAL METHODS
    // VIRTUAL METHODS
#pragma endregion

#pragma region Public Non-virtual Methods
    // NON-VOID METHODS
    void IAllocator::Delete (void * object) override;

    // VOID METHODS
    void * IAllocator::Allocate (size_t size) override;
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
    // PoolAllocator (void);
#pragma endregion

#pragma region Private Virtual Methods
    // PURE VIRTUAL METHODS
    // VIRTUAL METHODS
#pragma endregion

#pragma region Private Non-virtual Methods
    // NON-VOID METHODS
    byte * MergeSpace (byte * startAddress);

    byte * GetPreviousBlockAddress (byte* startAddress) const;

    // VOID METHODS
    void WriteSize (size_t size);

    void ReserveSpace (size_t size);

    void MarkDeleted (byte * addressToMark);
#pragma endregion

#pragma region Private Fields
    // SERVICES
    // COLLECTIONS
    // OBJECTS
    // PRIMITIVES
    size_t size;
    byte *memoryArray;
    byte *nextAddress;
#pragma endregion
};
#endif // !PoolAllocator_hpp