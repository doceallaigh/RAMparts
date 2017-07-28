#include <string>
#include <iostream>

#include "../Header/GlobalAllocationContext.hpp"
#include "../Header/PoolAllocator.hpp"
#include "../Header/PartitionedMemoryPool.hpp"

int main (int numArgs, char *args[]) 
{
    GlobalAllocationContext::Initialize ();

    PoolAllocatorConfig config = PoolAllocatorConfig ();
    config.PoolConfig = MemoryPoolConfig ();
    config.PoolConfig.PoolSize = 2048;

    std::shared_ptr<IMemoryPool> memoryPool = std::make_shared<PartitionedMemoryPool> (std::make_shared<MemoryPoolConfig>(config.PoolConfig));

    GlobalAllocationContext::SetAllocator<PoolAllocator, const std::shared_ptr<PoolAllocatorConfig>, std::shared_ptr<IMemoryPool>>(std::make_shared<PoolAllocatorConfig>(config), memoryPool);

    std::string *s = new std::string();

    *s = "test";

    std::cout << "String object size: " << sizeof (*s) << std::endl;

    *s = "thisIsALongString";

    std::cout << "Second allocate offset: " << (int)((int)&((*s)[0]) - (int)s) << std::endl;

    *s = "thisIsALongStringToTestTheAddressthisIsALongStringToTestTheAddressthisIsALongStringToTestTheAddressthisIsALongStringToTestTheAddressthisIsALongStringToTestTheAddress";

    std::cout << "Second allocate offset: " << (int)((int)&((*s)[0]) - (int)s) << std::endl;

    delete s;
    GlobalAllocationContext::UnsetAllocator ();
}
