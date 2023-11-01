#pragma once // crtgbg map alloc

#include "physObjectClass.h"
#include "ballCLass.h"
#include "racketClass.h"
#include "blokClass.h"
#include "bonusClass.h"

#include <vector>

class Window : public PhysObject
{
private:
	int hp;
	int level;
	int menuSize = MENU_SIZE; //const
	int score;

	std::vector<Bonus*> bonus;
	std::vector<Blok*> bloks;

public:
	Ball ball;
	Racket racket;

	Window();
	Window(int newHp, int newLevel, int windSizex, int windSizey, int windPosx, int windPosy);

	void ChooseLevel();
	void CreateLvlOne();
	void CreateLvlTwo();
	void BlokDestroy(int i);
	void DrawBloks();

	void CheckBallColision();

	void BonusInitialise(int blok_i);
	void RenderBonus();
	void BonusRelease();
	void BonusCatch(int bonus_i);
	void BonusDestroy(int bonus_i);
	void DrawBonus();

	void NewHP();
	void DrawHP();

	void setLevel(int wind_level);
	void setHp(int wind_hp);

	int getHp();
	int getLevel();
	int getScore();
};
