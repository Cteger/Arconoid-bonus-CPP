#include "physObjectClass.h"

void PhysObject::setRColor(double i)
{
	red = i;
}
void PhysObject::setGColor(double i)
{
	green = i;
}
void PhysObject::setBColor(double i)
{
	blue = i;
}

double PhysObject::getRColor()
{
	return red;
}
double PhysObject::getGColor()
{
	return green;
}
double PhysObject::getBColor()
{
	return blue;
}


void PhysObject::setSize(int x, int y)
{
	size.first = x;
	size.second = y;
}
int PhysObject::getSize(int i)
{
	if (i == 0)	return size.first;
	else return size.second;
}


void PhysObject::setPosition(int x, int y)
{
	position.first = x;
	position.second = y;
}
int PhysObject::getPosition(int i)
{
	if (i == 0)	return position.first;
	else return position.second;
}

void PhysObject::setVec(double x, double y)
{
	vect.first = x;
	vect.second = y;
}
double PhysObject::getVec(int i)
{
	if (i == 0)	return vect.first;
	else return vect.second;
}
