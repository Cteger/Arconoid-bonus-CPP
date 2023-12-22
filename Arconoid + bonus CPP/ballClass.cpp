#include "ballClass.h"

#include <windows.h>
#include <math.h>
#include <glut.h>


Ball::Ball(double racketPosx, double racketPosy, double racketSizex)
{
	setSize(Param::BALL_SIZE_WIDTH, Param::BALL_SIZE_HEIGHT);
	setPosition(racketPosx + racketSizex / 2 - getSize(0) / 2, racketPosy + getSize(1));
	isBallLaunch = 0;
	maxSpeed = Param::SPEED;
	vect.setVec(0, maxSpeed);

	isFireBall = 0;
	isBarrier = 0;

	setColor(0.0, 0.0, 0.0);
}

void Ball::BallLaunch(int deltaRacketSpeed)
{
	if (!isBallLaunch)
	{
		vect.setVec(deltaRacketSpeed - maxSpeed / 10, sqrt(maxSpeed * maxSpeed - vect.getVec(0) * vect.getVec(0)));
		isBallLaunch = 1;
	}
}


void Ball::RenderBall(double racketPosx, double racketPosy, double racketSizex)
{
	if (isBallLaunch)
	{
		setPosition(getPosition(0) + vect.getVec(0), getPosition(1) + vect.getVec(1));
	}
	else
	{
		setPosition(racketPosx + racketSizex / 2 - getSize(0) / 2, racketPosy + getSize(1));
	}
}

void Ball::MenuColision(int windSizex, int windSizey)
{
	int x0 = getPosition(0) + vect.getVec(0);
	int x1 = x0 + getSize(0);
	int y0 = getPosition(1) + vect.getVec(1);
	int y1 = y0 - getSize(1);

	if (x1 > windSizex || x0 < 0)
	{
		vect.setVec((-1) * vect.getVec(0), vect.getVec(1));
	}

	if (y0 > windSizey)
	{
		vect.setVec(vect.getVec(0), (-1) * vect.getVec(1));
		ReleaseFireBall();
	}

	if (y0 < 0)
	{
		if (!isBarrier)
		{
			EndGame(0);
		}
		else
		{
			vect.setVec(vect.getVec(0), (-1) * vect.getVec(1));
			ReleaseBarrier();
		}
	}
}
void Ball::RacketColision(int racketPosx, int racketPosy, int racketSizex, int deltaRacketSpeed)
{
	int x0 = getPosition(0) + vect.getVec(0);
	int x1 = x0 + getSize(0);
	int y0 = getPosition(1) + vect.getVec(1);
	int y1 = y0 - getSize(1);

	if ((x0 < racketPosx + racketSizex) && (x1 > racketPosx) && (y1 < racketPosy))
	{
		vect.setVec(vect.getVec(0) + ((deltaRacketSpeed) % 10), (-1) * vect.getVec(1));
		if (vect.getVec(0) > maxSpeed)
		{
			vect.setVec(maxSpeed, vect.getVec(1));
		}
		else if (vect.getVec(0) < (-1) * maxSpeed)
		{
			vect.setVec((-1) * maxSpeed, vect.getVec(1));
		}
	}
}
bool Ball::BlokColision(int blokPosx, int blokPosy, int blokSizex, int blokSizey, int strength)
{
	int x0 = getPosition(0) + vect.getVec(0);
	int x1 = x0 + getSize(0);
	int y0 = getPosition(1) + vect.getVec(1);
	int y1 = y0 - getSize(1);

	if ((x1 > blokPosx) && (x0 < blokPosx + blokSizex)
		&& (((y1 < blokPosy) && (y0 > blokPosy) && (y0 > blokPosy - blokSizey))
			|| ((y1 < blokPosy) && (y1 < blokPosy - blokSizey) && (y0 > blokPosy - blokSizey))))
	{
		if (isFireBall == 0 || strength == 5)
		{
			vect.setVec(vect.getVec(0), (-1) * vect.getVec(1));
		}
		return true;
	}
	else if (((y1 < blokPosy) && (y0 > blokPosy - blokSizey))
		&& (((x1 > blokPosx) && (x0 < blokPosx) && (x0 < blokPosx + blokSizex))
		|| ((x1 > blokPosx) && (x1 > blokPosx + blokSizex) && (x0 < blokPosx + blokSizex))))
	{
		if (isFireBall == 0 || strength == 5)
		{
			vect.setVec((-1) * vect.getVec(0), vect.getVec(1));
		}
		return true;
	}

	return false;
}

void Ball::ReleaseFireBall()
{
	isFireBall = 0;

	setColor(0.0, 0.0, 0.0);
}