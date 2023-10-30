#pragma once

#include "physObjectClass.h"
#include "ballCLass.h"
#include "racketClass.h"
#include "blokClass.h"
#include "bonusClass.h"

#include <vector>

class Window: public PhysObject//, public Bonus
{
private:
	int hp;
	int level;
	int menuSize;
	int score;

	std::vector<Bonus*> bonus;
	std::vector<Blok*> bloks;

public:
	Ball ball;
	Racket racket;

	Window();
	Window(int windMenuSize, int newHp, int newLevel, int windSizex, int windSizey, int windPosx, int windPosy);

	void ChooseLevel();
	void CreateLvlOne();
	void CreateLvlTwo();
	void BlokDestroy(int i);
	void DrawBloks();

	void CheckBallColision();

	void BonusInitialise(int blok_i);
	void RenderBonus();
	void BonusCatch(int bonus_i);
	void BonusDestroy(int bonus_i);
	void DrawBonus();

	void NewHP();
	void DrawHP();

	void setMenuSize(int wind_menuSize);
	void setLevel(int wind_level);
	void setHp(int wind_hp);

	int getHp();
	int getLevel();
	int getScore();
	int getBlokSize();
};
