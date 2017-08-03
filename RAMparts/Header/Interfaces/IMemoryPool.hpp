#pragma once

#pragma region Library Includes
#include <vector>
#pragma endregion

#pragma region Local Includes
#pragma endregion

#pragma region Forward Declarations
class IMemoryIterator;
class IMemoryPointer;
#pragma endregion

#pragma region Type Definitions
typedef unsigned char byte;
#pragma endregion

/*! \brief <Brief description goes here>
*
* <Detailed description goes here>
* */
class IMemoryPool
{
public:
#pragma region Destructor
    //! \cond Default Destructor
    virtual ~IMemoryPool(void) = default;
    //! \endcond
#pragma endregion

#pragma region Public Methods
    virtual std::unique_ptr<IMemoryIterator> GetMemoryIterator(void) const = 0;

    virtual std::vector<IMemoryPointer> GetOverlappingPointers(const IMemoryPointer& pointer) const = 0;
#pragma endregion
};