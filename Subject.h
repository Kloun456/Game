#pragma once
#include <string>
class Hero;

using namespace std;

class Subject
{
public:
	virtual string Show_subject() = 0;
	int Get_ident() { return this->ident; }
	virtual void Use(Hero* hero) = 0;
protected:
	int ident;
};
