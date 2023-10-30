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


void Blok::ResetBlokColor()
{
	if (strength == 1)
	{
		setRColor(0);
		setGColor(1.0);
		setBColor(0.0);
	}
	else if (strength == 2)
	{
		setRColor(1.0);
		setGColor(1.0);
		setBColor(0.0);
	}
	else if (strength == 3)
	{
		setRColor(0.1);
		setGColor(0.2);
		setBColor(0.8);
	}
	else if (strength == 4)
	{
		setRColor(1.0);
		setGColor(0.5);
		setBColor(0.5);
	}
}
void Blok::DrawBlok()
{
	glBegin(GL_QUADS);

	glColor3f(getRColor(), getGColor(), getBColor());

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