#include <string>
#include <iostream>

#include "GlobalAllocationContext.hpp"
#include "PoolAllocator.hpp"
#include "AllocatorConfig.hpp"

int main (int numArgs, char *args[]) 
{
    GlobalAllocationContext::Initialize ();

    AllocatorConfig config = AllocatorConfig ();
    config.AllocatorSize = 2048;
    GlobalAllocationContext::SetAllocator<PoolAllocator, AllocatorConfig&>(config);

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