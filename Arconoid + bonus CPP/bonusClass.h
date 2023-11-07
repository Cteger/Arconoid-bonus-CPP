#pragma once
#include "game.h"
#include "racketClass.h"
#include "ballClass.h"
#include "vectorStruct.h"
#include "physObjectClass.h"

class Bonus : public PhysObject, public Vector
{
private:
	int type;

public:
	Bonus() {};
	Bonus(int blokPosx, int blokPosy, int blokSizex, int blokSizey);
	virtual~Bonus() {};

	virtual void BonusInitialize(Racket& racket, Ball& ball, int& hpCount, int maxHp) {};

	int RenderBonus(double racketPosx, double racketPosy, double racketSizex);

	int CheckBonus(double racketPosx, double racketPosy, double racketSizex);
};

class Barrier : public Bonus
{
public:
	Barrier() {}
	Barrier(int blokPosx, int blokPosy, int blokSizex, int blokSizey) : Bonus(blokPosx, blokPosy, blokSizex, blokSizey)
	{
		setColor(0.0, 1.0, 0.0);
	}
	~Barrier() {};

	void BonusInitialize(Racket& racket, Ball& ball, int& hpCount, int maxHp) override
	{
		ball.setIsBarrier(1);
	}
};

class FireBall : public Bonus
{
public:
	FireBall() {}
	FireBall(int blokPosx, int blokPosy, int blokSizex, int blokSizey) : Bonus(blokPosx, blokPosy, blokSizex, blokSizey)
	{
		setColor(1.0, 0.1, 0.1);
	}
	~FireBall() {}

	void BonusInitialize(Racket& racket, Ball& ball, int& hpCount, int maxHp) override
	{
		ball.setIsFireBall(1);

		ball.setColor(1, 0.1, 0.1);
	}
};

class LittleRacket : public Bonus
{
public:
	LittleRacket() {}
	LittleRacket(int blokPosx, int blokPosy, int blokSizex, int blokSizey) : Bonus(blokPosx, blokPosy, blokSizex, blokSizey)
	{
		setColor(0.0, 0.5, 1.0);
	}
	~LittleRacket() {}

	void BonusInitialize(Racket& racket, Ball& ball, int& hpCount, int maxHp) override
	{
		racket.setSize((racket.getSize(0) / 2), racket.getSize(1));

		racket.setColor(0.0, 0.0, 1.0);
	}
};

class BigRacket : public Bonus
{
public:
	BigRacket() {}
	BigRacket(int blokPosx, int blokPosy, int blokSizex, int blokSizey) : Bonus(blokPosx, blokPosy, blokSizex, blokSizey)
	{
		setColor(1.0, 0.5, 0.0);
	}
	~BigRacket() {}

	void BonusInitialize(Racket& racket, Ball& ball, int& hpCount, int maxHp) override
	{
		racket.setSize((racket.getSize(0) * 1.2), racket.getSize(1));

		racket.setColor(1.0, 0.0, 0.0);
	}
};

class NewHp : public Bonus
{
private:

public:
	NewHp() {}
	NewHp(int blokPosx, int blokPosy, int blokSizex, int blokSizey) : Bonus(blokPosx, blokPosy, blokSizex, blokSizey)
	{
		setColor(0.0, 0.0, 0.0);
	}
	~NewHp() {}

	void BonusInitialize(Racket& racket, Ball& ball, int& hpCount, int maxHp) override
	{
		if (hpCount < maxHp)
		{
			hpCount = hpCount + 1;
		}
	}
};