#pragma once

#pragma region Library Includes
#include <map>
#include <vector>
#pragma endregion

#pragma region Local Includes
#include "Interfaces/IMemoryBlock.hpp"
#include "Interfaces/IMemoryIterator.hpp"
#include "MemoryConstraints.hpp"
#pragma endregion

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
typedef std::vector<IMemoryBlock>::const_iterator BlockIterator;
#pragma endregion

/*! \brief <Brief description goes here>
 * 
 * <Detailed description goes here>
 * */
class PartitionedMapMemoryIterator  : public virtual IMemoryIterator
{
public:
#pragma region Operators
    //! \cond \brief Copy assignment operator \endcond
    // PartitionedMapMemoryIterator& operator= (const PartitionedMapMemoryIterator &original);

    //! \cond \brief Move assignment operator \endcond
    // PartitionedMapMemoryIterator& operator= (PartitionedMapMemoryIterator &&original) noexcept;
#pragma endregion

#pragma region Custom Constructors
    /*! \cond \brief <Brief description goes here> \endcond
    *
    * \cond \param[in] <Parameter description goes here> \endcond
    * */
    PartitionedMapMemoryIterator (std::map<MemoryConstraints, std::vector<IMemoryBlock>> memoryMap)
    {
        this->iteratorMap = std::map<MemoryConstraints, BlockIterator>();

        for (const auto& kvp : memoryMap)
        {
            this->iteratorMap[kvp.first] = kvp.second.cbegin();
        }
    }
#pragma endregion

#pragma region Standard Constructors & Destructor
    //! \brief Default Constructor
    PartitionedMapMemoryIterator(void) = default;

    //! \brief Copy Constructor
    PartitionedMapMemoryIterator(const PartitionedMapMemoryIterator &original) = default;

    //! \cond \brief Move Constructor \endcond
    // PartitionedMapMemoryIterator(const PartitionedMapMemoryIterator &&original) noexcept = default;

    //! \brief Destructor
    virtual ~PartitionedMapMemoryIterator(void) noexcept = default;
#pragma endregion

private:
#pragma region Private Constructors
    //! \cond \brief Private Default Constructor \endcond
    // PartitionedMapMemoryIterator(void) = default;
#pragma endregion

public:
#pragma region Public Methods
    virtual void SetMemoryConstraints(const MemoryConstraints&& constraints) override
    {
        this->activeConstraints = constraints;
    }

    virtual void Advance(void) override
    {
        this->iteratorMap[this->activeConstraints];
    }

    virtual std::shared_ptr<IMemoryBlock> GetCurrent(void) const override
    {
        const BlockIterator blockIterator = this->iteratorMap.at(this->activeConstraints);

        return std::make_shared<IMemoryBlock>(*blockIterator);
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
#pragma endregion

private:
#pragma region Private Fields
    MemoryConstraints activeConstraints;
    std::map<MemoryConstraints, BlockIterator> iteratorMap;
#pragma endregion
};