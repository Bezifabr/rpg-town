#ifndef TOWN_H
#define TOWN_H

#include <map>
#include <vector>
#include <string>
#include "Building.h"

class Town
{
std::string name;

std::map<std::string, int> resources;
std::vector<Building> buildings;

public:

    void setName(const std::string& name);
    const std::string& getName();
    
    void addResource(const std::string& name, int amount);
    int checkResource(const std::string& name);

    const std::vector<Building>& getBuildings();
    void addBuilding(Building building);


};

#endif // TOWN_H