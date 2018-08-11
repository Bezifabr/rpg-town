#ifndef ENTITY_H
#define ENTITY_H

#include <queue>
#include <string>
#include <array>
#include <bitset>
#include <assert.h>
#include <memory>
#include "Component.h"

constexpr std::size_t maxComponents{32};
using ComponentBitset = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

using EntityId = unsigned long int;


class Entity
{
    EntityId id;
    static std::queue<EntityId> removedIds;

    std::string name;

    bool alive = true;

    std::vector<std::unique_ptr<Component>> components;
    ComponentArray array;
    ComponentBitset bitset;

public:
    Entity(std::string name);
    ~Entity();

    EntityId GetId() const {return id; }
    std::string GetName() const { return name; }
    bool IsAlive() const { return alive; }
    void Destroy() { alive = false; }

    void Refresh();
    void Update(sf::Time elapsedTime);
    void HandleEvent(sf::Event event);
    void Draw(sf::RenderTarget& target);

    template <typename T>
    bool HasComponent() const
    {
        return bitset[GetComponentTypeId<T>()];
    }

    template <typename T, typename... TArgs>
    T& AddComponent(TArgs&&... args)
    {
        assert(!HasComponent<T>());

        T* comp(new T(std::forward<TArgs>(args)...));
        comp->entity = this;
        std::unique_ptr<Component> ptr{comp};
        components.emplace_back(std::move(ptr));

        array[GetComponentTypeId<T>()] = comp;
        bitset[GetComponentTypeId<T>()] = true;

        comp->Init();
        return *comp;
    }

    template <typename T>
    T& GetComponent() const
    {
        assert(HasComponent<T>());
        auto ptr(array[GetComponentTypeId<T>()]);
        return *reinterpret_cast<T*>(ptr);
    }

private:
    inline EntityId GetUniqueEntityId()
    {
        static EntityId id{0u};
        return id++;
    }
};

#endif // ENTITY_H
