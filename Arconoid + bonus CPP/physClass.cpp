#include "physClass.h"

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

void PhysObject::setXSize(double i)
{
	sizex = i;
}
void PhysObject::setYSize(double i)
{
	sizey = i;
}

double PhysObject::getXSize()
{
	return sizex;
}

double PhysObject::getYSize()
{
	return sizey;
}


void PhysObject::setXPosition(double i)
{
	posx = i;
}
void PhysObject::setYPosition(double i)
{
	posy = i;
}

double PhysObject::getXPosition()
{
	return posx;
}
double PhysObject::getYPosition()
{
	return posy;
}

void PhysObject::setXVec(double i)
{
	vecx = i;
}
void PhysObject::setYVec(double i)
{
	vecy = i;
}

double PhysObject::getXVec()
{
	return vecx;
}
double PhysObject::getYVec()
{
	return vecy;
}