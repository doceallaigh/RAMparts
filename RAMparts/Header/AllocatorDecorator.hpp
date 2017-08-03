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
class AllocatorDecorator
{
public:
#pragma region Operators
    //! \cond \brief Copy assignment operator \endcond
    // AllocatorDecorator& operator= (const AllocatorDecorator &original);

    //! \cond \brief Move assignment operator \endcond
    // AllocatorDecorator& operator= (AllocatorDecorator &&original) noexcept;
#pragma endregion

#pragma region Custom Constructors
    /*! \cond \brief <Brief description goes here> \endcond
    *
    * \cond \param[in] <Parameter description goes here> \endcond
    * */
    // AllocatorDecorator (T ... args);
#pragma endregion

#pragma region Standard Constructors & Destructor
    //! \brief Default Constructor
    AllocatorDecorator(void) = default;

    //! \brief Copy Constructor
    AllocatorDecorator(const AllocatorDecorator &original) = default;

    //! \cond \brief Move Constructor \endcond
    // AllocatorDecorator(const AllocatorDecorator &&original) noexcept = default;

    //! \brief Destructor
    virtual ~AllocatorDecorator(void) noexcept = default;
#pragma endregion

private:
#pragma region Private Constructors
    //! \cond \brief Private Default Constructor \endcond
    // AllocatorDecorator(void) = default;
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