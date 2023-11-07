#include "racketClass.h"
#include <glut.h>


Racket::Racket(int windSizex)
{
	setSize(Param::RACKET_WIDTH, Param::RACKET_HIGHT);

	setPosition((windSizex - getSize(0)) / 2, Param::RACKET_YPOSITION);

	setColor(0.0, 1.0, 0.0);

	racketSpeed.x = 0;
	racketSpeed.y = 0;
}


void Racket::RenderRacket(int x, int y, int windSizex)
{
	racketSpeed.y = racketSpeed.x;
	racketSpeed.x = x;


	if (x >= windSizex - getSize(0) / 2)
	{
		setPosition(windSizex - getSize(0), getPosition(1));
	}
	else if (x <= getSize(0) / 2)
	{
		setPosition(0, getPosition(1));
	}
	else
	{
		setPosition(x - getSize(0) / 2, getPosition(1));
	}
}

int Racket::getRacketSpeed(int i)
{
	if (i == 0)	return racketSpeed.x;
	else return racketSpeed.y;
}