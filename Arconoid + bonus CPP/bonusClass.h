#pragma once
#include "Header.h"

#include "physClass.h"

class Bonus : public PhysObject
{
private:
	int type;

public:
	
	void setType(int i);
	int getType();

	void FireBallInitialise(struct Ball*& ball);

	void ReleaseFireBall(struct Ball*& ball);

	void LittleRacketInitialise(struct Racket& racket);

	void BigRacketInitialise(struct Racket& racket);

	void NewHP(int& hp);
};