#pragma once
#include "gameClass.h"
#include "bonusClass.h"
#include "physObjectClass.h"

class Bonus : public PhysObject
{
private:
	int type;

public:
	Bonus(int blokPosx, int blokPosy, int blokSizex, int blokSizey);
	
	int CheckBonus(double racketPosx, double racketPosy, double racketSizex);
	void DrawBonus();

	int getType();
};