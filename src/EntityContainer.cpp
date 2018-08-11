#include "EntityContainer.h"

EntityId EntityContainer::Add(std::string name)
{
    std::shared_ptr<Entity> ptr = std::make_shared<Entity>(name);
    entityLookup.insert({ptr->GetId(), entities.size() });
    entities.push_back(ptr);
    return ptr->GetId();
}

std::weak_ptr<Entity> EntityContainer::Get(EntityId id)
{
    auto itr = entityLookup.find(id);
    if (itr != entityLookup.end())
        return std::weak_ptr<Entity>(entities[itr->second]);
    else
        return std::weak_ptr<Entity>();
}

void EntityContainer::Remove(EntityId id)
{
    auto itr = entityLookup.find(id);
    if (itr != entityLookup.end())
    {
        EntityVectorIndex index = itr->second;
        EntityId back = entities.back()->GetId();

        std::swap(entities[index], entities.back());
        entities.pop_back();

        entityLookup[back] = index;
        entityLookup.erase(id);

    }
}
