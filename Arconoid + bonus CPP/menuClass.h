#pragma once
#include "physObjectClass.h"

class Menu : public PhysObject
{
private:
	int menuSize; //const

public:
	Menu();
	Menu(int menuSizex, int menuSizey, int menuPosy);
	~Menu();

	int getMenuSize();
};

class Hp : public PhysObject
{
public:
	Hp();
	Hp(int hpSizex, int hpSizey, int hpPosx, int hpPosy);
	~Hp();
};