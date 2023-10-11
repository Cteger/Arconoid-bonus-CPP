#include "ballClass.h"
#include "Bonus.h"

#include <glut.h>



void Ball::setLaunchFlag(int i)
{
	launchFlag = i;
}

int Ball::getLaunchFlag()
{
	return launchFlag;
}

void Ball::setMaxSpeed(double i)
{
	maxSpeed = i;
}

double Ball::getMaxSpeed()
{
	return maxSpeed;
}