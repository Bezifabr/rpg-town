#include "Entity.h"

std::queue<EntityId> Entity::removedIds;

Entity::Entity(std::string name) : name(name)
{
    if(!removedIds.empty())
    {
        id = removedIds.front();
        removedIds.pop();
    }
    else id = GetUniqueEntityId();
}

Entity::~Entity()
{
    removedIds.push(id);
}

void Entity::Refresh()
{
	if (!components.empty())
    for(auto& comp : components) comp->Refresh();
}

void Entity::Update(sf::Time elapsedTime)
{
	if(!components.empty())
    for(auto& comp : components) comp->Update(elapsedTime);
}

void Entity::HandleEvent(sf::Event event)
{
	if (!components.empty())
    for(auto& comp: components) comp->HandleEvent(event);
}

void Entity::Draw(sf::RenderTarget& target)
{
	if (!components.empty())
    for(auto& comp : components) comp->Draw(target);
}
