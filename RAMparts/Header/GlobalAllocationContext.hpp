/* GlobalAllocationContext.hpp
 * Class description:
 *     The purpose of this class is to control the application-wide default allocation behavior, by replacing the 
 *     global new and delete operators with alternatives defined in a custom allocator.
 * * */

#pragma once

#pragma region Library Includes
#include <memory>
#include <vector>
#pragma endregion

#pragma region Local Includes
#include "Interfaces/IAllocator.hpp"
#pragma endregion

#ifndef GlobalAllocationContext_hpp
#define GlobalAllocationContext_hpp

#pragma region Forward Declarations
#pragma endregion

#pragma region Type Definitions
#pragma endregion

class GlobalAllocationContext
{
public:
#pragma region Public Constructors & Destructor
    // DEFAULT CONSTRUCTOR
    // GlobalAllocationContext (void);

    // COPY CONSTRUCTOR
    // GlobalAllocationContext (const GlobalAllocationContext &original);

    // MOVE CONSTRUCTOR
    // GlobalAllocationContext (const GlobalAllocationContext &&original) noexcept;

    // DESTRUCTOR
    // ~GlobalAllocationContext (void) noexcept;
#pragma endregion

#pragma region Operators
    // COPY ASSIGNEMENT OPERATOR
    // GlobalAllocationContext& operator= (const GlobalAllocationContext &original);

    // MOVE ASSIGNEMENT OPERATOR
    // GlobalAllocationContext& operator= (GlobalAllocationContext &&original) noexcept;
#pragma endregion

#pragma region Public Virtual Methods
    // PURE VIRTUAL METHODS
    // VIRTUAL METHODS
#pragma endregion

#pragma region Public Non-virtual Methods
    // NON-VOID METHODS
    static std::unique_ptr<IAllocator>& GlobalAllocationContext::GetActiveAllocator (void);
    // VOID METHODS
    template <typename TAllocator, typename ... TParams>
    static void SetAllocator (TParams ... params)
    {
        // TODO Move this out to a TPP
        GlobalAllocationContext::p_allocators->push_back (std::make_unique<TAllocator> (params ...));
    }

    static void Initialize (void);
    static void UnsetAllocator (void);
#pragma endregion

#pragma region Public Fields
    // SERVICES
    // COLLECTIONS
    // OBJECTS
    // PRIMITIVES
    static bool initialized;
#pragma endregion

protected:
#pragma region Protected Virtual Methods
    // PURE VIRTUAL METHODS
    // VIRTUAL METHODS
#pragma endregion

#pragma region Protected Non-virtual Methods
    // NON-VOID METHODS
    // VOID METHODS
#pragma endregion

#pragma region Protected Fields
    // SERVICES
    // COLLECTIONS
    // OBJECTS
    // PRIMITIVES
#pragma endregion

private:
#pragma region Private Constructors
    // DEFAULT CONSTRUCTOR
    // GlobalAllocationContext (void);
#pragma endregion

#pragma region Private Virtual Methods
    // PURE VIRTUAL METHODS
    // VIRTUAL METHODS
#pragma endregion

#pragma region Private Non-virtual Methods
    // NON-VOID METHODS
    // VOID METHODS
#pragma endregion

#pragma region Private Fields
    // SERVICES
    // COLLECTIONS
    static std::unique_ptr<std::vector<std::unique_ptr<IAllocator>>> p_allocators;
    // OBJECTS
    // PRIMITIVES
#pragma endregion
};
#endif // !GlobalAllocationContext_hpp