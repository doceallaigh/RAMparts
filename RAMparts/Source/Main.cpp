#include <string>
#include <iostream>

#include "../Header/GlobalAllocationContext.hpp"
#include "../Header/PoolAllocator.hpp"

int main (int numArgs, char *args[]) 
{
    GlobalAllocationContext::Initialize ();

    PoolAllocatorConfig config = PoolAllocatorConfig ();
    config.PoolConfig = MemoryPoolConfig ();
    config.PoolConfig.PoolSize = 2048;
    GlobalAllocationContext::SetAllocator<PoolAllocator, const std::shared_ptr<PoolAllocatorConfig>>(std::make_shared<PoolAllocatorConfig>(config));

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