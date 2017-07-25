/* StandardAllocator.hpp
* Class description:
*     This class acts as a dummy allocator, offloading to malloc and free in the event that a custom allocator is not desirable.
*     It should be noted that while this allocator does offload to predefined behavior, it is not guaranteed or even expected to
*     behave identically to the standard new and delete.
* * */

#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#include "Interfaces/IAllocator.hpp"
#pragma endregion

#ifndef StandardAllocator_hpp
#define StandardAllocator_hpp

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

class StandardAllocator : public virtual IAllocator
{
public:
#pragma region Public Constructors & Destructor
    // DEFAULT CONSTRUCTOR
    // StandardAllocator (void);

    // COPY CONSTRUCTOR
    // StandardAllocator (const StandardAllocator &original);

    // MOVE CONSTRUCTOR
    // StandardAllocator (const StandardAllocator &&original) noexcept;

    // DESTRUCTOR
    // ~StandardAllocator (void) noexcept;
#pragma endregion

#pragma region Operators
    // COPY ASSIGNEMENT OPERATOR
    // StandardAllocator& operator= (const StandardAllocator &original);

    // MOVE ASSIGNEMENT OPERATOR
    // StandardAllocator& operator= (StandardAllocator &&original) noexcept;
#pragma endregion

#pragma region Public Virtual Methods
    // PURE VIRTUAL METHODS
    // VIRTUAL METHODS
#pragma endregion

#pragma region Public Non-virtual Methods
    // NON-VOID METHODS
    virtual void * IAllocator::Allocate (size_t size) override;

    // VOID METHODS
    virtual void IAllocator::Delete (void * object) override;
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

#pragma region Private Fields
    // SERVICES
    // COLLECTIONS
    // OBJECTS
    // PRIMITIVES
#pragma endregion
};
#endif // !StandardAllocator_hpp