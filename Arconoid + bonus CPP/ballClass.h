#pragma once
#include "game.h"
#include "physObjectClass.h"

struct Ball : public PhysObject
{
private:
	int launchFlag;
	double maxSpeed;
	int fireBallFlag;

public:

	Ball();
	Ball(double racketPosx, double racketPosy, double racketSizex);
	~Ball();

	void BallLaunch(int deltaRacketSpeed);

	bool RenderBall(double racketPosx, double racketPosy, double racketSizex);

	void MenuColision(int windSizex, int windSizey);
	void RacketColision(int racketPosx, int racketPosy, int racketSizex, int deltaRacketSpeed);
	bool BlokColision(int blokPosx, int blokPosy, int blokSizex, int blokSizey, int strength);

	void FireBallInitialise();
	void ReleaseFireBall();


	int getFireBallFlag();
};