#pragma once
#include "Location.h"
#include "Hero.h"
#include "Orc.h"

class Forest :
    public Location
{
public:
    Orc orc{ lvl };
    Forest(Hero* hero) : Location(hero)
    {
        monster = &orc;
    }
    void Trap_damage(Hero* hero)
    {
        hero->hp -= 6;
    }
};