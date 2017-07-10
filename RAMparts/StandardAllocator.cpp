#include "StandardAllocator.hpp"
#include <cstdlib>

void * StandardAllocator::Allocate(size_t size)
{
    return malloc (size);
}

void StandardAllocator::Delete (void * pointer)
{
    free (pointer);
}