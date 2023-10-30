#include "gameClass.h"
#include "windowClass.h"

#include <glut.h>
#include <windows.h>
#include <math.h>
#include <iostream>

Window wind;

void SystemOpen(int argc, char** argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
}
void SystemRelease()
{
	std::cout << "END" << std::endl << wind.getScore() << std::endl;
	exit(1);
}
void SystemInitialise(int hp, int next_level_flag, int blockCount, int level)
{
	wind.setSize(WINDOW_SIZEX, WINDOW_SIZEY);
	wind.setPosition(WINDOW_POSITIONX, WINDOW_POSITIONY);
	wind.setMenuSize(MENU_SIZE);

	wind.setLevel(level);
	wind.setHp(hp);


	wind.racket.RacketInitialise(wind.getSize(0));

	//wind.ball = new class Ball;

	wind.ball = Ball(wind.racket.getPosition(0), wind.racket.getPosition(1), wind.racket.getSize(0));

	if (next_level_flag == 0)
	{
		wind.ChooseLevel();
	}

	//ball.ReleaseFireBall();

	SystemUpdate();
}
void SystemUpdate()
{
	glutInitWindowPosition(wind.getPosition(0), wind.getPosition(1));
	glutInitWindowSize(wind.getSize(0), wind.getSize(1));
	glutCreateWindow("ARCONOID");

	gluOrtho2D(0, wind.getSize(0), 0, wind.getSize(1));
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutPassiveMotionFunc(MouseMove);
	glutMouseFunc(MouseButton);

	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene);

	glutMainLoop();
}


void RenderScene()
{
	if (wind.ball.RenderBall(wind.racket.getPosition(0), wind.racket.getPosition(1), wind.racket.getSize(0)))
	{
		wind.CheckBallColision();
		wind.ball.setPosition(wind.ball.getPosition(0) + wind.ball.getVec(0),
			wind.ball.getPosition(1) + wind.ball.getVec(1));
		Sleep(SLEEP);
	}

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
	wind.racket.DrawRacket();

	//BONUS
	wind.DrawBonus();

	//BALL	
	wind.ball.DrawBall();

	glutSwapBuffers();
}


void MouseMove(int x, int y)
{
	wind.racket.RenderRacket(x, y, wind.getSize(0));

	glutPostRedisplay();
}
void MouseButton(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		wind.ball.BallLaunch(wind.racket.getRacketSpeed(0) - wind.racket.getRacketSpeed(1));
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
			SystemInitialise(wind.getHp(), 1, wind.getBlokSize(), wind.getLevel());
		}
	}
}