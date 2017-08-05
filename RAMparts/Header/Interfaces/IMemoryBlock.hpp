#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#pragma endregion

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief An API to contain and expose information about a block of memory
 * */
class IMemoryBlock
{
public:
#pragma region Destructor
    //! \cond Default Destructor
    virtual ~IMemoryBlock(void) = default;
    //! \endcond
#pragma endregion

#pragma region Public Methods
    /*! \brief Get the address of the start of the described memory block
     *
     * \return A raw pointer to the start of the described memory block
     * 
     * \remarks Promise(s):
     *     1. The value returned here should remain the same throughout the entire life of this object
     * */
    virtual void * GetAddress(void) const = 0;

    /*! \brief Get the size of the described memory block
     *
     * \return The size of the described memory block
     * 
     * \remarks Promise(s):
     *     1. The value returned here should remain the same throughout the entire life of this object
     * */
    virtual size_t GetSize(void) const = 0;

    /*! \brief Get the alignment of the described memory block
     *
     * \return The alignment of the described memory block
     * 
     * \remarks Promise(s):
     *     1. The value returned here should remain the same throughout the entire life of this object
     * */
    virtual size_t GetAlignment(void) const = 0;

    /*! \brief Does the provided memory block overlap with this one?
     * 
     * \param[in] memoryBlock A memory block
     * 
     * \return \b true \a iff either:
     *     1. The address of this block is contained in the span of the passed block (inclusive)
     *     2. The address of the passed block is contained in the span of this block (inclusive)
     * */
    virtual bool Overlaps(const IMemoryBlock& memoryBlock) const = 0;

    /*! \brief Does this memory block contain the provided memory address?
    *
    * \param[in] address A memory address
    *
    * \return \b true \a iff:
    *     1. The provided address is contained in the span of the passed block (inclusive)
    * */
    virtual bool Contains(const void * address) const = 0;
#pragma endregion
};