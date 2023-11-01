#include "windowClass.h"

#include <glut.h>

Window::Window()
{

}

Window::Window(int newHp, int newLevel, int windSizex, int windSizey, int windPosx, int windPosy)
{
	setSize(windSizex, windSizey);
	setPosition(windPosx, windPosy);

	level = newLevel;
	hp = newHp;
	score = 0;
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
	for (int i = 0; i < bloks.size(); i++)
	{
		delete bloks[i];
	}
	bloks.clear();

	for (int i = 0; i < blokCount; i++)
	{
		auto new_blok = new Blok(i, menuSize, getSize(0), getSize(1), 60, 5, 1);// утечка
		bloks.push_back(new_blok);
	}
}
void Window::CreateLvlTwo()
{
	int blockCount = 120;
	for (int i = 0; i < bloks.size(); i++)
	{
		delete bloks[i];
	}
	bloks.clear();

	for (int i = 0; i < blockCount; i++)
	{
		auto new_blok = new Blok(i, menuSize, getSize(0), getSize(1), 15, 10, CHANCE_OF_RANDOM);
		bloks.push_back(new_blok);
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
		if (bloks[i]->getStrength() == 1 || ball.getFireBallFlag() == 1)
		{
			if (CHANCE_OF_RANDOM == 1)
			{
				BonusInitialise(i);
			}

			delete bloks[i];

			bloks[i] = bloks[bloks.size() - 1];//!!!!!!!

			//delete bloks[bloks.size() - 1];

			bloks.pop_back();

			score += 20;
		}
		else
		{
			bloks[i]->setStrength(bloks[i]->getStrength() - 1);
			bloks[i]->ResetBlokColor();
			score += 30;
		}
	}
}
void Window::DrawBloks()
{
	for (int i = 0; i < bloks.size(); i++)
	{
		bloks[i]->DrawBlok();
	}
}


void Window::CheckBallColision()
{
	ball.MenuColision(menuSize, getSize(0), getSize(1));

	ball.RacketColision(racket.getPosition(0), racket.getPosition(1), racket.getSize(0), racket.getRacketSpeed(0) - racket.getRacketSpeed(1));

	for (int i = 0; i < bloks.size(); i++)
	{
		if (ball.BlokColision(bloks[i]->getPosition(0), bloks[i]->getPosition(1), bloks[i]->getSize(0), bloks[i]->getSize(1)))
		{
			BlokDestroy(i);
			break;
		}
	}
}


void Window::BonusInitialise(int blok_i)
{
	auto new_bonus = new Bonus(bloks[blok_i]->getPosition(0), bloks[blok_i]->getPosition(1), bloks[blok_i]->getSize(0), bloks[blok_i]->getSize(1));

	bonus.push_back(new_bonus);
}
void Window::RenderBonus()
{
	for (int i = 0; i < bonus.size(); i++)
	{
		bonus[i]->setPosition(bonus[i]->getPosition(0), bonus[i]->getPosition(1) + bonus[i]->getVec(1));
		int j = bonus[i]->CheckBonus(racket.getPosition(0), racket.getPosition(1), racket.getSize(0));
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
	for (int i = 0; i < bonus.size(); i++)
	{
		delete bonus[i];
	}

	bonus.clear();
}
void Window::BonusCatch(int bonus_i)
{
	score += 100;

	if (bonus[bonus_i]->getType() == 1)
	{
		ball.FireBallInitialise();
	}
	else if (bonus[bonus_i]->getType() == 2)
	{
		racket.LittleRacketInitialise();
	}
	else if (bonus[bonus_i]->getType() == 3)
	{
		racket.BigRacketInitialise();
	}
	else if (bonus[bonus_i]->getType() == 4)
	{
		NewHP();
	}

	BonusDestroy(bonus_i);
}
void Window::BonusDestroy(int bonus_i)
{
	delete bonus[bonus_i];

	bonus[bonus_i] = bonus[bonus.size() - 1];

	//delete bonus[bonus.size() - 1];

	bonus.pop_back();
}
void Window::DrawBonus()
{
	for (int i = 0; i < bonus.size(); i++)
	{
		bonus[i]->DrawBonus();
	}
}


void Window::NewHP()
{
	if (hp < 3)
	{
		hp++;
	}
}
void Window::DrawHP()
{
	glColor3f(0, 0, 0);

	glBegin(GL_LINE_LOOP);

	glVertex2d(0, getSize(1) - 1);
	glVertex2d(getSize(0), getSize(1) - 1);
	glVertex2d(getSize(0), getSize(1) - menuSize);
	glVertex2d(0, getSize(1) - menuSize);

	glEnd();


	glBegin(GL_QUADS);

	glColor3f(0, 0, 0);

	for (int i = 0; i < hp; i++)
	{
		glVertex2d(300 + i * ball.getSize(0) + i * 5,
			getSize(1) - 3);
		glVertex2d(300 + (i + 1) * ball.getSize(0) + 5 * i,
			getSize(1) - 3);
		glVertex2d(300 + (i + 1) * ball.getSize(0) + 5 * i,
			getSize(1) - 3 - ball.getSize(1));
		glVertex2d(300 + i * (ball.getSize(0) + 5),
			getSize(1) - 3 - ball.getSize(1));
	}
	glEnd();
}


void Window::setLevel(int wind_level)
{
	level = wind_level;
}
void Window::setHp(int wind_hp)
{
	hp = wind_hp;
}
int Window::getHp()
{
	return hp;
}
int Window::getLevel()
{
	return level;
}
int Window::getScore()
{
	return score;
}