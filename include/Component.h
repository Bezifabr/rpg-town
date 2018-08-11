#ifndef COMPONENT_H
#define COMPONENT_H

#include <cstdio>
#include <type_traits>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>


using ComponentID = std::size_t;

class Entity;

struct Component
{
    Entity* entity;

    virtual void Init() {}
    virtual void Refresh() {}
    virtual void Update(sf::Time elapsedTime) {}
    virtual void HandleEvent(sf::Event event) {}
    virtual void Draw(sf::RenderTarget& target) {}

    virtual ~Component() {}
};


inline ComponentID GetUniqueComponentId() noexcept
{
    static ComponentID lastId{0u};
    return lastId++;
}

template <typename T>
inline ComponentID GetComponentTypeId() noexcept
{
    static_assert(std::is_base_of<Component, T>::value,
        "T must inherit from EntityComponent");

    static ComponentID typeId{GetUniqueComponentId()};
    return typeId;
}




#endif // COMPONENT_H
