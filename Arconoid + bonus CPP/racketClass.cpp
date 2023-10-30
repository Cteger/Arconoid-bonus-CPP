#include "racketClass.h"
#include <glut.h>

//Racket::Racket(int windSizex)
//{
//	setSize(RACKET_WIDTH, RACKET_HIGHT);
//
//	setPosition((windSizex - getSize(0)) / 2, RACKET_YPOSITION);
//
//	setRColor(0);
//	setGColor(1);
//	setBColor(0);
//}

void Racket::RacketInitialise(int windSizex)
{
	setSize(RACKET_WIDTH, RACKET_HIGHT);

	setPosition((windSizex - getSize(0)) / 2, RACKET_YPOSITION);

	setRColor(0);
	setGColor(1);
	setBColor(0);
}


void Racket::RenderRacket(int x, int y, int windSizex)
{
	racketSpeed.second = racketSpeed.first;
	racketSpeed.first = x;


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
void Racket::DrawRacket()
{
	glBegin(GL_QUADS);

	glColor3f(getRColor(), getGColor(), getBColor());

	glVertex2d(getPosition(0), getPosition(1));
	glVertex2d(getPosition(0) + getSize(0), getPosition(1));
	glVertex2d(getPosition(0) + getSize(0), getPosition(1) - getSize(1));
	glVertex2d(getPosition(0), getPosition(1) - getSize(1));

	glEnd();
}


void Racket::LittleRacketInitialise()
{
	setSize(getSize(0) / 2, getSize(1));

	setRColor(0);
	setGColor(0);
	setBColor(1);
}
void Racket::BigRacketInitialise()
{
	setSize(getSize(0) * 1.4, getSize(1));

	setRColor(1);
	setGColor(0);
	setBColor(0);
}


int Racket::getRacketSpeed(int i)
{
	if (i == 0)	return racketSpeed.first;
	else return racketSpeed.second;
}