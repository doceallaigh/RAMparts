#pragma once

#pragma region Library Includes
#include <map>
#pragma endregion

#pragma region Local Includes
#include "Interfaces/IMemoryBlock.hpp"
#include "Interfaces/IMemoryIterator.hpp"
#include "ConfiguredMemoryPool.hpp"
#include "PartitionedMemoryPoolConfig.hpp"
#pragma endregion

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief <Brief description goes here>
 * 
 * <Detailed description goes here>
 * */
class PartitionedMemoryPool : public virtual ConfiguredMemoryPool<PartitionedMemoryPoolConfig>
{
#pragma region Class Assertions
#pragma endregion

public:
#pragma region Operators
    //! \cond \brief Copy assignment operator \endcond
    // PartitionedMemoryPool& operator= (const PartitionedMemoryPool &original);

    //! \cond \brief Move assignment operator \endcond
    // PartitionedMemoryPool& operator= (PartitionedMemoryPool &&original) noexcept;
#pragma endregion

#pragma region Custom Constructors
    /*! \brief <Brief description goes here>
    *
    * \param[in] <Parameter description goes here>
    * */
    PartitionedMemoryPool(const std::shared_ptr<PartitionedMemoryPoolConfig> config)
        : ConfiguredMemoryPool(config)
    { }
#pragma endregion

#pragma region Standard Constructors & Destructor
    //! \cond \brief Default Constructor \endcond
    // PartitionedMemoryPool(void) = default;

    //! \brief Copy Constructor
    PartitionedMemoryPool(const PartitionedMemoryPool &original) = default;

    //! \brief Move Constructor
    // PartitionedMemoryPool(const PartitionedMemoryPool &&original) noexcept = default;

    //! \brief Destructor
    virtual ~PartitionedMemoryPool(void) noexcept = default;
#pragma endregion

private:
#pragma region Private Constructors
    //! \cond \brief Private Default Constructor \endcond
    // PartitionedMemoryPool(void) = default;
#pragma endregion

public:
#pragma region Public Methods
    virtual std::shared_ptr<IMemoryIterator> GetMemoryIterator(void) const override
    {
        return std::shared_ptr<IMemoryIterator>();
    }

    virtual std::vector<IMemoryBlock> GetOverlappingBlocks(const IMemoryBlock& pointer) const override
    {
        return std::vector<IMemoryBlock>();
    }
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
    std::map<const MemoryConstraints, std::vector<IMemoryBlock>> memoryMap;
#pragma endregion

private:
#pragma region Private Fields
#pragma endregion
};