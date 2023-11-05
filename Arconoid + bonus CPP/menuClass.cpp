#include "game.h"
#include "menuClass.h"


Menu::Menu(int menuSizex, int menuSizey, int menuPosy)
{
	setPosition(0, menuPosy);
	setSize(menuSizex, menuSizey);
	menuSize = Param::MENU_SIZE;
	setColor(1.0, 1.0, 1.0);
}


Hp::Hp(int hpSizex, int hpSizey, int hpPosx, int hpPosy)
{
	setPosition(hpPosx, hpPosy);
	setSize(hpSizex, hpSizey);

	setColor(0.0, 0.0, 0.0);
}