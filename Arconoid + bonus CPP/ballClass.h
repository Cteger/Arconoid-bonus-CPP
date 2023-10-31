#pragma once
#include "game.h"
#include "physObjectClass.h"

struct Ball: public PhysObject
{
private:
	int launchFlag;
	double maxSpeed;
	int fireBallFlag;

public:

	Ball();
	Ball(double racketPosx, double racketPosy, double racketSizex);
	~Ball();

	void BallInitialise(double racketPosx, double racketPosy, double racketSizex);
	void BallLaunch(int deltaRacketSpeed);

	bool RenderBall(double racketPosx, double racketPosy, double racketSizex);
	void DrawBall();

	void MenuColision(int menuSize, int windSizex, int windSizey); // menusize ----
	void RacketColision(int racketPosx, int racketPosy, int racketSizex, int deltaRacketSpeed);
	bool BlokColision(int blokPosx, int blokPosy, int blokSizex, int blokSizey);

	void FireBallInitialise();
	void ReleaseFireBall();


	int getFireBallFlag();
};


