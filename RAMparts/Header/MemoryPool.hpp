/* MemoryPool.hpp
 * Class description:
 *     <MemoryPool description goes here>
 * * */

#pragma once

#pragma region Library Includes
#include <memory>
#pragma endregion

#pragma region Local Includes
#include "Interfaces/IMemoryPool.hpp"
#include "MemoryPoolConfig.hpp"
#pragma endregion

#ifndef MemoryPool_hpp
#define MemoryPool_hpp

#pragma region Forward Declarations
#pragma endregion

class MemoryPool : public virtual IMemoryPool
{
public:
#pragma region Public Constructors & Destructor
    // DEFAULT CONSTRUCTOR
    // MemoryPool (void);

    // CUSTOM CONSTRUCTORS
    MemoryPool (const std::shared_ptr<MemoryPoolConfig> config);

    // COPY CONSTRUCTOR
    // MemoryPool (const MemoryPool &original);

    // MOVE CONSTRUCTOR
    // MemoryPool (const MemoryPool &&original) noexcept;

    // DESTRUCTOR
    virtual ~MemoryPool (void) noexcept;
#pragma endregion

#pragma region Operators
    // COPY ASSIGNEMENT OPERATOR
    // MemoryPool& operator= (const MemoryPool &original);

    // MOVE ASSIGNEMENT OPERATOR
    // MemoryPool& operator= (MemoryPool &&original) noexcept;
#pragma endregion

#pragma region Public Virtual Methods
    // PURE VIRTUAL METHODS
    // VIRTUAL METHODS
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
    const std::shared_ptr<MemoryPoolConfig> config;
    // PRIMITIVES
#pragma endregion

private:
#pragma region Private Constructors
    // DEFAULT CONSTRUCTOR
    // MemoryPool (void);
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
#endif // !MemoryPool_hpp