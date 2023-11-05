#include "bonusClass.h"
#include "windowClass.h"

#include <glut.h>
#include <stdlib.h>

Bonus::Bonus(int blokPosx, int blokPosy, int blokSizex, int blokSizey)
{
	setSize(Param::BONUS_SIZE_WIDTH, Param::BONUS_SIZE_HEIGHT);
	setPosition(blokPosx + blokSizex / 2 - getSize(0) / 2,
		blokPosy - blokSizey / 2 + getSize(1) / 2);
	setType(CHANCE_OF_RANDOM_BONUS);

	if (type == 1)
	{
		setColor(1.0, 0.1, 0.1);
	}
	else if (type == 2)
	{
		setColor(0.0, 0.5, 1.0);
	}
	else if (type == 3)
	{
		setColor(1.0, 0.5, 0.0);
	}
	else if (type == 4)
	{
		setColor(0.0, 0.0, 0.0);
	}

	setVec(0, (-0.5) * Param::SPEED);
}

int Bonus::CheckBonus(double racketPosx, double racketPosy, double racketSizex)
{
	int x0 = getPosition(0);
	int x1 = x0 + getSize(0);
	int y0 = getPosition(1) + getVec(1);
	int y1 = y0 - getSize(1);

	if (y0 <= 0)
	{
		return 1;
	}
	else if ((x1 >= racketPosx)
		&& (x0 <= racketPosx + racketSizex)
		&& (y1 <= racketPosy))
	{
		return 2;
	}
	return 0;
}