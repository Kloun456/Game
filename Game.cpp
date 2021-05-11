#include <iostream>
#include <Windows.h>
#include "Warrior.h"
#include "Castle.h"
#include "Hero.h"
#include "Wizard.h"
#include "Forest.h"


using namespace std;

int main()
{
    
    int action;
    Hero* hero;
    Warrior war;
    Wizard wiz;
    cout << "Choose hero:\n1 - Warrior\n2 - Wizard\n";
    cin >> action;
    switch (action)
    {
    case 1:
        hero = &war;
        break;
    default:
        hero = &wiz;
        break;
    }
    
    cout << "\nChoose location:\n1 - Castle\n2 - Forest\n";
    cin >> action;
    Location *loc;
    Castle castle(hero);
    Forest forest(hero);
    switch (action)
    {
    case 1:
        loc = &castle;
        cout << "\nYou go to castle!\n";
        break;
    default:
        loc = &forest;
        cout << "\nYou go to forest!\n";
        break;
    }
    
    hero->Start_position(loc);
    loc->Show_admin_location();
    while (action && hero->Get_hp() > 0)
    {
        cout << "\nYour stat :\n";
        hero->Show_stat();
        loc->Show_location();
        cout << "\nChoose action:\n1 - Go up\n2 - Go down\n3 - Go left\n4 - Go right\n";
        cin >> action;
        system("cls");
        switch (action)
        {
        case 1:
            hero->Go_up(loc);
            break;
        case 2:
            hero->Go_down(loc);
            break;
        case 3:
            hero->Go_left(loc);
            break;
        case 4:
            hero->Go_right(loc);
            break;
        }
        action = loc->Check_position(hero);
        switch (action)
        {
        case 1:
            cout << "Monster\n";
            if (hero->Fight(loc->monster))
            {
                loc->Decrease_monsters();
                loc->monster->Restore();
            }
            break;
        case 2:
            cout << "Empty\n";
            break;
        case 3:
            cout << "Trap\n";
            loc->Trap_damage(hero);
            break;
        case 4:
            cout << "Treasure\n";
            break;
        case 5:
            cout << "You find exit: Go out?\n0 - Yes\n1 - No\n";
            cin >> action;
            hero->Cancel_action();
        }
        hero->Change_position(loc); 
    }
    if (!hero->Get_hp())
    {
        system("cls");
        cout << "\nYou die!\n";
    }
}