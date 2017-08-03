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
class IMemoryIterator
{
public:
#pragma region Destructor
    //! \cond Default Destructor
    virtual ~IMemoryIterator(void) = default;
    //! \endcond
#pragma endregion

#pragma region Public Methods
    virtual void SetMemoryConstraints(const MemoryConstraints& constraints) = 0;

    virtual void Advance(void) = 0;

    virtual std::unique_ptr<IMemoryPointer> GetCurrent(void) const = 0;
#pragma endregion
};