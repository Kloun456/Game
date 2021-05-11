#pragma once
#include "Hero.h"
#include "Sword.h"
class Warrior :
    public Hero
{
public:
    Sword sword;
    Warrior() : Hero()
    {
        atack = 20;
        hp = 100;
        mp = 50;
        armor = 6;
        weapon = &sword;
    }
    void Show_atacks();
    bool Reinforced_blow(Monster* monster);
    bool Super_blow(Monster* monster);
};

