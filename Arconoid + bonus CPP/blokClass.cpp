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

void Blok::ResetBlokColor()
{
	if (strength == Strength::Green)
	{
		setColor(0.0, 1.0, 0.0);
	}
	else if (strength == Strength::Yellow)
	{
		setColor(1.0, 1.0, 0.0);
	}
	else if (strength == Strength::Blue)
	{
		setColor(0.1, 0.2, 0.8);
	}
	else if (strength == Strength::Pink)
	{
		setColor(1.0, 0.5, 0.5);
	}
	else if (strength == Strength::Gray)
	{
		setColor(0.5, 0.5, 0.5);
	}
}