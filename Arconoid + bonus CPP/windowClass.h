#pragma once

#include "physObjectClass.h"
#include "ballCLass.h"
#include "racketClass.h"
#include "blokClass.h"
#include "bonusClass.h"
#include "menuClass.h"

#include <vector>
#include <array>

class Window : public PhysObject
{
private:
	int level;
	int hpCount;
	int maxHp;// static
	int score;

	std::array<Hp, Param::HP_COUNT> hp;
	std::vector<Bonus> bonus;
	std::vector<Blok> bloks;

public:

	Menu menu;
	Ball ball;
	Racket racket;

	void HpInitialize(int ballSizex, int ballSizey, int windSizey);
	void NewHP();

	Window() {};
	Window(int hpCount, int newLevel, int windSizex, int windSizey, int windPosx, int windPosy);

	void ChooseLevel();
	void CreateLvlOne();
	void CreateLvlTwo();
	void BlokDestroy(int i);

	void CheckBallColision();

	void BonusInitialise(int blok_i);
	void RenderBonus();
	void BonusRelease();
	void BonusCatch(int bonus_i);
	void BonusDestroy(int bonus_i);

	void DrawHp();
	void DrawBloks();
	void DrawBonus();

	void setLevel(int level) { this->level = level; };
	void setHpCount(int hpCount) { this->hpCount = hpCount; };

	int getLevel() { return level; };
	int getScore() { return score; };
	int getHpCount() { return hpCount; };
};