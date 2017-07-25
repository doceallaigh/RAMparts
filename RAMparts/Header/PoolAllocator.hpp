#pragma once
#include <memory>
#include "AllocatorConfig.hpp"
#include "Interfaces/IAllocator.hpp"

typedef unsigned char byte;

class PoolAllocator : public IAllocator
{
public:
    PoolAllocator (const AllocatorConfig& config);

    virtual ~PoolAllocator ();

    void * IAllocator::Allocate (size_t size) override;

    void IAllocator::Delete (void * object) override;

    template <typename T>
    std::allocator<T> * GetAllocator (void)
    {
        return nullptr;
    }

private:
    PoolAllocator ();
    struct Pimpl_PoolAllocator;
    std::unique_ptr<Pimpl_PoolAllocator> pimpl;
};