#include "Structure.h"

void Structure::SetType(StructureType type)
{
    this->type = type;
}

StructureType Structure::GetType()
{
    return this->type;
}

void Structure::SetCost(uint8_t cost)
{
    this->cost = cost;
}

uint8_t Structure::GetCost()
{
    return cost;
}