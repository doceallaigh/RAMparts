/* IMemoryPointer.hpp
 * Interface description:
 *     <IMemoryPointer description goes here>
 * * */

#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#pragma endregion

#ifndef IMemoryPointer_hpp
#define IMemoryPointer_hpp

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

class IMemoryPointer 
{
public:
#pragma region Destructor
    virtual ~IMemoryPointer () = default;
#pragma endregion

#pragma region Public Methods
    virtual void * GetRawPointer(void) const = 0;

    virtual size_t GetSize(void) const = 0;

    virtual size_t GetAlignment(void) const = 0;

    virtual bool Overlaps(const IMemoryPointer& pointer) const = 0;

    virtual bool Contains(const void * pointer) const = 0;
#pragma endregion
};
#endif // !IMemoryPointer_hpp