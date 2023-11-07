#pragma once
#include "physObjectClass.h"

class Menu : public PhysObject
{
private:
	int menuSize = Param::MENU_SIZE;

public:
	Menu() {};
	Menu(int menuPosy, int menuSizex, int menuSizey) : PhysObject(0, menuPosy, menuSizex, menuSizey, 1.0, 1.0, 1.0) {};

	int getMenuSize() { return menuSize; };
};

class Hp : public PhysObject
{
public:
	Hp() {};
	Hp(int hpPosx, int hpPosy, int hpSizex, int hpSizey) : PhysObject(hpPosx, hpPosy, hpSizex, hpSizey, 0.0, 0.0, 0.0) {};
};