#pragma once
#include "Header.h"

#include "physClass.h"

struct Blok : public PhysObject
{
private:
	int strength;

public:

	void setStrength(int i);

	int getStrength();
};


