#pragma once
#include "Monster.h"
class Orc :
    public Monster
{
public:
    Orc(int lvl) : Monster(lvl)
    {
        hp = lvl * 150;
        atack = 3 + lvl * 5;
        armor = 1 + lvl * 2;
        temp_hp = hp;
        temp_atack = atack;
        temp_armor = armor;
    }
    string Hwo()
    {
        return " Orc ";
    }
};

