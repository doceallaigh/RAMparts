/* IMemoryReservationTracker.hpp
 * Interface description:
 *     <IMemoryReservationTracker description goes here>
 * * */

#pragma once

#pragma region Library Includes
#include <vector>
#pragma endregion

#pragma region Local Includes
#pragma endregion

#ifndef IMemoryReservationTracker_hpp
#define IMemoryReservationTracker_hpp

#pragma region Forward Declarations
class IMemoryPointer;
#pragma endregion

#pragma region Type Definitions
#pragma endregion


class IMemoryReservationTracker 
{
public:
#pragma region Destructor
    virtual ~IMemoryReservationTracker () = default;
#pragma endregion

#pragma region Public Methods
    virtual void Reserve(const IMemoryPointer& pointer) = 0;

    virtual void Unreserve(const IMemoryPointer& pointer) = 0;

    virtual std::vector<IMemoryPointer> GetReservedMemory(void) const = 0;

    virtual bool IsReserved(const IMemoryPointer& pointer) const = 0;
#pragma endregion
};
#endif // !IMemoryReservationTracker_hpp