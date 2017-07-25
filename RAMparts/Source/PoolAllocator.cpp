#include "../Header/PoolAllocator.hpp"

const size_t tombstoneFlag = (std::numeric_limits<size_t>::max () / 2) + 1;

struct PoolAllocator::Pimpl_PoolAllocator
{
    void WriteSize (size_t size)
    {
        *((size_t *)this->nextAddress) = size;
        this->nextAddress += sizeof (size_t);
    }

    void ReserveSpace (size_t size)
    {
        this->nextAddress += size;
    }

    byte * MergeSpace (byte * startAddress)
    {
        size_t blockSize = *((size_t *)startAddress);

        byte * neighboringBlock_p = this->GetPreviousBlockAddress (startAddress);
        size_t * neighboringBlockSize_p = (size_t *)neighboringBlock_p;
        size_t neighboringBlockSize = *neighboringBlockSize_p;

        return 0;
    }

    void MarkDeleted (byte * addressToMark)
    {
        *((size_t *)addressToMark) |= tombstoneFlag;
    }

    byte * GetPreviousBlockAddress (byte* startAddress)
    {
        if (startAddress == this->memoryArray)
        {
            return startAddress;
        }

        size_t previousBlockSize = *((size_t *)startAddress - 1);

        return startAddress - (previousBlockSize + 2 * sizeof (size_t *));
    }

    size_t size;
    byte *memoryArray;
    byte *nextAddress;
};

PoolAllocator::PoolAllocator()
{
    this->pimpl = std::make_unique<Pimpl_PoolAllocator>();
}

PoolAllocator::PoolAllocator (const AllocatorConfig& config) : PoolAllocator()
{
    this->pimpl->size = config.AllocatorSize;
    this->pimpl->memoryArray = new byte[this->pimpl->size];
    this->pimpl->nextAddress = this->pimpl->memoryArray;
}

PoolAllocator::~PoolAllocator ()
{
}

void * PoolAllocator::Allocate (size_t size) throw (std::bad_alloc)
{
    if (size >= tombstoneFlag) 
    {
        throw std::bad_alloc ();
    }

    this->pimpl->WriteSize(size);

    void *pointer = this->pimpl->nextAddress;
    this->pimpl->ReserveSpace (size);

    this->pimpl->WriteSize (size);

    return pointer;
}

void PoolAllocator::Delete (void * object)
{
    byte *addressToFree = (byte *)object - sizeof (size_t);

    this->pimpl->MergeSpace (addressToFree);
    this->pimpl->MarkDeleted (addressToFree);
}