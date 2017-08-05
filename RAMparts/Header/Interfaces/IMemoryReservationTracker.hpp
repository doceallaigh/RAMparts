#pragma once

#pragma region Library Includes
#include <vector>
#pragma endregion

#pragma region Local Includes
#pragma endregion

#pragma region Forward Declarations
class IMemoryBlock;
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief <Brief description goes here>
 *
 * <Detailed description goes here>
 * */
class IMemoryReservationTracker
{
public:
#pragma region Destructor
    //! \cond Default Destructor
    virtual ~IMemoryReservationTracker(void) = default;
    //! \endcond
#pragma endregion

#pragma region Public Methods
    virtual void Reserve(const IMemoryBlock& pointer) = 0;

    virtual void Unreserve(const IMemoryBlock& pointer) = 0;

    virtual std::vector<IMemoryBlock> GetReservedMemory(void) const = 0;

    virtual bool IsReserved(const IMemoryBlock& pointer) const = 0;
#pragma endregion
};