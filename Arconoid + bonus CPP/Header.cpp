#include "Header.h"
#include "Bloks.h"
#include "Ball.h"
#include "Racket.h"
#include "Bonus.h"
#include "Fire_Ball.h"
#include <stdio.h>
#include <string.h>
#include <glut.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

struct Window wind;

void SystemOpen(int argc, char** argv)
{	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
}

void SystemInitialise(int hp, struct Blok* bloks, int blok_count, int level)
{
	wind.size.width = WINDOW_SIZEX;
	wind.size.height = WINDOW_SIZEY;
	wind.position.x = WINDOW_POSITIONX;
	wind.position.y = WINDOW_POSITIONY;
	wind.menu_size = MENU_SIZE;

	wind.level = level;
	wind.hp = hp;

	wind.racket = RacketInitialise(wind);

	wind.ball = BallInitialise(wind);

	wind = Level(wind, bloks, blok_count, wind.level);

	wind.bonus_count = 0;

	wind = Release_Fire_Ball(wind);

	SystemUpdate();
}

void SystemUpdate()
{
	glutInitWindowPosition(wind.position.x, wind.position.y);
	glutInitWindowSize(wind.size.width, wind.size.height);
	wind.glutNum = glutCreateWindow("ARCONOID");

	gluOrtho2D(0, wind.size.width, 0, wind.size.height);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutPassiveMotionFunc(MouseMove);
	glutMouseFunc(MouseButton);

	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene);

	glutMainLoop();
}

void SystemRelease()
{
	std::cout << "END" << std::endl << wind.score << std::endl;
	exit(1);
}

void RenderScene()
{
	if (wind.ball.launch == 0)
	{
		wind.ball = BallInitialise(wind);
	}
	else
	{
		wind.ball.vector = CheckBall(wind);
		wind.ball.position.x += wind.ball.vector.x;
		wind.ball.position.y += wind.ball.vector.y;
		Sleep(SLEEP);
	}

	for (int i = 0; i < wind.bonus_count; i++)
	{
		wind = CheckBonus(wind, i);

		if (wind.bonus_count != 0)
		{
			(wind.bonus + i)->position.x += (wind.bonus + i)->vector.x;
			(wind.bonus + i)->position.y += (wind.bonus + i)->vector.y;
		}
	}

	Draw();
}

void Draw()
{
	// ������� ������ ����� � �������
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(1.0, 1.0, 1.0, 1.0);

	//MENU
	DrawHP(wind);

	//BLOKS
	DrawBloks(wind);

	//RACKET
	DrawRacket(wind);

	//BONUS
	DrawBonus(wind);

	//BALL	
	DrawBall(wind);

	glutSwapBuffers();
}

void MouseMove(int x, int y)
{
	wind.racket.speed[1] = wind.racket.speed[0];
	wind.racket.speed[0] = x;

	if (wind.count == 10)
	{
		wind.buffer[0] = wind.racket.position.x + wind.racket.size.width / 2;

		for (int i = 1; i < 10; i++)
		{
			wind.buffer[i] = wind.buffer[i-1];
		}
		wind.count = 0;
	}
	wind.count++;

	if (x >= wind.size.width - wind.racket.size.width + wind.racket.size.width / 2)
	{
		wind.racket.position.x = wind.size.width - wind.racket.size.width;
	}
	else if (x <= wind.racket.size.width / 2)
	{
		wind.racket.position.x = 0;
	}
	else
	{
		wind.racket.position.x = x - wind.racket.size.width / 2;
	}

	glutPostRedisplay();
}

void MouseButton(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) &&
		(wind.ball.launch == 0))
	{
		wind.ball.vector.x = wind.racket.speed[0] - wind.racket.speed[1] + 1;
		wind.ball.vector.y = powf(powf(SPEED, 2) - powf(wind.ball.vector.x, 2), 0.5);
		wind.ball.launch = 1;
		glutPostRedisplay();
	}
}

void Destroy(int i)
{
	if (wind.blok_count == 1)
	{
		EndGame(1);
	}
	else
	{
		if ((wind.bloks + i)->strength == 1 || wind.ball.fire_flag == 1)
		{
			if ((rand() % 10 + 1) == 1)
			{
				wind = BonusInitialise(wind, wind.bonus_count, i);
			}

			for (int j = i; j < wind.blok_count - 1; j++)
			{
				wind.bloks[j] = wind.bloks[j + 1];
			}

			wind.blok_count--;

			wind.bloks = (struct Blok*)realloc(wind.bloks,
				wind.blok_count * sizeof(struct Blok));

			wind.score += 20;
		}
		else
		{
			(wind.bloks + i)->strength--;
			wind.score += 30;
		}
	}
}

void EndGame(int win_point)
{
	if (win_point == 1)
	{
		if (wind.level == 2)
		{
			SystemRelease();
		}
		wind.level++;
		SystemInitialise(wind.hp, 0, 0, wind.level);
	}
	else
	{
		if (wind.hp == 1)
		{
			SystemRelease();
		}
		else
		{
			wind.hp--;
			SystemInitialise(wind.hp, wind.bloks, wind.blok_count, wind.level);
		}
	}
}