#pragma once
#include "game.h"
#include "vectorStruct.h"
#include "physObjectClass.h"

class Ball : public PhysObject
{
private:
	Vector vect;

	bool isBallLaunch;
	double maxSpeed;
	bool isFireBall;
	bool isBarrier;

public:

	Ball() {};
	Ball(double racketPosx, double racketPosy, double racketSizex);

	void BallLaunch(int deltaRacketSpeed);

	void RenderBall(double racketPosx, double racketPosy, double racketSizex);

	void MenuColision(int windSizex, int windSizey);
	void RacketColision(int racketPosx, int racketPosy, int racketSizex, int deltaRacketSpeed);
	bool BlokColision(int blokPosx, int blokPosy, int blokSizex, int blokSizey, int strength);

	void ReleaseFireBall();
	void ReleaseBarrier() { isBarrier = 0; };

	void setIsFireBall(bool isFireBall) { this->isFireBall = isFireBall; };
	void setIsBarrier(bool isBarrier) { this->isBarrier = isBarrier; };

	int getIsBallLaunch() { return isBallLaunch; }
	int getIsFireBall() { return isFireBall; }

	void setVectorx(int i) { vect.setVec(i, vect.getVec(1)); }
	int getVectorx() { return vect.getVec(0); }
};