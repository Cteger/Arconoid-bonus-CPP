#pragma once

#include "vectorStruct.h"
#include "colorStruct.h"

class PhysObject
{
//protected:
private:
	Color color;//tuple
	CustomVec<int> position;
	CustomVec<int> size;
	CustomVec<double> vect;

public:

	void setColor(double r, double g, double b);
	double getColor(int i);

	void setSize(int x, int y);
	int getSize(int i);

	void setPosition(int x, int y);
	int getPosition(int i);

	void setVec(double x, double y);
	double getVec(int i);
};