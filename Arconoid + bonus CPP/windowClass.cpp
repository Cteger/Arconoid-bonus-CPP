#define CHANCE_OF_RANDOM_BLOK (rand() % 5 + 1)
#define CHANCE_OF_RANDOM_BONUS (rand() % 5)


#include "windowClass.h"

#include <glut.h>


Window::Window(int hpCount, int level, int windSizex, int windSizey, int windPosx, int windPosy)
{
	setSize(windSizex, windSizey);
	setPosition(windPosx, windPosy);

	this->level = level;
	score = 0;
	this->hpCount = hpCount;
	maxHp = hpCount;
}

void Window::HpInitialize(int ballSizex, int ballSizey, int windSizey)
{
	for (int i = 0; i < hpCount; i++)
	{
		hp[i] = Hp(10 + i * (ballSizex + 5), windSizey - 3, ballSizex, ballSizey);
	}
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
		bloks.push_back(Blok(i, getSize(0), getSize(1) - menu.getMenuSize(), 60, 5, 1));
	}
}
void Window::CreateLvlTwo()
{
	srand(time(0));
	int blockCount = 120;

	bloks.clear();

	for (int i = 0; i < blockCount; i++)
	{
		bloks.push_back(Blok(i, getSize(0), getSize(1) - menu.getMenuSize(), 15, 10, CHANCE_OF_RANDOM_BLOK));
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
		if ((bloks[i].getStrength() == 1 || ball.getIsFireBall() == 1) && bloks[i].getStrength() != 5)
		{
			if (true)//CHANCE_OF_RANDOM_BONUS == 0)
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
	if (ball.getIsBallLaunch())
	{
		ball.MenuColision(getSize(0), getSize(1) - menu.getMenuSize());

		ball.RacketColision(racket.getPosition(0), racket.getPosition(1), racket.getSize(0), racket.getRacketSpeed(0) - racket.getRacketSpeed(1));

		for (int i = 0; i < bloks.size(); i++)
		{
			if (ball.BlokColision(bloks[i].getPosition(0), bloks[i].getPosition(1), bloks[i].getSize(0), bloks[i].getSize(1), bloks[i].getStrength()))
			{
				BlokDestroy(i);
				break;
			}
		}
	}
}


void Window::BonusInitialise(int blok_i)
{
	switch (CHANCE_OF_RANDOM_BONUS)
	{
	case 0:
		bonuses.push_back(new Barrier(bloks[blok_i].getPosition(0), bloks[blok_i].getPosition(1), bloks[blok_i].getSize(0), bloks[blok_i].getSize(1)));

		break;
	case 1:
		bonuses.push_back(new FireBall(bloks[blok_i].getPosition(0), bloks[blok_i].getPosition(1), bloks[blok_i].getSize(0), bloks[blok_i].getSize(1)));

		break;
	case 2:
		bonuses.push_back(new LittleRacket(bloks[blok_i].getPosition(0), bloks[blok_i].getPosition(1), bloks[blok_i].getSize(0), bloks[blok_i].getSize(1)));

		break;
	case 3:
		bonuses.push_back(new BigRacket(bloks[blok_i].getPosition(0), bloks[blok_i].getPosition(1), bloks[blok_i].getSize(0), bloks[blok_i].getSize(1)));

		break;
	case 4:
		bonuses.push_back(new NewHp(bloks[blok_i].getPosition(0), bloks[blok_i].getPosition(1), bloks[blok_i].getSize(0), bloks[blok_i].getSize(1)));

		break;
	case 5:
		bonuses.push_back(new ChangeTr(bloks[blok_i].getPosition(0), bloks[blok_i].getPosition(1), bloks[blok_i].getSize(0), bloks[blok_i].getSize(1)));
		break;
	}
}
void Window::RenderBonuses()
{
	int j = 0;

	for (int i = 0; i < bonuses.size(); i++)
	{
		j = bonuses[i]->RenderBonus(racket.getPosition(0), racket.getPosition(1), racket.getSize(0));
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
	for (int i = 0; i < bonuses.size(); i++)
	{
		delete bonuses[i];
	}

	bonuses.clear();
}
void Window::BonusCatch(int bonus_i)
{
	score += 100;

	bonuses[bonus_i]->BonusInitialize(racket, ball, hpCount, maxHp);

	BonusDestroy(bonus_i);
}
void Window::BonusDestroy(int bonus_i)
{
	delete bonuses[bonus_i];
	bonuses.erase(bonuses.begin() + bonus_i);
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
	for (int i = 0; i < bonuses.size(); i++)
	{
		bonuses[i]->DrawPhysObject();
	}
}