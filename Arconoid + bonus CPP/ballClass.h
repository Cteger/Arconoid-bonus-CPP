#pragma once
#include "Header.h"
#include "physClass.h"

struct Ball: public PhysObject
{
private:
	int launchFlag;
	double maxSpeed;
	int fireBallFlag;

public:

	void setLaunchFlag(int i);

	int getLaunchFlag();
	
	void setMaxSpeed(double i);

	double getMaxSpeed();
};


