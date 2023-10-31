#pragma once
#include "game.h"
#include "physObjectClass.h"
#include "vectorStruct.h"

class Racket: public PhysObject
{
private:
	dVector racketSpeed;

public:

	Racket();

	Racket(int windSizex);

	void RacketInitialise(int windSizex);

	void RenderRacket(int x, int y, int windSizex);
	void DrawRacket();

	void LittleRacketInitialise();
	void BigRacketInitialise();

	int getRacketSpeed(int i);
};

