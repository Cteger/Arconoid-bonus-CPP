#pragma once
#include "game.h"
#include "vectorStruct.h"
#include "physObjectClass.h"

class Bonus : public PhysObject, public Vector
{
private:
	int type;

public:
	Bonus() {};
	Bonus(int blokPosx, int blokPosy, int blokSizex, int blokSizey);

	int RenderBonus(double racketPosx, double racketPosy, double racketSizex);

	int CheckBonus(double racketPosx, double racketPosy, double racketSizex);

	int getType() { return type; };
	void setType(int rand) { type = rand; };
};

enum BonusType
{
	FireBall,
	LittleRacket,
	BigRacket,
	NewHp
};