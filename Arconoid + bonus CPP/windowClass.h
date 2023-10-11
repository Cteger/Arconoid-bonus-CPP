#pragma once

#include "physClass.h"
#include "ballCLass.h"
#include "racketClass.h"
#include "blokClass.h"
#include "bonusClass.h"

#include <vector>

class Window: public PhysObject
{
private:
	float buffer[10];
	int count;
	int blockCount;
	int ballCount;
	int hp;
	int level;
	int menuSize;
	int score;

	Ball ball;
	Racket racket;

	std::vector<Bonus*> bonus;
	std::vector<Blok*> bloks;
public:
	
	void CreateLevel();
	void DrawBloks();

	void RacketInitialise();
	void DrawRacket();

	void BallInitialise();
	void CheckBall();
	void DrawBall();

	void BonusInitialise(int bonus_i, int blok_i);
	void CheckBonus(int bonus_i);
	void BonusCatch(int bonus_i);
	void BonusDestroy(int bonus_i);
	void DrawBonus();


	void RenderBall();
	void RenderBonus();

	void setMenuSize(int wind_menuSize);
	void setLevel(int wind_level);
	void setHp(int wind_hp);
	void setBonusCount(int i);
	void setCount(int i);
	void setScore(int i);

	int getCount();
	int getBlockCount();
	int getBonusCount();
	int getBallCount();
	int getHp();
	int getLevel();
	int getMenuSize();
	int getScore();

	void DrawHP();
};
