#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#include "Interfaces/IAllocator.hpp"
#include "ConfiguredAllocator.hpp"
#pragma endregion

#pragma region Forward Declarations
class IMemoryPool;
struct PoolAllocatorConfig;
#pragma endregion

#pragma region Type Definitions
#pragma endregion

/*! \brief <Brief description goes here>
*
* <Detailed description goes here>
* */
class PoolAllocator : public virtual ConfiguredAllocator<PoolAllocatorConfig>, public virtual IAllocator
{
public:
#pragma region Operators
    //! \cond \brief Copy assignment operator \endcond
    // PoolAllocator& operator= (const PoolAllocator &original);

    //! \cond \brief Move assignment operator \endcond
    // PoolAllocator& operator= (PoolAllocator &&original) noexcept;
#pragma endregion

#pragma region Custom Constructors
    /*! \brief <Brief description goes here>
    *
    * \param[in] <Parameter description goes here>
    * */
    PoolAllocator(const std::shared_ptr<PoolAllocatorConfig> config, std::shared_ptr<IMemoryPool> memoryPool);
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
    std::shared_ptr<IMemoryPool> memoryPool;
#pragma endregion

private:
#pragma region Private Fields
#pragma endregion
};