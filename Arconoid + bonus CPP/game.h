#pragma once

#define CHANCE_OF_RANDOM_BLOK (rand() % 5 + 1)
#define CHANCE_OF_RANDOM_BONUS (rand() % 6)

enum Param
{
	BALL_SIZE_HEIGHT = 10,
	BALL_SIZE_WIDTH = 10,
	WINDOW_POSITIONX = 200,
	WINDOW_POSITIONY = 50,
	WINDOW_SIZEX = 400,
	WINDOW_SIZEY = 600,
	RACKET_WIDTH = 100,
	RACKET_HIGHT = 7,
	RACKET_YPOSITION = 10,
	BONUS_SIZE_HEIGHT = 30,
	BONUS_SIZE_WIDTH = 30,
	MENU_SIZE = 20,
	SLEEP = 9,
	SPEED = 7,
	HP_COUNT = 3
};

void SystemOpen(int argc, char** argv);
void SystemRelease();
void GameInitialize(int level);
void GameUpdate(int hpCount, bool isNextLevel, int level);
void SystemUpdate();

void RenderScene();
void Draw();

void MouseMove(int x, int y);
void MouseButton(int button, int state, int x, int y);

void EndGame(int win_point);