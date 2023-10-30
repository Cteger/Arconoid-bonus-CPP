#pragma once
#include "gameClass.h"
#include "physObjectClass.h"

class Racket: public PhysObject
{
private:
	std::pair<int, int> racketSpeed;

public:

	void RacketInitialise(int windSizex);

	void RenderRacket(int x, int y, int windSizex);
	void DrawRacket();

	void LittleRacketInitialise();
	void BigRacketInitialise();

	int getRacketSpeed(int i);
};

