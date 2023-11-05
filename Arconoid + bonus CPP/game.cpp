#include "game.h"
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
void GameInitialize(int level)
{
	wind = Window(Param::HP_COUNT, level, WINDOW_SIZEX, WINDOW_SIZEY, WINDOW_POSITIONX, WINDOW_POSITIONY); // утечка

	wind.menu = Menu(wind.getSize(0), Param::MENU_SIZE, wind.getSize(1) - 1);

	wind.racket = Racket(wind.getSize(0));

	wind.ball = Ball(wind.racket.getPosition(0), wind.racket.getPosition(1), wind.racket.getSize(0));

	wind.HpInitialize(wind.ball.getSize(0), wind.ball.getSize(1), wind.getSize(1));

	wind.ChooseLevel();

	SystemUpdate();
}

void GameUpdate(int hpCount, int next_level_flag, int level)
{
	wind.setLevel(level);
	wind.setHpCount(hpCount);

	wind.racket = Racket(wind.getSize(0));

	wind.ball = Ball(wind.racket.getPosition(0), wind.racket.getPosition(1), wind.racket.getSize(0));

	if (next_level_flag == 0)
	{
		wind.ChooseLevel();
	}

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
	wind.CheckBallColision();
	wind.ball.RenderBall(wind.racket.getPosition(0), wind.racket.getPosition(1), wind.racket.getSize(0));
	Sleep(Param::SLEEP);

	wind.RenderBonuses();

	Draw();
}
void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(1.0, 1.0, 1.0, 1.0);

	wind.menu.DrawPhysObject();

	wind.DrawHp();

	wind.DrawBloks();

	wind.racket.DrawPhysObject();

	wind.ball.DrawPhysObject();

	wind.DrawBonuses();

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
		glutPostRedisplay();
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
			GameUpdate(wind.getHpCount(), 0, wind.getLevel());
		}
	}
	else
	{
		if (wind.getHpCount() == 1)
		{
			SystemRelease();
		}
		else
		{
			wind.setHpCount(wind.getHpCount() - 1);
			wind.BonusRelease();
			GameUpdate(wind.getHpCount(), 1, wind.getLevel());
		}
	}
}