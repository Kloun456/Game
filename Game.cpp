#include <iostream>
#include <Windows.h>
#include "Warrior.h"
#include "Castle.h"
#include "Hero.h"
#include "Wizard.h"
#include "Forest.h"
#include "Subject.h"

using namespace std;

int main()
{
    int action;
    Subject* subject;
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
        cout << "\nChoose action:\n1 - Go up\n2 - Go down\n3 - Go left\n4 - Go right\n5- Invetn\n";
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
        case 5:
            if (hero->Show_inventory())
            {
                cout << "\nYou want to use subject?\n1 - Yes\n2 - NO\n";
                cin >> action;
                if (action == 1)
                    hero->Use_subject();
            }
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
                hero->Taking_xp(loc->monster);
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
            subject = loc->Get_treasure();
            cout << "\nYou find treasure it`s " << subject->Show_subject();
            cout << "\nTake this treasure?\n1 - Yes\n2 - NO\n";
            cin >> action;
            if (action == 1)
                hero->Add_subject(subject);
            break;
        case 5:
            cout << "You find exit: Go out?\n1 - Yes\n2 - No\n";
            cin >> action;
            if (action == 1)
                action = 0;
            hero->Cancel_action();
            break;
        }
        hero->Change_position(loc); 
    }
    if (!hero->Get_hp())
    {
        system("cls");
        cout << "\nYou die!\n";
    }
}
