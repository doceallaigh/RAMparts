#include <string>
#include <iostream>

#include "../Header/GlobalAllocationContext.hpp"
#include "../Header/PoolAllocator.hpp"
#include "../Header/MemoryPool.hpp"
#include "../Header/MemoryPoolConfig.hpp"
#include "../Header/PoolAllocatorConfig.hpp"

int main (int numArgs, char *args[]) 
{
    GlobalAllocationContext::Initialize ();

    PoolAllocatorConfig<MemoryPoolConfig> config = PoolAllocatorConfig<MemoryPoolConfig>();
    config.PoolConfig = MemoryPoolConfig ();
    config.PoolConfig.PoolSize = 2048;

    std::shared_ptr<PoolAllocatorDependencyPack> poolAllocatorDependencyPack = nullptr; // std::make_shared<MemoryPool>(std::make_shared<MemoryPoolConfig>(config.PoolConfig));

    GlobalAllocationContext::SetAllocator<PoolAllocator<MemoryPoolConfig>>(std::make_shared<PoolAllocatorConfig<MemoryPoolConfig>>(config), poolAllocatorDependencyPack);

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
