#pragma once
#include "Hero.h"
#include "Stick.h"
class Wizard :
    public Hero
{
public:
    Stick stick;
    Wizard() : Hero()
    {
        atack = 22;
        hp = 80;
        mp = 100;
        armor = 4;
        weapon = &stick;
    }
    void Show_atacks();
    bool Reinforced_blow(Monster* monster);
    bool Super_blow(Monster* monster);
};