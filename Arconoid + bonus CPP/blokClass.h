#pragma once
#include "gameClass.h"

#include "physObjectClass.h"

struct Blok : public PhysObject
{
private:
	int strength;

public:

	Blok(int i, int menuSize, int windSizex, int windSizey, int blokSizey, int lineSize, int strength);

	void ResetBlokColor();
	void DrawBlok();


	void setStrength(int i);
	int getStrength();
};


