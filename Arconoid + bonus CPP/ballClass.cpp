#include "ballClass.h"

#include <windows.h>
#include <math.h>
#include <glut.h>


Ball::Ball(double racketPosx, double racketPosy, double racketSizex)
{
	setSize(Param::BALL_SIZE_WIDTH, Param::BALL_SIZE_HEIGHT);
	setPosition(racketPosx + racketSizex / 2 - getSize(0) / 2, racketPosy + getSize(1));
	launchFlag = 0;
	maxSpeed = Param::SPEED;
	setVec(0, maxSpeed);

	fireBallFlag = 0;

	setColor(0.0, 0.0, 0.0);
}

void Ball::BallLaunch(int deltaRacketSpeed)
{
	if (!launchFlag)
	{
		setVec(deltaRacketSpeed - maxSpeed / 10, sqrt(maxSpeed * maxSpeed - getVec(0) * getVec(0)));
		launchFlag = 1;
	}
}


void Ball::RenderBall(double racketPosx, double racketPosy, double racketSizex)
{
	if (launchFlag)
	{
		setPosition(getPosition(0) + getVec(0), getPosition(1) + getVec(1));
	}
	else
	{
		setPosition(racketPosx + racketSizex / 2 - getSize(0) / 2, racketPosy + getSize(1));
	}
}

void Ball::MenuColision(int windSizex, int windSizey)
{
	int x0 = getPosition(0) + getVec(0);
	int x1 = x0 + getSize(0);
	int y0 = getPosition(1) + getVec(1);
	int y1 = y0 - getSize(1);

	if (x1 > windSizex || x0 < 0)
	{
		setVec((-1) * getVec(0), getVec(1));
	}

	if (y0 > windSizey)
	{
		setVec(getVec(0), (-1) * getVec(1));
		ReleaseFireBall();
	}

	if (y0 <= 0)
	{
		EndGame(0);
	}
}
void Ball::RacketColision(int racketPosx, int racketPosy, int racketSizex, int deltaRacketSpeed)
{
	int x0 = getPosition(0) + getVec(0);
	int x1 = x0 + getSize(0);
	int y0 = getPosition(1) + getVec(1);
	int y1 = y0 - getSize(1);

	if ((x0 < racketPosx + racketSizex) && (x1 > racketPosx) && (y1 < racketPosy))
	{
		setVec(getVec(0) + ((deltaRacketSpeed) % 10), (-1) * getVec(1));
		if (getVec(0) > maxSpeed)
		{
			setVec(maxSpeed, getVec(1));
		}
		else if (getVec(0) < (-1) * maxSpeed)
		{
			setVec((-1) * maxSpeed, getVec(1));
		}
	}
}
bool Ball::BlokColision(int blokPosx, int blokPosy, int blokSizex, int blokSizey, int strength)
{
	int x0 = getPosition(0) + getVec(0);
	int x1 = x0 + getSize(0);
	int y0 = getPosition(1) + getVec(1);
	int y1 = y0 - getSize(1);

	if ((x1 > blokPosx) && (x0 < blokPosx + blokSizex)
		&& (((y1 < blokPosy) && (y0 > blokPosy) && (y0 > blokPosy - blokSizey))
		|| ((y1 < blokPosy) && (y1 < blokPosy - blokSizey) && (y0 > blokPosy - blokSizey))))
	{
		if (fireBallFlag == 0 || strength == 5)
		{
			setVec(getVec(0), (-1) * getVec(1));
		}
		return true;
	}
	else if (((y1 < blokPosy) && (y0 > blokPosy - blokSizey))
		&& (((x1 > blokPosx) && (x0 < blokPosx) && (x0 < blokPosx + blokSizex))
			|| ((x1 > blokPosx) && (x1 > blokPosx + blokSizex) && (x0 < blokPosx + blokSizex))))
	{
		if (fireBallFlag == 0 || strength == 5)
		{
			setVec((-1) * getVec(0), getVec(1));
		}
		return true;
	}

	return false;
}


void Ball::FireBallInitialise()
{
	fireBallFlag = 1;

	setColor(1, 0.1, 0.1);
}
void Ball::ReleaseFireBall()
{
	fireBallFlag = 0;

	setColor(0.0, 0.0, 0.0);
}