/* ContiguousMemoryPool.hpp
 * Class description:
 *     <ContiguousMemoryPool description goes here>
 * * */

#pragma once

#pragma region Library Includes
#include <memory>
#pragma endregion

#pragma region Local Includes
#include "MemoryPool.hpp"
#include "MemoryPoolConfig.hpp"
#pragma endregion

#ifndef ContiguousMemoryPool_hpp
#define ContiguousMemoryPool_hpp

#pragma region Forward Declarations
#pragma endregion

class ContiguousMemoryPool : public virtual MemoryPool
{
public:
#pragma region Public Constructors & Destructor
    // DEFAULT CONSTRUCTOR
    // ContiguousMemoryPool (void);

    // CUSTOM CONSTRUCTORS
    ContiguousMemoryPool (const std::shared_ptr<MemoryPoolConfig> config);

    // COPY CONSTRUCTOR
    // ContiguousMemoryPool (const ContiguousMemoryPool &original);

    // MOVE CONSTRUCTOR
    // ContiguousMemoryPool (const ContiguousMemoryPool &&original) noexcept;

    // DESTRUCTOR
    // ~ContiguousMemoryPool (void) noexcept;
#pragma endregion

#pragma region Operators
    // COPY ASSIGNEMENT OPERATOR
    // ContiguousMemoryPool& operator= (const ContiguousMemoryPool &original);

    // MOVE ASSIGNEMENT OPERATOR
    // ContiguousMemoryPool& operator= (ContiguousMemoryPool &&original) noexcept;
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
    // ContiguousMemoryPool (void);
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
#endif // !ContiguousMemoryPool_hpp