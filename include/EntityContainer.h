#ifndef GESFML_ENTITY_CONTAINER_H
#define GESFML_ENTITY_CONTAINER_H

#include "Entity.h"
#include <memory>
#include <vector>
#include <unordered_map>

using EntityVector = std::vector<std::shared_ptr<Entity>>;
using EntityVectorIndex = EntityVector::size_type;

class EntityContainer
{
    EntityVector entities;
    std::unordered_map<EntityId, EntityVectorIndex> entityLookup;
public:
    EntityId Create(std::string name);
	EntityId Add(std::shared_ptr<Entity> entity);

    std::weak_ptr<Entity> Get(EntityId id);
    void Remove(EntityId id);

	std::weak_ptr<Entity> GetLastCreatedEntity();

	void RemoveEntities();
    const EntityVector & GetEntities() const { return entities; }
};
#endif // GESFML_ENTITY_CONTAINER_H
