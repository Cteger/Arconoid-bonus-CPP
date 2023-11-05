#pragma once
#include "game.h"
#include "vectorStruct.h"
#include "physObjectClass.h"

struct Ball : public PhysObject, public Vector
{
private:
	bool launchFlag;
	double maxSpeed;
	bool fireBallFlag;

public:

	Ball() {};
	Ball(double racketPosx, double racketPosy, double racketSizex);

	void BallLaunch(int deltaRacketSpeed);

	void RenderBall(double racketPosx, double racketPosy, double racketSizex);

	void MenuColision(int windSizex, int windSizey);
	void RacketColision(int racketPosx, int racketPosy, int racketSizex, int deltaRacketSpeed);
	bool BlokColision(int blokPosx, int blokPosy, int blokSizex, int blokSizey, int strength);

	void FireBallInitialise();
	void ReleaseFireBall();

	int getLaunchFlag() { return launchFlag; }
	int getFireBallFlag() { return fireBallFlag; }
};