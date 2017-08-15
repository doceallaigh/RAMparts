#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#include "Interfaces/IAllocator.hpp"
#include "Interfaces/IMemoryBlock.hpp"
#include "Interfaces/IMemoryPool.hpp"
#include "Interfaces/IMemoryReservationTracker.hpp"
#include "Interfaces/IMemorySelector.hpp"
#include "ConfiguredAllocator.hpp"
#include "PoolAllocatorConfig.hpp"
#pragma endregion

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief A POD object containing the dependencies necessary for operating a pool allocator
* */
typedef struct PoolAllocatorDependencyPack
{
public:
    const std::shared_ptr<IMemoryPool> MemoryPool;
    const std::shared_ptr<IMemoryReservationTracker> ReservationTracker;
    const std::shared_ptr<IMemorySelector> MemorySelector;
} PoolAllocatorDependencyPack;

/*! \brief An allocator which has a preset pool of memory to draw from
* */
template <typename TConfig>
class PoolAllocator : public virtual ConfiguredAllocator<PoolAllocatorConfig<TConfig>>, public virtual IAllocator
{
public:
#pragma region Operators
    //! \cond \brief Copy assignment operator \endcond
    // PoolAllocator& operator= (const PoolAllocator &original);

    //! \cond \brief Move assignment operator \endcond
    // PoolAllocator& operator= (PoolAllocator &&original) noexcept;
#pragma endregion

#pragma region Custom Constructors
    /*! \brief Dependant Constructor
    *
    * \param[in] config A struct detailing the configuration parameters for this pool allocator
    * \param[in] dependencyPack A struct containing the dependencies necessary for operating the allocator
    * */
    PoolAllocator(const std::shared_ptr<PoolAllocatorConfig<TConfig>> config, const std::shared_ptr<PoolAllocatorDependencyPack> dependencyPack)
        : ConfiguredAllocator<PoolAllocatorConfig<TConfig>>(config),
        dependencyPack(dependencyPack)
    { }
#pragma endregion

#pragma region Standard Constructors & Destructor
    //! \brief Default Constructor
    PoolAllocator(void) = default;

    //! \brief Copy Constructor
    PoolAllocator(const PoolAllocator &original) = default;

    //! \cond \brief Move Constructor \endcond
    // PoolAllocator(const PoolAllocator &&original) noexcept = default;

    //! \brief Destructor
    virtual ~PoolAllocator(void) noexcept = default;
#pragma endregion

private:
#pragma region Private Constructors
    //! \cond \brief Private Default Constructor \endcond
    // PoolAllocator(void) = default;
#pragma endregion

public:
#pragma region Public Methods
    virtual void * IAllocator::Allocate(const MemoryConstraints& constraints) throw(std::bad_alloc) override
    {
        auto memoryPool = this->dependencyPack->MemoryPool;
        auto memorySelector = this->dependencyPack->MemorySelector;
        auto memoryReservationTracker = this->dependencyPack->ReservationTracker;

        auto memoryBlock = memorySelector->SelectMemorySatisfyingConstraints(constraints);

        if (memoryReservationTracker->TryReserve(*memoryBlock))
        {
            return memoryBlock->GetAddress();
        }

        return nullptr;
    }

    virtual bool IAllocator::TryDelete(void * pointer) noexcept override
    {
        auto memoryPool = this->dependencyPack->MemoryPool;
        auto memorySelector = this->dependencyPack->MemorySelector;
        auto memoryReservationTracker = this->dependencyPack->ReservationTracker;

        auto memoryReservationMap = memoryReservationTracker->GetReservedMemoryMap();
        auto memoryBlock = memoryReservationMap[pointer];

        if (memoryBlock)
        {
            return memoryReservationTracker->TryUnreserve(*memoryBlock);
        }

        return false;
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
    std::shared_ptr<PoolAllocatorDependencyPack> dependencyPack;
#pragma endregion

private:
#pragma region Private Fields
#pragma endregion
};