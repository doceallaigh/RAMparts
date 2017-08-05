#pragma once

#pragma region Library Includes
#include <vector>
#pragma endregion

#pragma region Local Includes
#pragma endregion

#pragma region Forward Declarations
class IMemoryIterator;
class IMemoryBlock;
#pragma endregion

#pragma region Type Definitions
typedef unsigned char byte;
#pragma endregion

/*! \brief An API for memory storage and access
 *
 * \remarks In addition to any rules defined below, implementations of this API are expected to uphold the following promise(s):
 *     1. The pool of memory described by this object must be static in size and location, or exhibit the following properties:
 *         1. Any memory iterator returned by a previous call to this API cannot be invalidated by the update
 *         2. All memory currently allocated in the scope of this pool must remain in the confined of the defined space
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
    /*! \brief Get an object used to iterate over blocks of memory contained within this pool
     * 
     * \return A pointer to a memory iterator object
     * */
    virtual std::shared_ptr<IMemoryIterator> GetMemoryIterator(void) const = 0;

    /*! \brief Get a collection of all blocks of memory in this pool which overlap with the provided block
     * 
     * \param[in] memoryBlock The block of memory to check against
     *
     * \return A collection of all blocks of memory in this pool which overlap with the provided block
     */
    virtual std::vector<IMemoryBlock> GetOverlappingBlocks(const IMemoryBlock& memoryBlock) const = 0;
#pragma endregion
};