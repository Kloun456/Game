#include <iostream>
#include <string>
#include "Monster.h"

class Subject;
class Hero;

using namespace std;

class Location
{
public:
    Monster *monster;
    Location(Hero *hero);
    ~Location();
    virtual void Trap_damage(Hero *hero) = 0;
    void Show_location(); 
    void Show_admin_location();
    int Check_position(Hero *hero);
    void Get_player_position(int& position_i, int& position_j); 
    Subject *Get_treasure();
    int Get_Size() { return this->n; }
    int Get_lvl() { return lvl; }
    void Decrease_monsters() { this->m--; }
protected:
    string** field,objects[4] = { "monster","empty","trap","treasure" };
    string Treasures[2] = {"MP potion","HP potion"};
    friend class Hero;
    int m = 0, trap = 0, tres = 0, n, lvl; // m - quantity monsters, tres - treasure
};
