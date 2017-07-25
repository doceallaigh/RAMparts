/* IAllocator.hpp
 * Interface description:
 *     This file defines the basic interface of all memory allocators.  
 *     Implementers are responsible for detailing the rules by which memory is allocated and released.
 * * */

#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#pragma endregion

#ifndef IAllocator_hpp
#define IAllocator_hpp

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

class IAllocator
{
public:
    // DESTRUCTOR
    virtual ~IAllocator () noexcept = default;

#pragma region Public Virtual Methods
    // PURE VIRTUAL METHODS
    virtual void * Allocate (size_t size) = 0;

    virtual void Delete (void * object) = 0;
#pragma endregion
};
#endif // !IAllocator_hpp