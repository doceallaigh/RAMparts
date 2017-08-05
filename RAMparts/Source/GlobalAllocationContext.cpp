#pragma region Library Includes
#include <vector>
#pragma endregion

#pragma region Local Includes
#include "../Header/GlobalAllocationContext.hpp"
#include "../Header/MemoryConstraints.hpp"
#include "../Header/StandardAllocator.hpp"
#pragma endregion

#pragma region Constants
#pragma endregion

#pragma region Static Fields
bool GlobalAllocationContext::initialized = false;

std::unique_ptr<std::vector<std::unique_ptr<IAllocator>>> GlobalAllocationContext::p_allocators = nullptr;
#pragma endregion

#pragma region Operators
#pragma endregion

#pragma region Custom Constructors
#pragma endregion

#pragma region Standard Constructors & Destructor
#pragma endregion

#pragma region Private Constructors
#pragma endregion

#pragma region Public Methods
std::unique_ptr<IAllocator>& GlobalAllocationContext::GetActiveAllocator(void)
{
    std::unique_ptr<IAllocator>& allocator = GlobalAllocationContext::p_allocators->back();
    return allocator;
}

void GlobalAllocationContext::Initialize()
{
    GlobalAllocationContext::p_allocators = std::make_unique<std::vector<std::unique_ptr<IAllocator>>>();

    // TODO This is currently only necessary due to an issue that arrises when the vector resizes itself on a push.  This should be fixed holistically, not patched.
    GlobalAllocationContext::p_allocators->reserve(10000);
    GlobalAllocationContext::SetAllocator<StandardAllocator>();

    GlobalAllocationContext::initialized = true;
}

void GlobalAllocationContext::UnsetAllocator(void)
{
    std::unique_ptr<IAllocator>& allocator = GlobalAllocationContext::p_allocators->back();
    GlobalAllocationContext::p_allocators->pop_back();
    allocator.reset();
}
#pragma endregion

#pragma region Protected Methods
#pragma endregion

#pragma region Private Methods
#pragma endregion

#pragma region Global Operator Replacements
void * operator new(size_t size)
{
    // TODO Figure out a way around this
    if (!GlobalAllocationContext::initialized)
    {
        return malloc (size);
    }

    std::unique_ptr<IAllocator>& allocator = GlobalAllocationContext::GetActiveAllocator ();

    MemoryConstraints constraints = MemoryConstraints();
    constraints.MinimumSize = size;

    return allocator->Allocate (constraints);
}

void operator delete(void *pointer)
{
    // TODO_HIGH This currently fails when deleting GlobalAllocationContext.  This could be fixed by making this class a singleton and creating custom new and delete operators for it.
    std::unique_ptr<IAllocator>& allocator = GlobalAllocationContext::GetActiveAllocator ();
    
    if(!allocator->TryDelete(pointer))
    {
        throw std::bad_alloc();
    }
}

void operator delete[](void *object)
{
    // TODO Implement
}

void operator delete[](void *object, size_t size)
{
    // TODO Implement
}
#pragma endregion