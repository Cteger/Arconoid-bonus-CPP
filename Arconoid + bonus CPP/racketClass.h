#pragma once
#include "game.h"
#include "physObjectClass.h"

class Racket : public PhysObject
{
private:
	CustomVec<double> racketSpeed;

public:

	Racket();

	Racket(int windSizex);

	void RenderRacket(int x, int y, int windSizex);

	void LittleRacketInitialise();
	void BigRacketInitialise();

	int getRacketSpeed(int i);
};

