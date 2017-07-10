#pragma once
#include <memory>
#include <vector>
#include "IAllocator.hpp"

class GlobalAllocationContext
{
public:
    static void Initialize (void);

    template <typename TAllocator, typename ... TParams>
    static void SetAllocator (TParams ... params)
    {
        // TODO Move this out to a TPP
        GlobalAllocationContext::p_allocators->push_back (std::make_unique<TAllocator> (params ...));
    }

    static std::unique_ptr<IAllocator>& GlobalAllocationContext::GetActiveAllocator (void);

    static void UnsetAllocator ();

    static bool initialized;

private:
    static std::unique_ptr<std::vector<std::unique_ptr<IAllocator>>> p_allocators;
};
