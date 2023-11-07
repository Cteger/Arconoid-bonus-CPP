#pragma once
#include "game.h"
#include "physObjectClass.h"

class Racket : public PhysObject
{
private:
	CustomVec<int> racketSpeed;

public:
	Racket() {};

	Racket(int windSizex);

	void RenderRacket(int x, int y, int windSizex);

	int getRacketSpeed(int i);
};