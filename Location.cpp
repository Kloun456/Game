#include "Location.h"
#include "Hero.h"
#include "HP_potion.h"
#include "MP_potion.h"
#include "Subject.h"

Location::Location(Hero *hero)
{
    srand(time(0));
    int temp;
    this->n = rand() % 2 + 3; // ðàçìåð îò 3 äî 4
    this->field = new string * [n];
    for (int i = 0; i < n; i++)
        this->field[i] = new string[n];

    lvl = hero->Get_lvl();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            temp = rand() % 4;
            if (!temp)
            {
                if (m < n)
                {
                    field[i][j] = objects[temp];
                    m++;
                }
                else
                    field[i][j] = objects[1];
            }
            else if (temp == 2)
            {
                if (trap < n - 1)
                {
                    field[i][j] = objects[temp];
                    trap++;
                }
                else
                    field[i][j] = objects[1];
            }
            else if (temp == 3)
            {
                if (tres < n - 1)
                {
                    field[i][j] = objects[temp];
                    tres++;
                }
                else
                    field[i][j] = objects[1];
            }
            else
                field[i][j] = objects[temp];
        }
    field[n - 1][n - 1] = "exit";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (field[i][j] == "empty")
            {
                field[i][j] = "player";
                i = n;
                break;
            }
}

Location::~Location()
{
    m = trap = tres = n = 0;
    for (int i = 0; i < n; i++)
        delete[] field[n];
    delete[] field;
}

void Location::Show_location()
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            if (field[i][j] == "player")
                cout << "you" << "\t";
            else if (field[i][j] == ".")
            {
                cout << ".\t";
            }
            else
                cout << "*\t";
        }
    }
    cout << endl;
}
    
void Location::Show_admin_location()
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
            cout << field[i][j] << "\t";
    }
    cout << endl;
}
    
int Location::Check_position(Hero *hero)
{
    for (int i = 0; i < 4; i++)
    {
        if (field[hero->pos_i][hero->pos_j] == objects[i])
            return i + 1;
        else if (field[hero->pos_i][hero->pos_j] == "exit")
            return 5;
    }
    return 2;
}

void Location::Get_player_position(int& position_i, int& position_j)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (field[i][j] == "player")
            {
                position_i = i;
                position_j = j;
            }
}

Subject *Location::Get_treasure()
{
    srand(time(0));
    int temp = rand() % 2;  // от 0 до 1
    Subject* subj;
    MP_potion potion1;
    HP_potion potion2;
    switch (temp)
    {
    case 0:
        subj = new MP_potion();
        break;
    default:
        subj = new HP_potion();
        break;
    }
    return subj;
    
}
