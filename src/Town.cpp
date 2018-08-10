#include "Town.h"

#include <iostream>

using std::cout;
using std::endl;

void Town::AddResource(const std::string& name, int amount)
{
    if(name.empty())
        cout << "Warning [Town::addResources()]: amount of resources is equal 0." << endl;

    if(resources.count(name) == 0)
        resources[name] = 0;
    resources[name] += amount;
}

int Town::CheckResource(const std::string& name)
{
    if(resources.count(name) == 0)
        {
            cout << "Data error [Town::checkResource()]: " << name << "is not a resource!" << endl;
            return 0;
        }
    return resources[name];
}

const std::vector<Building>& Town::GetBuildings()
{
    if(buildings.empty())
        cout << "Data error [Town::getBuildings()]: Town " << name << " has no buildings!" << endl;
    return buildings;
}

void Town::SetName(const std::string& name)
{
    if(name.empty())
        cout << "Warning [Town::setName()]: name is empty." << endl;
    this->name = name;
}

const std::string& Town::GetName()
{
    return name;
}

void Town::AddBuilding(Building building)
{
    buildings.push_back(building);
}

void Town::SetLevel(int level)
{
    this->level = level;

    FixToLevel();
}

int Town::GetLevel()
{
    return level;
}

void Town::FixToLevel()
{
    SetMaxAmountOfBuildings();
}

void Town::SetMaxAmountOfBuildings()
{
    maxNumberOfBuildings = 3 + level * 2;
}

int Town::GetMaxAmountOfBuildings()
{
    return maxNumberOfBuildings;
}