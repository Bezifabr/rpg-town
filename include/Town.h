#ifndef TOWN_H
#define TOWN_H

#include <map>
#include <vector>
#include <string>
#include "Building.h"

class Town
{
std::string name;
int maxNumberOfBuildings;

int level = 1;


std::map<std::string, int> resources;
std::vector<Building> buildings;

public:

    void SetName(const std::string& name);
    const std::string& GetName();
    
    void AddResource(const std::string& name, int amount);
    int CheckResource(const std::string& name);

    const std::vector<Building>& GetBuildings();
    void AddBuilding(Building building);

    void SetLevel(int level);
    int GetLevel();

    int GetMaxAmountOfBuildings();

private:

    void FixToLevel();
    void SetMaxAmountOfBuildings();
};

#endif // TOWN_H