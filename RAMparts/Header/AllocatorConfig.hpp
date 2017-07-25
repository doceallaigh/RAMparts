#pragma once


/* AllocatorConfig.hpp
 * Object description:
 *     The object defined here is a simple POD object used to configure memory allocators.
 *     It exists only to encapsulate the base parameters to which the allocator is to be set.
 * * */

#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#pragma endregion

#ifndef AllocatorConfig_hpp
#define AllocatorConfig_hpp

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

typedef struct AllocatorConfig
{
public:
    size_t AllocatorSize;
} AllocatorConfig;
#endif // !AllocatorConfig_hpp