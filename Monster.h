#pragma once
#include <iostream>

using namespace std;

class Monster
{
public:
	Monster(int lvl)
	{
		this->lvl = lvl;
	}
	virtual void Show_stat()
	{
		cout << "HP = " << hp << " lvl = " << lvl << endl;
		cout << "Atack = " << atack << " Armor = " << armor << endl;
	}
	virtual string Hwo() = 0;
	void Restore()
	{
		hp = temp_hp;
		atack = temp_atack;
		armor = temp_armor;
	}
protected:
	friend class Hero;
	friend class Warrior;
	friend class Wizard;
	int hp, lvl, atack, armor, temp_hp, temp_atack, temp_armor;
};