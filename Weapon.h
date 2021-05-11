#pragma once
#include <time.h>
#include <iostream>

class Weapon
{
public:
	Weapon()
	{
		damage = critical_damage = 0;
	}
	int Hit()
	{
		if (rand() % 2)
			return damage + critical_damage;
		else
			return damage;
	}
protected:
	friend class Hero;
	int damage, critical_damage;
};

