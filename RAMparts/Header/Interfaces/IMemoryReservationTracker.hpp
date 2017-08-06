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

/*! \brief An API for tracking memory block availability
 * 
 * \remarks
 *     Memory reservations created/removed/returned by this API are guaranteed to exist 
 *     only in the context of the object on which those calls were made
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
    /*! \brief Attempt to reserve a block of memory
     * 
     * \return true \a iff the reservation attempt was successful
     * \param[in] memoryBlock The block of memory to reserve
     * 
     * \remarks Promise(s):
     *     1. An attempt to reserve a block of memory for which some or all memory is already reserved will fail
     *     2. A failed attempt will not change the state of this object
     * */
    virtual bool TryReserve(const IMemoryBlock& memoryBlock) = 0;

    /*! \brief Attempt to clear the reservation for a block of memory
     * 
     * \return true \a iff the reservation removal attempt was successful
     * \param[in] memoryBlock The block of memory for which to clear the reservation
     * 
     * \remarks Promise(s):
     *     1. An attempt to clear the reservation of a block of memory for which some or all memory is \b NOT already reserved will fail
     *     2. A failed attempt will not change the state of this object
     * */
    virtual bool TryUnreserve(const IMemoryBlock& memoryBlock) = 0;
    
    /*! \brief Get a collection of all memory blocks currently reserved by this tracker
     * 
     * \return A collection of memory blocks representing all memory currently reserved by this tracker
     * 
     * \remarks
     *     The memory blocks in this collection are not guaranteed to be identical to the blocks provided to make the reservations.
     *     They should, however, be equivalent, in that they represent the same set of bits in memory
     * */
    virtual const std::array<IMemoryBlock> GetReservedMemory(void) const = 0;
    
    /*! \brief Query whether or not the provied block can be reserved by this tracker in its current state
     * 
     * \return The same value that would be returned by a call to TryReserve, but without changing the satte of this tracker
     * */
    virtual bool IsAvailableForReservation(const IMemoryBlock& memoryBlock) const = 0;
#pragma endregion
};
