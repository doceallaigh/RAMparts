#include <cstdlib>
#include "../Header/StandardAllocator.hpp"

void * StandardAllocator::Allocate(size_t size)
{
    return malloc (size);
}

void StandardAllocator::Delete (void * pointer)
{
    free (pointer);
}