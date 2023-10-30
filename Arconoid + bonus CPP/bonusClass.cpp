#include "bonusClass.h"
#include "windowClass.h"

#include <glut.h>
#include <stdlib.h>

Bonus::Bonus(int blokPosx, int blokPosy, int blokSizex, int blokSizey)
{
	setSize(BONUS_SIZE_WIDTH, BONUS_SIZE_HEIGHT);
	setPosition(blokPosx + blokSizex / 2 - BONUS_SIZE_WIDTH / 2,
		blokPosy - blokSizey / 2 + BONUS_SIZE_HEIGHT / 2);
	type = CHANCE_OF_RANDOM_BONUS;

	if (type == 1)
	{
		setRColor(1.0);
		setGColor(0.1);
		setBColor(0.1);
	}
	else if (type == 2)
	{
		setRColor(0.0);
		setGColor(0.5);
		setBColor(1.0);
	}
	else if (type == 3)
	{
		setRColor(1.0);
		setGColor(0.5);
		setBColor(0.0);
	}
	else if (type == 4)
	{
		setRColor(0.0);
		setGColor(0.0);
		setBColor(0.0);
	}

	setVec(0, (-0.5) * SPEED);
}


int Bonus::CheckBonus(double racketPosx, double racketPosy, double racketSizex)
{
	int x0 = getPosition(0);
	int x1 = x0 + getSize(0);
	int y0 = getPosition(1) + getVec(1);
	int y1 = y0 - getSize(1);

	if (y0 <= 0)
	{
		return 1;//BonusDestroy(bonus_i);
	}
	else if ((x1 >= racketPosx)
		&& (x0 <= racketPosx + racketSizex)
		&& (y1 <= racketPosy))
	{
		return 2;//BonusCatch(bonus_i);
	}
	return 0;
}
void Bonus::DrawBonus()
{
	glBegin(GL_QUADS);

	glColor3f(getRColor(), getGColor(),	getBColor());

	glVertex2d(getPosition(0), getPosition(1));
	glVertex2d(getPosition(0) + getSize(0),	getPosition(1));
	glVertex2d(getPosition(0) + getSize(0),	getPosition(1) - getSize(1));
	glVertex2d(getPosition(0), getPosition(1) - getSize(1));

	glEnd();
}


int Bonus::getType()
{
	return type;
}