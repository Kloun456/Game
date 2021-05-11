#include "Warrior.h"

void Warrior::Show_atacks()
{
    switch (lvl)
    {
    case 1:
        cout << "1 - Blow\n2 - Reinforced blow(lock)\n3 - Super blow(lock)\n4 - Block\n";
        break;
    case 2:
        cout << "1 - Blow\n2 - Reinforced blow (5 mp)\n3 - Super blow(lock)\n4 - Block\n";
        break;
    case 3:
        cout << "1 - Blow\n2 - Reinforced blow (5 mp)\n3 - Super blow (20 mp)\n4 - Block\n";
        break;
    }
}

bool Warrior::Reinforced_blow(Monster* monster)
{
    
    if (lvl < 2)
    {
        cout << "Small level!\n" << endl;
        return 0;
    }
    else
    {
        monster->hp -= weapon->Hit() + atack + 10 - monster->armor;
        if (mp >= 5)
            mp -= 5;
        else
        {
            cout << "\nNot enough mana!\n";
            return 0;
        }
        return 1;
    }
}

bool Warrior::Super_blow(Monster* monster)
{
    if (lvl < 3)
    {
        cout << "Small level!\n" << endl;
        return 0;
    }
    else
    {
        monster->hp -= weapon->Hit() + atack + 20 - monster->armor;
        if (mp >= 20)
            mp -= 20;
        else
        {
            cout << "\nNot enough mana!\n";
            return 0;
        }
        return 1;
    }
}