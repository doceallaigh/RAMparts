#pragma once

class IAllocator 
{
public:
    virtual void * Allocate (size_t size) = 0;

    virtual void Delete (void * object) = 0;
};