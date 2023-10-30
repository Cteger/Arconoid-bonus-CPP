#pragma once

#include <vector>

class PhysObject
{
//protected:
private:
	double red, green, blue;//tuple
	std::pair<int, int> position;
	std::pair<int, int> size;
	std::pair<double, double> vect;

public:

	void setRColor(double i);
	void setGColor(double i);
	void setBColor(double i);

	double getRColor();
	double getGColor();
	double getBColor();

	void setSize(int x, int y);
	int getSize(int i);

	void setPosition(int x, int y);
	int getPosition(int i);

	void setVec(double x, double y);
	double getVec(int i);
};