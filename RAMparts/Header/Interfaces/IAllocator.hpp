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
class IAllocator
{
public:
#pragma region Destructor
    //! \cond Default Destructor
    virtual ~IAllocator(void) = default;
    //! \endcond
#pragma endregion

#pragma region Public Methods
    virtual void * Allocate(size_t size) = 0;

    virtual void Delete(void * object) = 0;
#pragma endregion
};