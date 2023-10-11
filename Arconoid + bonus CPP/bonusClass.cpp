#include "bonusClass.h"

#include <glut.h>
#include <stdlib.h>


void Bonus::FireBallInitialise()
{
	ball.fire_ball_flag = 1;

	ball.color.red = 1;
	ball.color.green = 0.1;
	ball.color.blue = 0.1;
}

void Bonus::ReleaseFireBall()
{
	ball.fire_ball_flag = 0;

	ball.color.red = 0.0;
	ball.color.green = 0.0;
	ball.color.blue = 0.0;
}

void Bonus::LittleRacketInitialise(struct Racket& racket)
{
	size.sizex /= 2;

	color.red = 0;
	color.green = 0;
	color.blue = 1;
}

void Bonus::BigRacketInitialise(struct Racket& racket)
{
	size.sizex *= 1.4;

	color.red = 1;
	color.green = 0;
	color.blue = 0;
}

void Bonus::NewHP(int& hp)
{
	if (hp < 3)
	{
		hp++;
	}
}

void Bonus::setType(int i)
{
	type = i;
}

int Bonus::getType()
{
	return type;
}