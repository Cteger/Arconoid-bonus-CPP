#pragma once

#include "vectorStruct.h"
#include "colorMapStruct.h"

class PhysObject
{
private:
	ColorMap color;
	CustomVec<int> position;
	CustomVec<int> size;
	CustomVec<double> vect;

public:

	void DrawPhysObject();

	void setColor(double r, double g, double b);
	double getColor(std::string color);

	void setSize(int x, int y);
	int getSize(int i);

	void setPosition(int x, int y);
	int getPosition(int i);

	void setVec(double x, double y);
	double getVec(int i);
};