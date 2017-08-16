#include <string>
#include <iostream>

#include "../Header/GlobalAllocationContext.hpp"
#include "../Header/PoolAllocator.hpp"
#include "../Header/MemoryPool.hpp"
#include "../Header/PartitionedMemoryPoolConfig.hpp"
#include "../Header/AllocatorConfig.hpp"
#include "../Header/PartitionedMemoryPool.hpp"

int main (int numArgs, char *args[]) 
{
    GlobalAllocationContext::Initialize ();

    AllocatorConfig allocatorConfig = AllocatorConfig();
    PartitionedMemoryPoolConfig memoryPoolConfig = PartitionedMemoryPoolConfig();
    memoryPoolConfig.PoolSize = 2048;

    std::shared_ptr<PoolAllocatorDependencyPack> poolAllocatorDependencyPack = std::make_shared<PoolAllocatorDependencyPack>();
    poolAllocatorDependencyPack->MemoryPool = std::make_shared<PartitionedMemoryPool<PartitionedMemoryPoolConfig>>(std::make_shared<PartitionedMemoryPoolConfig>(memoryPoolConfig));
    poolAllocatorDependencyPack->MemorySelector = nullptr;
    poolAllocatorDependencyPack->ReservationTracker = nullptr;

    GlobalAllocationContext::SetAllocator<PoolAllocator>(std::make_shared<AllocatorConfig>(allocatorConfig), poolAllocatorDependencyPack);

    std::string *s = new std::string();

    *s = "test";

    std::cout << "String object size: " << sizeof (*s) << std::endl;

    *s = "thisIsALongString";

    std::cout << "Second allocate offset: " << static_cast<int>(reinterpret_cast<int>(&((*s)[0])) - reinterpret_cast<int>(s)) << std::endl;

    *s = "thisIsALongStringToTestTheAddressthisIsALongStringToTestTheAddressthisIsALongStringToTestTheAddressthisIsALongStringToTestTheAddressthisIsALongStringToTestTheAddress";

    std::cout << "Second allocate offset: " << static_cast<int>(reinterpret_cast<int>(&((*s)[0])) - reinterpret_cast<int>(s)) << std::endl;

    delete s;
    GlobalAllocationContext::UnsetAllocator ();
}
