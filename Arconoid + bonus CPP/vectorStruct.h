#pragma once

template <typename T>
class CustomVec
{
public:
	T x, y;
};

class Vector
{
private:
	CustomVec<double> vect;

public:
	void setVec(double x, double y)
	{
		vect.x = x;
		vect.y = y;
	}
	
	double getVec(int i)
	{
		if (i == 0)	return vect.x;
		else return vect.y;
	}
};