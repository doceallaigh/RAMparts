/* IMemoryIterator.hpp
 * Interface description:
 *     <IMemoryIterator description goes here>
 * * */

#pragma once

#pragma region Library Includes
#include <memory>
#pragma endregion

#pragma region Local Includes
#include "IMemoryPointer.hpp"
#pragma endregion

#ifndef IMemoryIterator_hpp
#define IMemoryIterator_hpp

#pragma region Forward Declarations
struct MemoryConstraints;
#pragma endregion

#pragma region Type Definitions
#pragma endregion


class IMemoryIterator
{
public:
#pragma region Destructor
    virtual ~IMemoryIterator () = default;
#pragma endregion

#pragma region Public Methods
    virtual void SetMemoryConstraints(const MemoryConstraints& constraints) = 0;

    virtual void Advance(void) = 0;

    virtual std::unique_ptr<IMemoryPointer> GetCurrent(void) const = 0;
#pragma endregion
};
#endif // !IMemoryIterator_hpp