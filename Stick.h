#pragma once
#include "Weapon.h"
class Stick :
    public Weapon
{
public:
    Stick()
    {
        damage = 10;
        critical_damage = 5;
    }
};

