#pragma once
#include "Header.h"
#include "physClass.h"

class Racket: public PhysObject
{
private:
	int racketSpeed[2];

public:

	void setRacketSpeed(int new_speed, int i);

	int getRacketSpeed(int i);
};

