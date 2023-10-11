#pragma once

class PhysObject
{
//protected:
private:
	double red, green, blue;
	double posx, posy;
	double sizey, sizex;
	
	double vecx, vecy;

public:

	void setRColor(double i);
	void setGColor(double i);
	void setBColor(double i);

	double getRColor();
	double getGColor();
	double getBColor();

	void setXSize(double i);
	void setYSize(double i);

	double getXSize();
	double getYSize();

	void setXPosition(double i);
	void setYPosition(double i);

	double getXPosition();
	double getYPosition();

	void setXVec(double i);
	void setYVec(double i);

	double getXVec();
	double getYVec();
};