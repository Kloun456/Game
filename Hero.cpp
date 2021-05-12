#include "Hero.h"

void Hero::Go_down(Location *loc)
{
    if (pos_i < loc->Get_Size() - 1)
    {
        loc->field[pos_i][pos_j] = ".";
        temp_pos_i = pos_i;
        temp_pos_j = pos_j;
        pos_i++;
    }
    else
        cout << "Impossible to pass!" << endl;
}

void Hero::Go_up(Location* loc)
{
    if (pos_i > 0)
    {
        loc->field[pos_i][pos_j] = ".";
        temp_pos_i = pos_i;
        temp_pos_j = pos_j;
        pos_i--;
    }
    else
        cout << "Impossible to pass!" << endl;
}

void Hero::Go_left(Location* loc)
{
    if (pos_j > 0)
    {
        loc->field[pos_i][pos_j] = ".";
        temp_pos_j = pos_j;
        temp_pos_i = pos_i;
        pos_j--;
    }
    else
        cout << "Impossible to pass!" << endl;
}

void Hero::Go_right(Location* loc)
{
    if (pos_j < loc->Get_Size() - 1)
    {
        loc->field[pos_i][pos_j] = ".";
        temp_pos_j = pos_j;
        temp_pos_i = pos_i;
        pos_j++;
            
    }
    else
        cout << "Impossible to pass!" << endl;
}

void Hero::Taking_xp(Monster *monster)
{
    xp += monster->lvl * 50;
    if (xp >= lvl * 100)
    {
        xp = xp - lvl * 100;
        lvl++;
    }
}

void Hero::Blow(Monster *monster)
{
    
    monster->hp -= weapon->Hit() + atack - monster->armor;
}

void Hero::Taking_damage(Monster* monster)
{
    hp -= monster->atack - armor;
}

void Hero::Show_stat()
{
    cout << "HP = " << hp << " MP = " << mp << " lvl = " << lvl << endl;
    cout << "Atack(+dop) = " << atack << "+" << weapon->damage << " Armor = " << armor << endl;
}

bool Hero::Fight(Monster* monster)
{
int action;
    cout << "Fight!\n";
    while (hp > 0 && monster->hp > 0)
    {
        cout << "\nYour stat:\n";
        Show_stat();
        cout << "\n" << monster->Hwo() << " stat:\n";
        monster->Show_stat();
        cout << "\nChose your action:\n";
        Show_atacks();
        cin >> action;
        system("cls");
        switch (action)
        {
        case 1:
            Blow(monster);
            Taking_damage(monster);
            break;
        case 2:
            if (Reinforced_blow(monster))
                Taking_damage(monster);
            break;
        case 3:
            if (Super_blow(monster))
                Taking_damage(monster);
            break;
        case 4:
            Block();
            Taking_damage(monster);
            unBlock();
            break;
        case 5:
            if (this->Show_inventory())
                Use_subject();
            break;
        }
    }
    if (hp)
        return 1;
    else
        return 0;
}

void Hero::Start_position(Location* loc)
{
    loc->Get_player_position(pos_i, pos_j);
}

void Hero::Change_position(Location* loc)
{
    loc->field[pos_i][pos_j] = "player";
}

void Hero::Cancel_action()
{
    pos_i = temp_pos_i;
    pos_j = temp_pos_j;
}

void Hero::Add_subject(Subject *subject)
{
    int i;
    if (subjects.size() < 5)
    {
        subjects.push_back(subject); 
    }
    else
    {
        cout << "\nNot enough space in inventory\n";
        cout << "\nChoose subject, which you want to change:\n";
        this->Show_inventory();
        cin >> i;
        i--;
        auto it = subjects.begin();
        it += i;
        subjects.erase(it);
        this->Add_subject(subject);
    }
}

bool Hero::Show_inventory()
{
    if (this->subjects.empty())
    {
        cout << "\nInventory is empty!\n";
        return 0;
    }
    else
    {
        int i = 1;
        for (auto &it : subjects)
        {
            cout << "\n" << i << " - " << it->Show_subject();
            i++;
        }
        cout << endl;
        return 1;
    }
}

void Hero::Use_subject()
{
    int i;
    cout << "\nChoose subject, which you want to use.\n";
    cin >> i;
    auto it = subjects.begin();
    i--;
    it += i;
    subjects[i]->Use(this);
    subjects.erase(it);
}
