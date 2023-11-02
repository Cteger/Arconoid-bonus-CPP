#pragma once
#include "game.h"
#include "bonusClass.h"
#include "physObjectClass.h"

enum class Type
{
	FireBall,
	LittleRacket,
	BigRacket,
	NewHP
};

class Bonus : public PhysObject
{
private:
	int type;

public:
	Bonus();
	Bonus(int blokPosx, int blokPosy, int blokSizex, int blokSizey);
	~Bonus();
	
	int CheckBonus(double racketPosx, double racketPosy, double racketSizex);
	void DrawBonus();

	int getType();
};