#include "blokClass.h"
#include <glut.h>

Blok::Blok(int i, int windSizex, int windSizey, int blokSizey, int lineSize, int strength)
{
	setSize(windSizex / lineSize, blokSizey);

	this->strength = strength;

	if (i / lineSize == 0)
	{
		setPosition((i % lineSize) * getSize(0), windSizey);
	}
	else
	{
		setPosition((i % lineSize) * getSize(0), windSizey - (i / lineSize) * getSize(1));
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
	else if (strength == 5)
	{
		setColor(0.5, 0.5, 0.5);
	}
}

void Blok::setStrength(int i)
{
	strength = i;
}
int Blok::getStrength()
{
	return strength;
}