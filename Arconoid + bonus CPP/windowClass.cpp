#include "windowClass.h"

#include <glut.h>

void Window::HpInitialize(int ballSizex, int ballSizey, int windSizey)
{
	for (int i = 0; i < hpCount; i++)
	{
		hp[i] = Hp(ballSizex, ballSizey, 10 + i * (ballSizex + 5), windSizey - 3);
	}
}

void Window::NewHP()
{
	if (hpCount < maxHp)
	{
		hpCount++;
	}
}

Window::Window(int hpCount, int level, int windSizex, int windSizey, int windPosx, int windPosy)
{
	setSize(windSizex, windSizey);
	setPosition(windPosx, windPosy);

	this->level = level;
	score = 0;
	this->hpCount = hpCount;
	maxHp = hpCount;
}

void Window::ChooseLevel()
{
	if (level == 1)
	{
		CreateLvlOne();
	}
	else if (level == 2)
	{
		CreateLvlTwo();
	}
}
void Window::CreateLvlOne()
{
	int blokCount = 15;

	for (int i = 0; i < blokCount; i++)
	{
		auto* new_blok = new Blok(i, getSize(0), getSize(1) - menu.getMenuSize(), 60, 5, 1);// утечка
		bloks.push_back(*new_blok);
		delete new_blok;
	}
}
void Window::CreateLvlTwo()
{
	srand(time(0));
	int blockCount = 120;

	bloks.clear();

	for (int i = 0; i < blockCount; i++)
	{
		Blok* new_blok = new Blok(i, getSize(0), getSize(1) - menu.getMenuSize(), 15, 10, CHANCE_OF_RANDOM_BLOK);
		bloks.push_back(*new_blok);
		delete new_blok;
	}
}
void Window::BlokDestroy(int i)
{
	if (bloks.size() == 1)
	{
		EndGame(1);
	}
	else
	{
		if ((bloks[i].getStrength() == 1 || ball.getFireBallFlag() == 1) && bloks[i].getStrength() != 5)
		{
			if (CHANCE_OF_RANDOM_BONUS == 1)
			{
				BonusInitialise(i);
			}

			bloks[i] = bloks[bloks.size() - 1];

			bloks.pop_back();

			score += 20;
		}
		else if (bloks[i].getStrength() != 5)
		{
			bloks[i].setStrength(bloks[i].getStrength() - 1);
			bloks[i].ResetBlokColor();
			score += 30;
		}
	}
}

void Window::CheckBallColision()
{
	if (ball.getLaunchFlag())
	{
		ball.MenuColision(getSize(0), getSize(1) - menu.getMenuSize());

		ball.RacketColision(racket.getPosition(0), racket.getPosition(1), racket.getSize(0), racket.getRacketSpeed(0) - racket.getRacketSpeed(1));

		for (int i = 0; i < bloks.size(); i++)
		{
			/*if (bloks[i].getStrength() != 0)
			{*/
			if (ball.BlokColision(bloks[i].getPosition(0), bloks[i].getPosition(1), bloks[i].getSize(0), bloks[i].getSize(1), bloks[i].getStrength()))
			{
				BlokDestroy(i);
				break;
				//}
			}

		}
	}
}


void Window::BonusInitialise(int blok_i)
{
	Bonus* new_bonus = new Bonus(bloks[blok_i].getPosition(0), bloks[blok_i].getPosition(1), bloks[blok_i].getSize(0), bloks[blok_i].getSize(1));

	bonus.push_back(*new_bonus);

	delete new_bonus;
}
void Window::RenderBonuses()
{
	int j = 0;

	for (int i = 0; i < bonus.size(); i++)
	{
		j = bonus[i].RenderBonus(racket.getPosition(0), racket.getPosition(1), racket.getSize(0));
		if (j == 1)
		{
			BonusDestroy(i);
		}
		else if (j == 2)
		{
			BonusCatch(i);
		}
	}
}
void Window::BonusRelease()
{
	bonus.clear();
}
void Window::BonusCatch(int bonus_i)
{
	score += 100;

	if (bonus[bonus_i].getType() == 1)
	{
		ball.FireBallInitialise();
	}
	else if (bonus[bonus_i].getType() == 2)
	{
		racket.LittleRacketInitialise();
	}
	else if (bonus[bonus_i].getType() == 3)
	{
		racket.BigRacketInitialise();
	}
	else if (bonus[bonus_i].getType() == 4)
	{
		NewHP();
	}

	BonusDestroy(bonus_i);
}
void Window::BonusDestroy(int bonus_i)
{
	bonus[bonus_i] = bonus[bonus.size() - 1];

	bonus.pop_back();
}
void Window::DrawHp()
{
	for (int i = 0; i < hpCount; i++)
	{
		hp[i].DrawPhysObject();
	}
}
void Window::DrawBloks()
{
	for (int i = 0; i < bloks.size(); i++)
	{
		if (bloks[i].getStrength() != 0)
		{
			bloks[i].DrawPhysObject();
		}
	}
}
void Window::DrawBonuses()
{
	for (int i = 0; i < bonus.size(); i++)
	{
		bonus[i].DrawPhysObject();
	}
}