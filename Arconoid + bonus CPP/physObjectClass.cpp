#include "physObjectClass.h"

#include <glut.h>



void PhysObject::DrawPhysObject()
{
	glBegin(GL_QUADS);

	glColor3f(color.map["red"], color.map["green"], color.map["blue"]);

	glVertex2d(position.x, position.y);
	glVertex2d(position.x + size.x, position.y);
	glVertex2d(position.x + size.x, position.y - size.y);
	glVertex2d(position.x, position.y - size.y);

	glEnd();

	glColor3f(0, 0, 0);

	glBegin(GL_LINE_LOOP);

	glVertex2d(position.x, position.y);
	glVertex2d(position.x + size.x, position.y);
	glVertex2d(position.x + size.x, position.y - size.y);
	glVertex2d(position.x, position.y - size.y);

	glEnd();
}

void PhysObject::setColor(double r, double g, double b)
{
	color.map["red"] = r;
	color.map["green"] = g;
	color.map["blue"] = b;
}

double PhysObject::getColor(std::string new_color)
{
	if (new_color == "red") return color.map["red"];
	else if (new_color == "green") return color.map["green"];
	else if (new_color == "blue") return color.map["blue"];
	else return 0;
}


void PhysObject::setSize(int x, int y)
{
	size.x = x;
	size.y = y;
}
int PhysObject::getSize(int i)
{
	if (i == 0)	return size.x;
	else return size.y;
}


void PhysObject::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}
int PhysObject::getPosition(int i)
{
	if (i == 0)	return position.x;
	else return position.y;
}
