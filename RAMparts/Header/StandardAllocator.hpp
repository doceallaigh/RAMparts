#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#include "Interfaces/IAllocator.hpp"
#pragma endregion

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief <Brief description goes here>
*
* <Detailed description goes here>
* */
class StandardAllocator : public virtual IAllocator
{
public:
#pragma region Operators
    //! \cond \brief Copy assignment operator \endcond
    // StandardAllocator& operator= (const StandardAllocator &original);

    //! \cond \brief Move assignment operator \endcond
    // StandardAllocator& operator= (StandardAllocator &&original) noexcept;
#pragma endregion

#pragma region Custom Constructors
    /*! \cond \brief <Brief description goes here> \endcond
    *
    * \cond \param[in] <Parameter description goes here> \endcond
    * */
    // StandardAllocator (T ... args);
#pragma endregion

#pragma region Standard Constructors & Destructor
    //! \brief Default Constructor
    StandardAllocator(void) = default;

    //! \brief Copy Constructor
    StandardAllocator(const StandardAllocator &original) = default;

    //! \cond \brief Move Constructor \endcond
    // StandardAllocator(const StandardAllocator &&original) noexcept = default;

    //! \brief Destructor
    virtual ~StandardAllocator(void) noexcept = default;
#pragma endregion

private:
#pragma region Private Constructors
    //! \cond \brief Private Default Constructor \endcond
    // StandardAllocator(void) = default;
#pragma endregion

public:
#pragma region Public Methods
    virtual void * IAllocator::Allocate(const MemoryConstraints& constraints) throw(std::bad_alloc) override;

    virtual bool IAllocator::TryDelete(void * object) noexcept override;
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