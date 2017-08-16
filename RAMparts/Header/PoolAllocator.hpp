#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#include "Interfaces/IAllocator.hpp"
#include "ConfiguredAllocator.hpp"
#pragma endregion

#pragma region Forward Declarations
class IMemoryPool;
class IMemoryReservationTracker;
class IMemorySelector;
struct AllocatorConfig;
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief A POD object containing the dependencies necessary for operating a pool allocator
* */
typedef struct PoolAllocatorDependencyPack
{
public:
    std::shared_ptr<IMemoryPool> MemoryPool;
    std::shared_ptr<IMemoryReservationTracker> ReservationTracker;
    std::shared_ptr<IMemorySelector> MemorySelector;
} PoolAllocatorDependencyPack;

/*! \brief An allocator which has a preset pool of memory to draw from
* */
class PoolAllocator : public virtual ConfiguredAllocator<AllocatorConfig>, public virtual IAllocator
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
    PoolAllocator(const std::shared_ptr<AllocatorConfig> config, const std::shared_ptr<PoolAllocatorDependencyPack> dependencyPack);
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
    virtual void * Allocate(const MemoryConstraints& constraints) throw(std::bad_alloc) override;

    virtual bool TryDelete(void * pointer) noexcept override;
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