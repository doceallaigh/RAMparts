/* IMemoryPool.hpp
 * Interface description:
 *     <IMemoryPool description goes here>
 * * */

#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#pragma endregion

#ifndef IMemoryPool_hpp
#define IMemoryPool_hpp

#pragma region Forward Declarations
#pragma endregion

class IMemoryPool 
{
public:
    virtual ~IMemoryPool () = default;

#pragma region Public Virtual Methods
    // PURE VIRTUAL METHODS
    virtual void * GetMemory (size_t size) = 0;

    virtual void FreeMemory (void * pointer, size_t size) = 0;
#pragma endregion
};
#endif // !IMemoryPool_hpp