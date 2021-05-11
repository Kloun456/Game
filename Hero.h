#pragma once
#include "Weapon.h"
#include "Location.h"
#include "Monster.h"
#include "Subject.h"
#include <list>

class Hero
{
public:
    Hero()
    {
        xp = 0;
        lvl = 1;
    }
    void Go_up(Location* loc);
    void Go_down(Location* loc);
    void Go_left(Location* loc);
    void Go_right(Location* loc);
    void Cancel_action();
    void Blow(Monster *monster);
    virtual bool Reinforced_blow(Monster* monster) = 0;
    virtual bool Super_blow(Monster* monster) = 0;
    virtual void Show_atacks() = 0;
    void Block()
    {
        this->armor += 2*lvl;
    }
    void unBlock()
    {
        this->armor -= 2*lvl;
    }
    void Use_subject();
    void Show_subjects();
    void Add_subject();
    void Start_position(Location* loc);
    void Change_position(Location* loc);
    void Taking_damage(Monster* monster);
    void Taking_xp(Monster* monster);
    void Show_stat();
    bool Fight(Monster* monster);
    int Get_lvl() { return lvl; }
    int Get_hp() { return hp; }
protected:
    Weapon *weapon;
    list<Subject> subjects;
    friend class Location;
    friend class Castle;
    friend class Forest;
    int xp, lvl, hp, mp, atack, armor, pos_i, pos_j, temp_pos_i, temp_pos_j;
};

