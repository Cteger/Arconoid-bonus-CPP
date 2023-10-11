#include "Header.h"
#include "blokClass.h"
#include "ballClass.h"
#include "racketClass.h"
#include "windowClass.h"

#include <glut.h>
#include <math.h>
#include <windows.h>
#include <iostream>

Window wind;

void SystemOpen(int argc, char** argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
}

void SystemInitialise(int hp, int next_level_flag, int blockCount, int level)
{
	wind.setXSize(WINDOW_SIZEX);
	wind.setYSize(WINDOW_SIZEY);
	wind.setXPosition(WINDOW_POSITIONX);
	wind.setYPosition(WINDOW_POSITIONY);
	wind.setMenuSize(MENU_SIZE);

	wind.setLevel(level);
	wind.setHp(hp);


	wind.RacketInitialise();

	//wind.ball = new class Ball;

	wind.BallInitialise();

	wind.setLevel(level); //????

	if (next_level_flag == 0)
	{
		wind.CreateLevel();
	}

	wind.setBonusCount(0);

	//ReleaseFireBall(wind.ball);

	SystemUpdate();
}

void SystemUpdate()
{
	glutInitWindowPosition(wind.getXPosition(), wind.getYPosition());
	glutInitWindowSize(wind.getXSize(), wind.getYSize());
	glutCreateWindow("ARCONOID");

	gluOrtho2D(0, wind.getXSize(), 0, wind.getYSize());
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutPassiveMotionFunc(MouseMove);
	glutMouseFunc(MouseButton);

	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene);

	glutMainLoop();
}

void SystemRelease()
{
	std::cout << "END" << std::endl << wind.getScore() << std::endl;
	exit(1);
}

void RenderScene()
{
	wind.RenderBall();

	wind.RenderBonus();

	Draw();
}

void Draw()
{
	// очистка буфера цвета и глубины
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(1.0, 1.0, 1.0, 1.0);

	//MENU
	wind.DrawHP();

	//BLOKS
	wind.DrawBloks();

	//RACKET
	wind.DrawRacket();

	//BONUS
	DrawBonus(wind.bonus, wind.getBonusCount());

	//BALL	
	wind.DrawBall();

	glutSwapBuffers();
}

void MouseMove(int x, int y)
{
	wind.racket.setRacketSpeed(wind.racket.getRacketSpeed(), 1);
	wind.racket.setRacketSpeed(x, 0);

	wind.setCount(wind.getCount() + 1);

	if (x >= wind.getXSize() - wind.racket.getXSize() / 2)
	{
		wind.racket.setXPosition(wind.getXSize() - wind.racket.getXSize() / 2);
	}
	else if (x <= wind.racket.getXSize() / 2)
	{
		wind.racket.setXPosition(0);
	}
	else
	{
		wind.racket.setXPosition(x - wind.racket.getXSize() / 2);
	}

	glutPostRedisplay();
}

void MouseButton(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) &&
		(wind.ball.getLaunchFlag() == 0))
	{
		wind.ball.setXVec(wind.racket.getRacketSpeed() - wind.racket.getRacketSpeed() + 1
			- wind.ball.getMaxSpeed() / 10);
		wind.ball.setYVec(sqrt(wind.ball.getMaxSpeed() * wind.ball.getMaxSpeed()
			- wind.ball.getXVec() * wind.ball.getXVec()));
		wind.ball.setLaunchFlag(1);
		glutPostRedisplay();
	}
}

void Destroy(int i)
{
	if (wind.getBlockCount() == 1)
	{
		EndGame(1);
	}
	else
	{
		if (wind.bloks[i]->getStrength() == 1 || wind.ball.fire_ball_flag == 1)
		{
			if (BONUS_CHANSE == 1)
			{
				wind.setBonusCount(wind.getBonusCount() + 1);
				wind.bonus = (class Bonus*)realloc(wind.bonus, wind.bonusCount * sizeof(class Bonus));
				BonusInitialise(wind.bonus[wind.bonusCount - 1], wind.bloks[i]);
			}

			for (int j = i; j < wind.blockCount - 1; j++)
			{
				wind.bloks[j] = wind.bloks[j + 1];
			}

			wind.blockCount--;

			wind.bloks = (class Blok*)realloc(wind.bloks,
				wind.blockCount * sizeof(class Blok));

			wind.score += 20;
		}
		else
		{
			(wind.bloks + i)->strength--;
			wind.setScore(wind.getScore() + 30);
		}
	}
}

void EndGame(int win_point)
{
	if (win_point == 1)
	{
		if (wind.getLevel() == 2)
		{
			SystemRelease();
		}
		else
		{
			wind.setLevel(wind.getLevel() + 1);
			SystemInitialise(wind.getHp(), 0, 0, wind.getLevel());
		}
	}
	else
	{
		if (wind.getHp() == 1)
		{
			SystemRelease();
		}
		else
		{
			wind.setHp(wind.getHp() - 1);
			SystemInitialise(wind.getHp(), 1, wind.getBlockCount(), wind.getLevel());
		}
	}
}