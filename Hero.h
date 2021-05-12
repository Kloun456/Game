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
    virtual void Taking_xp(Monster* monster) = 0;
    void Block()
    {
        this->armor += 2*lvl;
    }
    void unBlock()
    {
        this->armor -= 2*lvl;
    }
    void Use_subject();
    bool Show_inventory();
    void Add_subject(Subject *subject);
    void Start_position(Location* loc);
    void Change_position(Location* loc);
    void Taking_damage(Monster* monster);
    void Show_stat();
    bool Fight(Monster* monster);
    int Get_lvl() { return lvl; }
    int Get_hp() { return hp; }
protected:
    Weapon *weapon;
    vector<Subject *> subjects; // inventory 5 items
    friend class Location;
    friend class Castle;
    friend class Forest;
    friend class MP_potion;
    friend class HP_potion;
    int xp, lvl, hp, mp, atack, armor, pos_i, pos_j, temp_pos_i, temp_pos_j, temp_hp, temp_mp;
};

