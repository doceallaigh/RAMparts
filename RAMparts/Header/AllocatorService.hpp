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
class AllocatorService
{
public:
#pragma region Operators
    //! \cond \brief Copy assignment operator \endcond
    // AllocatorService& operator= (const AllocatorService &original);

    //! \cond \brief Move assignment operator \endcond
    // AllocatorService& operator= (AllocatorService &&original) noexcept;
#pragma endregion

#pragma region Custom Constructors
    /*! \cond \brief <Brief description goes here> \endcond
    *
    * \cond \param[in] <Parameter description goes here> \endcond
    * */
    // AllocatorService (T ... args);
#pragma endregion

#pragma region Standard Constructors & Destructor
    //! \brief Default Constructor
    AllocatorService(void) = default;

    //! \brief Copy Constructor
    AllocatorService(const AllocatorService &original) = default;

    //! \cond \brief Move Constructor \endcond
    // AllocatorService(const AllocatorService &&original) noexcept = default;

    //! \brief Destructor
    virtual ~AllocatorService(void) noexcept = default;
#pragma endregion

private:
#pragma region Private Constructors
    //! \cond \brief Private Default Constructor \endcond
    // AllocatorService(void) = default;
#pragma endregion

public:
#pragma region Public Methods
#pragma endregion

protected:
#pragma region Protected Methods
#pragma endregion

private:
#pragma region Private Methods
#pragma endregion

public:
#pragma region Public Fields
#pragma endregion

protected:
#pragma region Protected Fields
#pragma endregion

private:
#pragma region Private Fields
#pragma endregion
};