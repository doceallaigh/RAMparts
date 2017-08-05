#pragma once

#pragma region Library Includes
#include <memory>
#pragma endregion

#pragma region Local Includes
#pragma endregion

#pragma region Forward Declarations
struct MemoryConstraints;
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief An API for memory allocation and release
 *
 * \remarks In addition to any rules defined below, implementations of this API are expected to uphold the following promise(s):
 *     1. Allocated memory remains in scope until it is deleted via the same API implementation
 * */
class IAllocator
{
public:
#pragma region Destructor
    //! \cond Default Destructor
    virtual ~IAllocator(void) = default;
    //! \endcond
#pragma endregion

#pragma region Public Methods
    /*! \brief Reserve a block of memory satisfying provided constraints
     * 
     * \return A raw pointer to a reserved block of memory
     * \param[in] constraints A struct representing the requirements which must be satisfied by the returned block of memory
     * \throw std::bad_alloc thrown iff allocation was not successful
     * 
     * \remarks Promise(s):
     *     1. If a memory block satisfying the provided cannot be reserved, 
     *        a std::bad_alloc exception should be thrown rather than failing silently
     *     2. The block of memory returned here by instance \b A of this contract should not overlap a block previously 
     *        allocated by \b A unless it has since been deleted from \b A via the same API  
     */
    virtual void * Allocate(const MemoryConstraints& constraints) throw(std::bad_alloc) = 0;

    /*! \brief Release a block of memory previously reserved in the context of this allocator
    *
    * \return A boolean value representing whether or not the deletion was successful
    * \param[in] pointer A raw pointer to a block of memory 
    *
    * \remarks Promise(s):
    *     1. A call to this function on instance \b A with pointer \b p as a parameter should return true \a iff:
    *        1. A block of memory starting at \b p was reserved in the context of \b A at the start of the call
    *        2. Said block is unreserved in the context of \b A at the end of the call
    */
    virtual bool TryDelete(void * pointer) noexcept = 0;
#pragma endregion
};