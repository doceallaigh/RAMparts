#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#pragma endregion

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief <Brief description goes here>
*
* <Detailed description goes here>
* */
class IMemoryPointer
{
public:
#pragma region Destructor
    //! \cond Default Destructor
    virtual ~IMemoryPointer(void) = default;
    //! \endcond
#pragma endregion

#pragma region Public Methods
    virtual void * GetRawPointer(void) const = 0;

    virtual size_t GetSize(void) const = 0;

    virtual size_t GetAlignment(void) const = 0;

    virtual bool Overlaps(const IMemoryPointer& pointer) const = 0;

    virtual bool Contains(const void * pointer) const = 0;
#pragma endregion
};