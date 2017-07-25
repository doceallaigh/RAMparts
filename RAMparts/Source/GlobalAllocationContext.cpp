// INCLUDES
#pragma region Library Includes
#include <vector>
#pragma endregion

#pragma region Local Includes
#include "../Header/GlobalAllocationContext.hpp"
#include "../Header/StandardAllocator.hpp"
#pragma endregion

#pragma region Public Constructors & Destructor
// DEFAULT CONSTRUCTOR
// GlobalAllocationContext::GlobalAllocationContext (void) { }

// COPY CONSTRUCTOR
// GlobalAllocationContext::GlobalAllocationContext (const GlobalAllocationContext &original) { }

// MOVE CONSTRUCTOR
// GlobalAllocationContext::GlobalAllocationContext (const GlobalAllocationContext &&original) noexcept { }

// DESTRUCTOR
// GlobalAllocationContext::~GlobalAllocationContext (void) noexcept { }
#pragma endregion

#pragma region Operators
// COPY ASSIGNEMENT OPERATOR
// GlobalAllocationContext& GlobalAllocationContext::operator= (const GlobalAllocationContext &original) { }

// MOVE ASSIGNEMENT OPERATOR
// GlobalAllocationContext& GlobalAllocationContext::operator= (GlobalAllocationContext &&original) noexcept { }
#pragma endregion

#pragma region Public Virtual Methods
// PURE VIRTUAL METHODS
// VIRTUAL METHODS
#pragma endregion

#pragma region Public Non-virtual Methods
// NON-VOID METHODS
std::unique_ptr<IAllocator>& GlobalAllocationContext::GetActiveAllocator (void)
{
    std::unique_ptr<IAllocator>& allocator = GlobalAllocationContext::p_allocators->back ();
    return allocator;
}

// VOID METHODS
void GlobalAllocationContext::Initialize ()
{
    GlobalAllocationContext::p_allocators = std::make_unique<std::vector<std::unique_ptr<IAllocator>>> ();

    // TODO This is currently only necessary due to an issue that arrises when the vector resizes itself on a push.  This should be fixed holistically, not patched.
    GlobalAllocationContext::p_allocators->reserve (10000);
    GlobalAllocationContext::SetAllocator<StandardAllocator> ();

    GlobalAllocationContext::initialized = true;
}

void GlobalAllocationContext::UnsetAllocator (void)
{
    std::unique_ptr<IAllocator>& allocator = GlobalAllocationContext::p_allocators->back ();
    GlobalAllocationContext::p_allocators->pop_back ();
    allocator.reset ();
}
#pragma endregion

#pragma region Public Fields
bool GlobalAllocationContext::initialized = false;
#pragma endregion

#pragma region Protected Virtual Methods
// PURE VIRTUAL METHODS
// VIRTUAL METHODS
#pragma endregion

#pragma region Protected Non-virtual Methods
// NON-VOID METHODS
// VOID METHODS
#pragma endregion

#pragma region Private Constructors
// DEFAULT CONSTRUCTOR
// GlobalAllocationContext (void);
#pragma endregion

#pragma region Private Virtual Methods
// PURE VIRTUAL METHODS
// VIRTUAL METHODS
#pragma endregion

#pragma region Private Non-virtual Methods
// NON-VOID METHODS
// VOID METHODS
#pragma endregion

#pragma region Private Fields
std::unique_ptr<std::vector<std::unique_ptr<IAllocator>>> GlobalAllocationContext::p_allocators = nullptr;
#pragma endregion

void * operator new(size_t size)
{
    // TODO Figure out a way around this
    if (!GlobalAllocationContext::initialized)
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