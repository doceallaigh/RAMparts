/* ConfiguredAllocator.hpp
 * Class description:
 *     <ConfiguredAllocator description goes here>
 * * */

#pragma once

#pragma region Library Includes
#pragma endregion

#pragma region Local Includes
#include "Interfaces/IAllocator.hpp"
#pragma endregion

#ifndef ConfiguredAllocator_hpp
#define ConfiguredAllocator_hpp

#pragma region Forward Declarations
#pragma endregion

template <typename TConfig>
class ConfiguredAllocator : public virtual IAllocator
{
public:
#pragma region Public Constructors & Destructor
    // DEFAULT CONSTRUCTOR
    // ConfiguredAllocator (void);

    // CUSTOM CONSTRUCTORS
    ConfiguredAllocator<TConfig> (const std::shared_ptr<AllocatorConfig> config) : config(config) {}

    // COPY CONSTRUCTOR
    // ConfiguredAllocator (const ConfiguredAllocator &original);

    // MOVE CONSTRUCTOR
    // ConfiguredAllocator (const ConfiguredAllocator &&original) noexcept;

    // DESTRUCTOR
    // ~ConfiguredAllocator (void) noexcept;
#pragma endregion

#pragma region Operators
    // COPY ASSIGNEMENT OPERATOR
    // ConfiguredAllocator& operator= (const ConfiguredAllocator &original);

    // MOVE ASSIGNEMENT OPERATOR
    // ConfiguredAllocator& operator= (ConfiguredAllocator &&original) noexcept;
#pragma endregion

#pragma region Public Virtual Methods
    // PURE VIRTUAL METHODS
    // VIRTUAL METHODS
#pragma endregion

#pragma region Public Non-virtual Methods
    // NON-VOID METHODS
    // VOID METHODS
#pragma endregion

#pragma region Public Fields
    // SERVICES
    // COLLECTIONS
    // OBJECTS
    // PRIMITIVES
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
    const std::shared_ptr<TConfig> config;
    // PRIMITIVES
#pragma endregion

private:
#pragma region Private Constructors
    // DEFAULT CONSTRUCTOR
    // Allocator (void);
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
    // OBJECTS
    // PRIMITIVES
#pragma endregion
};
#endif // !ConfiguredAllocator_hpp