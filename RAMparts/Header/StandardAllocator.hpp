#pragma once
#include "Interfaces/IAllocator.hpp"

class StandardAllocator : public virtual IAllocator
{
    virtual void * Allocate (size_t size) override;

    virtual void Delete (void * object) override;
};
