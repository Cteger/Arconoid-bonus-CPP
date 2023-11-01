#include "blokClass.h"
#include <glut.h>

Blok::Blok(int i, int menuSize, int windSizex, int windSizey, int blokSizey, int lineSize, int strength)
{
	setSize(windSizex / lineSize, blokSizey);

	this->strength = strength;

	if (i / lineSize == 0)
	{
		setPosition((i % lineSize) * getSize(0),
			windSizey - menuSize);
	}
	else
	{
		setPosition((i % lineSize) * getSize(0),
			windSizey - menuSize - (i / lineSize) * getSize(1));
	}

	ResetBlokColor();
}

Blok::~Blok()
{

}


void Blok::ResetBlokColor()
{
	if (strength == 1)
	{
		setColor(0.0, 1.0, 0.0);
	}
	else if (strength == 2)
	{
		setColor(1.0, 1.0, 0.0);
	}
	else if (strength == 3)
	{
		setColor(0.1, 0.2, 0.8);
	}
	else if (strength == 4)
	{
		setColor(1.0, 0.5, 0.5);
	}
}

void Blok::DrawBlok()
{
	glBegin(GL_QUADS);

	glColor3f(getColor(0), getColor(1), getColor(2));

	glVertex2d(getPosition(0), getPosition(1));
	glVertex2d(getPosition(0) + getSize(0),	getPosition(1));
	glVertex2d(getPosition(0) + getSize(0),	getPosition(1) - getSize(1));
	glVertex2d(getPosition(0), getPosition(1) - getSize(1));

	glEnd();

	glColor3f(0, 0, 0);

	glBegin(GL_LINE_LOOP);

	glVertex2d(getPosition(0), getPosition(1));
	glVertex2d(getPosition(0) + getSize(0),	getPosition(1));
	glVertex2d(getPosition(0) + getSize(0),	getPosition(1) - getSize(1));
	glVertex2d(getPosition(0), getPosition(1) - getSize(1));

	glEnd();
}


void Blok::setStrength(int i)
{
	strength = i;
}
int Blok::getStrength()
{
	return strength;
}