#include "windowClass.h"

#include <glut.h>
#include <windows.h>



void Window::setMenuSize(int wind_menuSize)
{
	menuSize = wind_menuSize;
}

void Window::setLevel(int wind_level)
{
	level = wind_level;
}

void Window::setHp(int wind_hp)
{
	hp = wind_hp;
}

void Window::BallInitialise()
{
	ball.setYSize(BALL_SIZE_HEIGHT);
	ball.setXSize(BALL_SIZE_WIDTH);
	ball.setXPosition(ball.getXPosition() + racket.getXSize() / 2 - ball.getXSize() / 2);
	ball.setYPosition(ball.getYPosition() + racket.getYSize());
	ball.setLaunchFlag(0);
	ball.setXVec(0);
	ball.setYVec(SPEED);
	ball.setMaxSpeed(SPEED);

	//fire_ball_flag = 0;

	ball.setRColor(0);
	ball.setGColor(0);
	ball.setBColor(0);
}

void Window::CheckBall()
{
	int x0 = ball.getXPosition() + ball.getXVec();
	int x1 = x0 + ball.getXSize();
	int y0 = ball.getYPosition() + ball.getYVec();
	int y1 = y0 - ball.getYSize();

	if (x1 > ball.getXSize() || x0 < 0)
	{
		ball.setXVec((-1) * ball.getXVec());
	}

	if (y0 >= ball.getYSize() - menuSize)
	{
		ball.setYVec((-1) * ball.getYVec());
		//ReleaseFireBall(ball);
	}

	if (y0 <= 0)
	{
		EndGame(0);
	}

	if ((x1 >= ball.getXPosition())
		&& (x0 <= ball.getXPosition() + ball.getXSize())
		&& (y1 <= ball.getYPosition()))
	{
		ball.setXVec(ball.getXVec() + ((speed - speed[1]) % 10));
		if (vector.x > max_speed)
		{
			vector.x = max_speed;
		}
		else if (vector.x < (-1) * max_speed)
		{
			vector.x = (-1) * max_speed;
		}
		vector.y = (-1) * vector.y;
	}

	for (int i = 0; i < blockCount; i++)
	{
		if ((x1 > (bloks + i)->x)
			&& (x0 < (bloks + i)->x + (bloks + i)->sizex)
			&& (y1 < (bloks + i)->y)
			&& (y0 > (bloks + i)->y)
			&& (y0 > (bloks + i)->y - (bloks + i)->sizey)
			|| ((x1 > (bloks + i)->x)
				&& (x0 < (bloks + i)->x + (bloks + i)->sizex)
				&& (y1 < (bloks + i)->y - (bloks + i)->sizey)
				&& (y0 > (bloks + i)->y - (bloks + i)->sizey)))
		{
			if (fire_ball_flag == 0)
			{
				vector.y = (-1) * vector.y;
			}
			Destroy(wind, i);
			break;
		}
		else if ((x1 > (bloks + i)->x)
			&& (x0 < (bloks + i)->x + (bloks + i)->sizex)
			&& (x0 < (bloks + i)->x)
			&& (y1 < (bloks + i)->y)
			&& (y0 > (bloks + i)->y - (bloks + i)->sizey)
			|| (x1 > (bloks + i)->x)
			&& (x1 > (bloks + i)->x + (bloks + i)->sizex)
			&& (x0 < (bloks + i)->x + (bloks + i)->sizex)
			&& (y1 < (bloks + i)->y)
			&& (y0 > (bloks + i)->y - (bloks + i)->sizey))
		{
			if (fire_ball_flag == 0)
			{
				vector.x = (-1) * vector.x;
			}
			Destroy(i);
			break;
		}
	}
}

void Window::DrawBall()
{
	glBegin(GL_QUADS);

	glColor3f(ball.getRColor(), ball.getGColor(), ball.getBColor());

	glVertex2d(ball.getXPosition(), ball.getYPosition());
	glVertex2d(ball.getXPosition() + ball.getXSize(), ball.getYPosition());
	glVertex2d(ball.getXPosition() + ball.getXSize(), ball.getYPosition() - ball.getYSize());
	glVertex2d(ball.getXPosition(), ball.getYPosition() - ball.getYSize());

	glEnd();
}


void Window::RacketInitialise()
{
	racket.setYSize(RACKET_HIGHT);
	racket.setXSize(RACKET_WIDTH);

	racket.setXPosition(getXSize() / 2);
	//posx = (sizex - RACKET_WIDTH) / 2;
	racket.setYPosition(10);

	racket.setRColor(0);
	racket.setGColor(1);
	racket.setBColor(0);


	//speed = new int[2];
}

void Window::DrawRacket()
{
	glBegin(GL_QUADS);

	glColor3f(racket.getRColor(), racket.getGColor(), racket.getBColor());

	glVertex2d(racket.getXPosition(), racket.getYPosition());
	glVertex2d(racket.getXPosition() + racket.getXSize(), racket.getYPosition());
	glVertex2d(racket.getXPosition() + racket.getXSize(), racket.getYPosition() - racket.getYSize());
	glVertex2d(racket.getXPosition(), racket.getYPosition() - racket.getYSize());

	glEnd();
}


void Window::DrawHP()
{
	glColor3f(0, 0, 0);

	glBegin(GL_LINE_LOOP);

	glVertex2d(0, getYSize() - 1);
	glVertex2d(getXSize(), getYSize() - 1);
	glVertex2d(getXSize(), getYSize() - menuSize);
	glVertex2d(0, getYSize() - menuSize);

	glEnd();


	glBegin(GL_QUADS);

	glColor3f(0, 0, 0);

	for (int i = 0; i < hp; i++)
	{
		glVertex2d(300 + i * ball.getXSize() + i * 5,
			getYSize() - 3);
		glVertex2d(300 + (i + 1) * ball.getXSize() + 5 * i,
			getYSize() - 3);
		glVertex2d(300 + (i + 1) * ball.getXSize() + 5 * i,
			getYSize() - 3 - ball.getYSize());
		glVertex2d(300 + i * (ball.getXSize() + 5),
			getYSize() - 3 - ball.getYSize());
	}
}

void Window::CreateLevel()
{
	if (level == 1)
	{
		blockCount = blockCount1;
		bloks.clear();
		bloks.resize(blockCount);

		for (int i = 0; i < blockCount; i++)
		{
			bloks[i]->setYSize(60);
			bloks[i]->setXSize(getXSize() / 5);

			bloks[i]->setStrength(1);
			bloks[i]->setXPosition((i % 5) * bloks[i]->getXSize());
		}

		for (int i = 0; i < blockCount; i++)
		{
			if (i / 5 == 0)
			{
				bloks[i]->setYPosition(getYSize() - menuSize);
			}
			else if (i / 5 == 1)
			{
				bloks[i]->setYPosition(bloks[0]->getYPosition()
					- bloks[i]->getYSize());
			}
			else
			{
				bloks[i]->setYPosition(bloks[0]->getYPosition()
					- 2 * bloks[i]->getYSize());
			}
		}
	}
	else if (level == 2)
	{
		blockCount = 120;
		bloks.clear();
		bloks.resize(blockCount);
		for (int i = 0; i < blockCount; i++)
		{
			bloks[i]->setYSize(15);
			bloks[i]->setXSize(getXSize() / 10);

			bloks[i]->setStrength(rand() % 4 + 1);
			bloks[i]->setXPosition((i % 10) * bloks[i]->getXSize());
		}

		for (int i = 0; i < blockCount; i++)
		{
			if (i / 10 == 0)
			{
				bloks[i]->setYPosition(getYSize() - menuSize);
			}
			else
			{
				bloks[i]->setYPosition(bloks[0]->getYPosition() - (i / 10) * bloks[i]->getYSize());
			}
		}
	}
}

void Window::DrawBloks()
{
	glBegin(GL_QUADS);

	for (int i = 0; i < blockCount; i++)
	{
		if (bloks[i]->getStrength() == 1)
		{
			bloks[i]->setRColor(0);
			bloks[i]->setGColor(1.0);
			bloks[i]->setBColor(0.0);
		}
		else if (bloks[i]->getStrength() == 2)
		{
			bloks[i]->setRColor(1.0);
			bloks[i]->setGColor(1.0);
			bloks[i]->setBColor(0.0);
		}
		else if (bloks[i]->getStrength() == 3)
		{
			bloks[i]->setRColor(0.1);
			bloks[i]->setGColor(0.2);
			bloks[i]->setBColor(0.8);
		}
		else if (bloks[i]->getStrength() == 4)
		{
			bloks[i]->setRColor(1.0);
			bloks[i]->setGColor(0.5);
			bloks[i]->setBColor(0.5);
		}

		glColor3f(bloks[i]->getRColor(), bloks[i]->getGColor(),	bloks[i]->getBColor());

		glVertex2d(bloks[i]->getXPosition(), bloks[i]->getYPosition());
		glVertex2d(bloks[i]->getXPosition() + bloks[i]->getXSize(),
			bloks[i]->getYPosition());
		glVertex2d(bloks[i]->getXPosition() + bloks[i]->getXSize(),
			bloks[i]->getYPosition() - bloks[i]->getYSize());
		glVertex2d(bloks[i]->getXPosition(),
			bloks[i]->getYPosition() - bloks[i]->getYSize());
	}

	glEnd();

	for (int i = 0; i < blockCount; i++)
	{
		glColor3f(0, 0, 0);

		glBegin(GL_LINE_LOOP);

		glVertex2d(bloks[i]->getXPosition(), bloks[i]->getYPosition());
		glVertex2d(bloks[i]->getXPosition() + bloks[i]->getXSize(),
			bloks[i]->getYPosition());
		glVertex2d(bloks[i]->getXPosition() + bloks[i]->getXSize(),
			bloks[i]->getYPosition() - bloks[i]->getYSize());
		glVertex2d(bloks[i]->getXPosition(),
			bloks[i]->getYPosition() - bloks[i]->getYSize());

		glEnd();
	}
}

void Window::BonusInitialise(int bonus_i, int blok_i)
{
	bonus[bonus_i]->setYSize(BONUS_SIZE_HEIGHT);
	bonus[bonus_i]->setXSize(BONUS_SIZE_WIDTH);
	bonus[bonus_i]->setXPosition(bloks[blok_i]->getXPosition() + bloks[blok_i]->getXSize() / 2
		- BONUS_SIZE_WIDTH / 2);
	bonus[bonus_i]->setYPosition(bloks[blok_i]->getYPosition() - bloks[blok_i]->getYSize() / 2
		+ BONUS_SIZE_HEIGHT / 2);
	bonus[bonus_i]->setType(BONUS_CHANSE);

	if (bonus[bonus_i]->getType() == 1)
	{
		bonus[bonus_i]->setRColor(1.0);
		bonus[bonus_i]->setGColor(0.1);
		bonus[bonus_i]->setBColor(0.1);
	}
	else if (bonus[bonus_i]->getType() == 2)
	{
		bonus[bonus_i]->setRColor(0.0);
		bonus[bonus_i]->setGColor(0.5);
		bonus[bonus_i]->setBColor(1.0);
	}
	else if (bonus[bonus_i]->getType() == 3)
	{
		bonus[bonus_i]->setRColor(1.0);
		bonus[bonus_i]->setGColor(0.5);
		bonus[bonus_i]->setBColor(0.0);
	}
	else if (bonus[bonus_i]->getType() == 4)
	{
		bonus[bonus_i]->setRColor(0.0);
		bonus[bonus_i]->setGColor(0.0);
		bonus[bonus_i]->setBColor(0.0);
	}

	bonus[bonus_i]->setXVec(0);
	bonus[bonus_i]->setYVec((-0.5) * SPEED);
}

void Window::CheckBonus(int bonus_i)
{
	int x0 = bonus[bonus_i]->getXPosition();
	int x1 = x0 + bonus[bonus_i]->getXSize();
	int y0 = bonus[bonus_i]->getYPosition() + (bonus[bonus_i]->getYVec();
	int y1 = y0 - bonus[bonus_i]->getYSize();

	if (y0 <= 0)
	{
		BonusDestroy(bonus_i);
	}
	else if ((x1 >= getXPosition())
		&& (x0 <= getXPosition() + getXSize())
		&& (y1 <= getYPosition()))
	{
		BonusCatch(bonus_i);
	}
}

void Window::BonusCatch(int bonus_i)
{
	score += 100;

	if (bonus[bonus_i]->getType() == 1)
	{
		BonusDestroy(bonus_i);		

		FireBallInitialise(ball);
	}
	else if (bonus[bonus_i]->getType() == 2)
	{
		BonusDestroy(bonus_i);		

		LittleRacketInitialise(racket);
	}
	else if (bonus[bonus_i]->getType() == 3)
	{
		BonusDestroy(bonus_i);		

		BigRacketInitialise(racket);
	}
	else if (bonus[bonus_i]->getType() == 4)
	{
		bonus[bonus_i]->BonusDestroy(bonus_i);		

		NewHP(hp);
	}
}

void Window::BonusDestroy(int bonus_i)
{
	for (int i = bonus_i; i < bonus.size(); i++)
	{
		bonus[i] = bonus[i + 1];
	}

	bonus.pop_back();
}

void Window::RenderBall()
{
	if (ball.getLaunchFlag() == 0)
	{
		BallInitialise();
	}
	else
	{
		CheckBall();
		ball.setXPosition(ball.getXPosition() + ball.getXVec());
		ball.setXPosition(ball.getYPosition() + ball.getYVec());
		Sleep(SLEEP);
	}
}

void Window::RenderBonus()
{
	for (int i = 0; i < getBonusCount(); i++)
	{
		CheckBonus(i);

		if (getBonusCount() != 0)
		{
			bonus[i]->setYPosition(bonus[i]->getYPosition() + bonus[i]->getYVec());
		}
	}
}

void Window::DrawBonus()
{
	glBegin(GL_QUADS);

	for (int i = 0; i < bonus.size(); i++)
	{
		glColor3f(bonus[i]->getRColor(),
			bonus[i]->getGColor(),
			bonus[i]->getBColor());

		glVertex2d(bonus[i]->getXPosition(), bonus[i]->getYPosition());
		glVertex2d(bonus[i]->getXPosition() + bonus[i]->getXSize(),
			bonus[i]->getYPosition());
		glVertex2d(bonus[i]->getXPosition() + bonus[i]->getXSize(),
			bonus[i]->getYPosition() - bonus[i]->getYSize());
		glVertex2d(bonus[i]->getXPosition(),
			bonus[i]->getYPosition() - bonus[i]->getYSize());
	}
	glEnd();
}



void Window::setBonusCount(int i)
{
	bonusCount = i;
}
void Window::setCount(int i)
{
	count = i;
}
void Window::setScore(int i)
{
	score = i;
}

int Window::getCount()
{
	return count;
}
int Window::getBlockCount()
{
	return blockCount;
}
int Window::getBonusCount()
{
	return bonusCount;
}
int Window::getBallCount()
{
	return ballCount;
}
int Window::getHp()
{
	return hp;
}
int Window::getLevel()
{
	return level;
}
int Window::getMenuSize()
{
	return menuSize;
}
int Window::getScore()
{
	return score;
}