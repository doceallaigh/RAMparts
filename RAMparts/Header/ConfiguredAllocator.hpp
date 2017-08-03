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
template <typename TConfig>
class ConfiguredAllocator : public virtual IAllocator
{
public:
#pragma region Operators
    //! \cond \brief Copy assignment operator \endcond
    // ConfiguredAllocator& operator= (const ConfiguredAllocator &original);

    //! \cond \brief Move assignment operator \endcond
    // ConfiguredAllocator& operator= (ConfiguredAllocator &&original) noexcept;
#pragma endregion

#pragma region Custom Constructors
    /*! \brief <Brief description goes here>
    *
    * \param[in] <Parameter description goes here>
    * */
    ConfiguredAllocator<TConfig>(const std::shared_ptr<TConfig> config) : config(config)
    { }
#pragma endregion

#pragma region Standard Constructors & Destructor
    //! \brief Default Constructor
    ConfiguredAllocator(void) = default;

    //! \brief Copy Constructor
    ConfiguredAllocator(const ConfiguredAllocator &original) = default;

    //! \cond \brief Move Constructor \endcond
    // ConfiguredAllocator(const ConfiguredAllocator &&original) noexcept = default;

    //! \brief Destructor
    virtual ~ConfiguredAllocator(void) noexcept = default;
#pragma endregion

private:
#pragma region Private Constructors
    //! \cond \brief Private Default Constructor \endcond
    // ConfiguredAllocator(void) = default;
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
    const std::shared_ptr<TConfig> config;
#pragma endregion

private:
#pragma region Private Fields
#pragma endregion
};