#include <vector>
#include "../Header/GlobalAllocationContext.hpp"
#include "../Header/StandardAllocator.hpp"

std::unique_ptr<std::vector<std::unique_ptr<IAllocator>>> GlobalAllocationContext::p_allocators = nullptr;
bool GlobalAllocationContext::initialized = false;

void GlobalAllocationContext::Initialize()
{
    GlobalAllocationContext::p_allocators = std::make_unique<std::vector<std::unique_ptr<IAllocator>>>();

    // TODO This is currently only necessary due to an issue that arrises when the vector resizes itself on a push.  This should be fixed holistically, not patched.
    GlobalAllocationContext::p_allocators->reserve (10000);
    GlobalAllocationContext::SetAllocator<StandardAllocator> ();

    GlobalAllocationContext::initialized = true;
}

std::unique_ptr<IAllocator>& GlobalAllocationContext::GetActiveAllocator(void)
{
    std::unique_ptr<IAllocator>& allocator = GlobalAllocationContext::p_allocators->back ();
    return allocator;
}

void GlobalAllocationContext::UnsetAllocator(void)
{
    std::unique_ptr<IAllocator>& allocator = GlobalAllocationContext::p_allocators->back ();
    GlobalAllocationContext::p_allocators->pop_back ();
    allocator.reset ();
}

void * operator new(size_t size)
{
    // TODO Figure out a way around this
    if(!GlobalAllocationContext::initialized)
    {
        return malloc (size);
    }

    std::unique_ptr<IAllocator>& allocator = GlobalAllocationContext::GetActiveAllocator ();
    return allocator->Allocate (size);
}

void operator delete(void *pointer)
{
    // TODO_HIGH This currently fails when deleting GlobalAllocationContext.  This could be fixed by making this class a singleton and creating custom new and delete operators for it.
    std::unique_ptr<IAllocator>& allocator = GlobalAllocationContext::GetActiveAllocator ();
    allocator->Delete (pointer);
}

void operator delete[](void *object)
{
    // TODO Implement
}

void operator delete[](void *object, size_t size)
{
    // TODO Implement
}