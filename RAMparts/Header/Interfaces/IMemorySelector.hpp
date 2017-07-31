/* IMemorySelector.hpp
 * Interface description:
 *     <IMemorySelector description goes here>
 * * */

#pragma once

#pragma region Library Includes
#include <memory>
#pragma endregion

#pragma region Local Includes
#include "IMemoryPointer.hpp"
#pragma endregion

#ifndef IMemorySelector_hpp
#define IMemorySelector_hpp

#pragma region Forward Declarations
struct MemoryConstraints;
#pragma endregion

#pragma region Type Definitions
#pragma endregion


class IMemorySelector 
{
public:
#pragma region Destructor
    virtual ~IMemorySelector () = default;
#pragma endregion

#pragma region Public Methods
    virtual std::unique_ptr<IMemoryPointer> SelectMemorySatisfyingConstraints(const MemoryConstraints& constraints) = 0;
#pragma endregion
};
#endif // !IMemorySelector_hpp