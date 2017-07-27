// INCLUDES
#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#include "../Header/PoolAllocator.hpp"
#pragma endregion

#pragma region Constants
const size_t tombstoneFlag = (std::numeric_limits<size_t>::max () / 2) + 1;
#pragma endregion

struct PoolAllocator::Pimpl_PoolAllocator
{
    void WriteSize (size_t size)
    {
        *(reinterpret_cast<size_t *>(this->nextAddress)) = size;
        this->nextAddress += sizeof (size_t);
    }

    void ReserveSpace (size_t size)
    {
        this->nextAddress += size;
    }

    // TODO Implement this
    byte * MergeSpace (byte * startAddress)
    {
        size_t blockSize = *(reinterpret_cast<size_t *>(startAddress));

        byte * neighboringBlock_p = this->GetPreviousBlockAddress (startAddress);
        size_t * neighboringBlockSize_p = reinterpret_cast<size_t *>(neighboringBlock_p);
        size_t neighboringBlockSize = *neighboringBlockSize_p;

        return 0;
    }

    static void MarkDeleted (byte * addressToMark)
    {
        *(reinterpret_cast<size_t *>(addressToMark)) |= tombstoneFlag;
    }

    byte * GetPreviousBlockAddress (byte* startAddress) const
    {
        if (startAddress == this->memoryArray)
        {
            return startAddress;
        }

        size_t previousBlockSize = *((reinterpret_cast<size_t *>(startAddress)) - 1);

        return startAddress - (previousBlockSize + 2 * sizeof (size_t *));
    }

    size_t size;
    byte *memoryArray;
    byte *nextAddress;
};

#pragma region Public Constructors & Destructor
// DEFAULT CONSTRUCTOR
PoolAllocator::PoolAllocator (void) : pimpl(std::make_unique<Pimpl_PoolAllocator> ()) { }

// COPY CONSTRUCTOR
// PoolAllocator::PoolAllocator (const PoolAllocator &original) { }

// MOVE CONSTRUCTOR
// PoolAllocator::PoolAllocator (const PoolAllocator &&original) noexcept { }

// CUSTOM CONSTRUCTORS
PoolAllocator::PoolAllocator (const AllocatorConfig& config) : PoolAllocator ()
{
    this->pimpl->size = config.AllocatorSize;
    this->pimpl->memoryArray = new byte[this->pimpl->size];
    this->pimpl->nextAddress = this->pimpl->memoryArray;
}

// DESTRUCTOR
PoolAllocator::~PoolAllocator (void) noexcept { }
#pragma endregion

#pragma region Operators
// COPY ASSIGNEMENT OPERATOR
// PoolAllocator& PoolAllocator::operator= (const PoolAllocator &original) { }

// MOVE ASSIGNEMENT OPERATOR
// PoolAllocator& PoolAllocator::operator= (PoolAllocator &&original) noexcept { }
#pragma endregion

#pragma region Public Virtual Methods
// PURE VIRTUAL METHODS
// VIRTUAL METHODS
#pragma endregion

#pragma region Public Non-virtual Methods
// NON-VOID METHODS
void * PoolAllocator::Allocate (size_t size) throw (std::bad_alloc)
{
    if (size >= tombstoneFlag)
    {
        throw std::bad_alloc ();
    }

    this->pimpl->WriteSize (size);

    void *pointer = this->pimpl->nextAddress;
    this->pimpl->ReserveSpace (size);

    this->pimpl->WriteSize (size);

    return pointer;
}

// VOID METHODS
void PoolAllocator::Delete (void * object)
{
    byte *addressToFree = (static_cast<byte *>(object)) - sizeof (size_t);

    this->pimpl->MergeSpace (addressToFree);
    this->pimpl->MarkDeleted (addressToFree);
}
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
// PoolAllocator (void);
#pragma endregion

#pragma region Private Virtual Methods
// PURE VIRTUAL METHODS
// VIRTUAL METHODS
#pragma endregion

#pragma region Private Non-virtual Methods
// NON-VOID METHODS
// VOID METHODS
#pragma endregion