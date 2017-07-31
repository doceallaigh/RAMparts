/* IMemoryPool.hpp
 * Interface description:
 *     <IMemoryPool description goes here>
 * * */

#pragma once

#pragma region Library Includes
#include <vector>
#pragma endregion

#pragma region Local Includes
#include "IMemoryIterator.hpp"
#include "IMemoryPointer.hpp"
#pragma endregion

#ifndef IMemoryPool_hpp
#define IMemoryPool_hpp

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
typedef unsigned char byte;
#pragma endregion

class IMemoryPool 
{
public:
#pragma region Destructor
    virtual ~IMemoryPool () = default;
#pragma endregion

#pragma region Public Methods
    virtual std::unique_ptr<IMemoryIterator> GetMemoryIterator(void) const = 0;

    virtual std::vector<IMemoryPointer> GetOverlappingPointers(const IMemoryPointer& pointer) const = 0;
#pragma endregion
};
#endif // !IMemoryPool_hpp