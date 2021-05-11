#pragma once
#include "Weapon.h"
class Sword :
    public Weapon
{
public:
    Sword()
    {
        damage = 5;
        critical_damage = 3;
    }
};

