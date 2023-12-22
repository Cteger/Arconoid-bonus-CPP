#pragma once
#include "game.h"

#include "physObjectClass.h"

enum Strength
{
	White,
	Green,
	Yellow,
	Blue,
	Pink,
	Gray
};

class Blok : public PhysObject
{
private:
	int strength;

public:
	Blok() {}
	Blok(int i, int windSizex, int windSizey, int blokSizey, int lineSize, int strength);

	void ResetBlokColor();

	void setStrength(int strength) { this->strength = strength; };
	int getStrength() { return strength; };
};