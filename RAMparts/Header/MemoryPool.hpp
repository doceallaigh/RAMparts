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
class MemoryPool : public virtual IMemoryPool
{
public:
#pragma region Operators
    //! \cond \brief Copy assignment operator \endcond
    // MemoryPool& operator= (const MemoryPool &original);

    //! \cond \brief Move assignment operator \endcond
    // MemoryPool& operator= (MemoryPool &&original) noexcept;
#pragma endregion

#pragma region Custom Constructors
    /*! \brief <Brief description goes here>
    *
    * \param[in] <Parameter description goes here>
    * */
    MemoryPool(const std::shared_ptr<MemoryPoolConfig> config);
#pragma endregion

#pragma region Standard Constructors & Destructor
    //! \brief Default Constructor
    MemoryPool(void) = default;

    //! \brief Copy Constructor
    MemoryPool(const MemoryPool &original) = default;

    //! \cond \brief Move Constructor \endcond
    // MemoryPool(const MemoryPool &&original) noexcept = default;

    //! \brief Destructor
    virtual ~MemoryPool(void) noexcept = default;
#pragma endregion

private:
#pragma region Private Constructors
    //! \cond \brief Private Default Constructor \endcond
    // MemoryPool(void) = default;
#pragma endregion

public:
#pragma region Public Methods
    virtual std::unique_ptr<IMemoryIterator> GetMemoryIterator(void) const override = 0;

    virtual std::vector<IMemoryBlock> GetOverlappingPointers(const IMemoryBlock& pointer) const override = 0;
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
    const std::shared_ptr<MemoryPoolConfig> config;
#pragma endregion

private:
#pragma region Private Fields
#pragma endregion
};