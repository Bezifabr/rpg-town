#include "Town.h"

#include <iostream>

using std::cout;
using std::endl;

void Town::addResource(const std::string& name, int amount)
{
    if(name.empty())
        cout << "Warning [Town::addResources()]: amount of resources is equal 0." << endl;

    if(resources.count(name) == 0)
        resources[name] = 0;
    resources[name] += amount;
}

int Town::checkResource(const std::string& name)
{
    if(resources.count(name) == 0)
        {
            cout << "Data error [Town::checkResource()]: " << name << "is not a resource!" << endl;
            return 0;
        }
    return resources[name];
}

const std::vector<Building>& Town::getBuildings()
{
    if(buildings.empty())
        cout << "Data error [Town::getBuildings()]: Town " << name << " has no buildings!" << endl;
    return buildings;
}

void Town::setName(const std::string& name)
{
    if(name.empty())
        cout << "Warning [Town::setName()]: name is empty." << endl;
    this->name = name;
}

const std::string& Town::getName()
{
    return name;
}

void Town::addBuilding(Building building)
{
    buildings.push_back(building);
}
