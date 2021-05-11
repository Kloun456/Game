#pragma once
#include "Location.h"
#include "Hero.h"
#include "Demon.h"
class Castle :
    public Location
{
public:
    Demon demon{ lvl };
    Castle(Hero *hero): Location(hero)
    {
        monster = &demon;
    }
    void Trap_damage(Hero* hero)
    {
        hero->hp -= 7;
    }
};

