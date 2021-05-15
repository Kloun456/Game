#pragma once
#include "Monster.h"
class Demon :
    public Monster
{
public:
    Demon(int lvl) : Monster(lvl)
    {
        hp = lvl * 100;
        atack = 5 + lvl * 5;
        armor = 2 + lvl * 2;
        temp_hp = hp;`
    }
    string Hwo()
    {
        return " Demon ";
    }
};

