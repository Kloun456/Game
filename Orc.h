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
    }
    string Hwo()
    {
        return " Orc ";
    }
};

