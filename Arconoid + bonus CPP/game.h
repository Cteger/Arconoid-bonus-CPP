#pragma once
#define BALL_SIZE_HEIGHT 10
#define BALL_SIZE_WIDTH 10
#define WINDOW_POSITIONX 200
#define WINDOW_POSITIONY 50
#define WINDOW_SIZEX 400
#define WINDOW_SIZEY 600
#define RACKET_WIDTH 100
#define RACKET_HIGHT 7
#define RACKET_YPOSITION 10
#define BONUS_SIZE_HEIGHT 30
#define BONUS_SIZE_WIDTH 30
#define MENU_SIZE 20
#define SLEEP 1
#define SPEED 7
#define CHANCE_OF_RANDOM (rand() % 4 + 1)
#define CHANCE_OF_RANDOM_BONUS (rand() % 4 + 1)

void SystemOpen(int argc, char** argv);
void SystemRelease();
void SystemInitialise(int hp, int next_level_flag, int blockCount, int level);
void SystemUpdate();

void RenderScene();
void Draw();

void MouseMove(int x, int y);
void MouseButton(int button, int state, int x, int y);

void EndGame(int win_point);