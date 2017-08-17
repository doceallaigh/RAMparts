#pragma once

#pragma region Library Includes
#include <memory>
#pragma endregion

#pragma region Local Includes
#include "Interfaces/IMemoryPool.hpp"
#pragma endregion

#pragma region Forward Declarations
class IMemoryIterator;
class IMemoryBlock;
struct MemoryPoolConfig;
#pragma endregion

#pragma region Type Definitions
#pragma endregion


/*! \brief <Brief description goes here>
*
* <Detailed description goes here>
* */
template <typename TConfig>
class ConfiguredMemoryPool : public virtual IMemoryPool
{
#pragma region Class Assertions
    static_assert(std::is_base_of<MemoryPoolConfig, TConfig>(), "");
#pragma endregion

public:
#pragma region Operators
    //! \cond \brief Copy assignment operator \endcond
    // ConfiguredMemoryPool& operator= (const ConfiguredMemoryPool &original);

    //! \cond \brief Move assignment operator \endcond
    // ConfiguredMemoryPool& operator= (ConfiguredMemoryPool &&original) noexcept;
#pragma endregion

#pragma region Custom Constructors
    /*! \brief <Brief description goes here>
    *
    * \param[in] <Parameter description goes here>
    * */
    ConfiguredMemoryPool(const std::shared_ptr<TConfig> config)
        : config(config)
    { }
#pragma endregion

#pragma region Standard Constructors & Destructor
    //! \cond \brief Default Constructor \endcond
    // ConfiguredMemoryPool(void) = default;

    //! \brief Copy Constructor
    ConfiguredMemoryPool(const ConfiguredMemoryPool &original) = default;

    //! \cond \brief Move Constructor \endcond
    // ConfiguredMemoryPool(const ConfiguredMemoryPool &&original) noexcept = default;

    //! \brief Destructor
    virtual ~ConfiguredMemoryPool(void) noexcept = default;
#pragma endregion

private:
#pragma region Private Constructors
    //! \brief Private Default Constructor
    ConfiguredMemoryPool(void) = default;
#pragma endregion

public:
#pragma region Public Methods
    virtual std::shared_ptr<IMemoryIterator> GetMemoryIterator(void) const override = 0;

    virtual std::vector<IMemoryBlock> GetOverlappingBlocks(const IMemoryBlock& pointer) const override = 0;
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