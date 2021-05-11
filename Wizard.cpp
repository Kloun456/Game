#include "Wizard.h"

void Wizard::Show_atacks()
{
    switch (lvl)
    {
    case 1:
        cout << "1 - Blow\n2 - Reinforced blow(lock)\n3 - Super blow(lock)\n4 - Block\n";
        break;
    case 2:
        cout << "1 - Blow\n2 - Reinforced blow (15 mp)\n3 - Super blow(lock)\n4 - Block\n";
        break;
    case 3:
        cout << "1 - Blow\n2 - Reinforced blow (15 mp)\n3 - Super blow (35 mp)\n4 - Block\n";
        break;
    }
}

bool Wizard::Reinforced_blow(Monster* monster)
{

    if (lvl < 2)
    {
        cout << "Small level!\n" << endl;
        return 0;
    }
    else
    {
        monster->hp -= weapon->Hit() + atack + 15 - monster->armor;
        if (mp >= 15)
            mp -= 15;
        else
        {
            cout << "\nNot enough mana!\n";
            return 0;
        }
        return 1;
    }
}

bool Wizard::Super_blow(Monster* monster)
{
    if (lvl < 3)
    {
        cout << "Small level!\n" << endl;
        return 0;
    }
    else
    {
        monster->hp -= weapon->Hit() + atack + 30 - monster->armor;
        if (mp >= 35)
            mp -= 35;
        else
        {
            cout << "\nNot enough mana!\n";
            return 0;
        }
        return 1;
    }
}