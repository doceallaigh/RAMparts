#pragma once

#pragma region Library Includes
#include <memory>
#pragma endregion

#pragma region Local Includes
#pragma endregion

#pragma region Forward Declarations
class IMemoryPointer;
struct MemoryConstraints;
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief <Brief description goes here>
*
* <Detailed description goes here>
* */
class IMemorySelector
{
public:
#pragma region Destructor
    //! \cond Default Destructor
    virtual ~IMemorySelector(void) = default;
    //! \endcond
#pragma endregion

#pragma region Public Methods
    virtual std::unique_ptr<IMemoryPointer> SelectMemorySatisfyingConstraints(const MemoryConstraints& constraints) = 0;
#pragma endregion
};