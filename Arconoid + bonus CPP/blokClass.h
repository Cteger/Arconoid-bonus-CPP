#pragma once
#include "game.h"

#include "physObjectClass.h"

struct Blok : public PhysObject
{
private:
	int strength;

public:

	Blok(int i, int windSizex, int windSizey, int blokSizey, int lineSize, int strength);
	~Blok();

	void ResetBlokColor();

	void setStrength(int i);
	int getStrength();
};