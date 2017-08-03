#pragma once

#pragma region Library Includes
#include <memory>
#include <vector>
#pragma endregion

#pragma region Local Includes
#pragma endregion

#pragma region Forward Declarations
class IAllocator;
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief <Brief description goes here>
*
* <Detailed description goes here>
* */
class GlobalAllocationContext
{
public:
#pragma region Operators
    //! \cond \brief Copy assignment operator \endcond
    // GlobalAllocationContext& operator= (const GlobalAllocationContext &original);

    //! \cond \brief Move assignment operator \endcond
    // GlobalAllocationContext& operator= (GlobalAllocationContext &&original) noexcept;
#pragma endregion

#pragma region Custom Constructors
    /*! \cond \brief <Brief description goes here> \endcond
    *
    * \cond \param[in] <Parameter description goes here> \endcond
    * */
    // GlobalAllocationContext (T ... args);
#pragma endregion

#pragma region Standard Constructors & Destructor
    //! \brief Default Constructor
    GlobalAllocationContext(void) = default;

    //! \brief Copy Constructor
    GlobalAllocationContext(const GlobalAllocationContext &original) = default;

    //! \cond \brief Move Constructor \endcond
    // GlobalAllocationContext(const GlobalAllocationContext &&original) noexcept = default;

    //! \brief Destructor
    virtual ~GlobalAllocationContext(void) noexcept = default;
#pragma endregion

private:
#pragma region Private Constructors
    //! \cond \brief Private Default Constructor \endcond
    // GlobalAllocationContext(void) = default;
#pragma endregion

public:
#pragma region Public Methods
    static std::unique_ptr<IAllocator>& GlobalAllocationContext::GetActiveAllocator(void);

    template <typename TAllocator, typename ... TParams>
    static void SetAllocator(TParams ... params)
    {
        // TODO Move this out to a TPP
        GlobalAllocationContext::p_allocators->push_back(std::make_unique<TAllocator>(params ...));
    }

    static void Initialize(void);

    static void UnsetAllocator(void);
#pragma endregion

protected:
#pragma region Protected Methods
#pragma endregion

private:
#pragma region Private Methods
#pragma endregion

public:
#pragma region Public Fields
    static bool initialized;
#pragma endregion

protected:
#pragma region Protected Fields
#pragma endregion

private:
#pragma region Private Fields
    static std::unique_ptr<std::vector<std::unique_ptr<IAllocator>>> p_allocators;
#pragma endregion
};