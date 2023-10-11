#include "racketClass.h"
#include <glut.h>

void Racket::setRacketSpeed(int new_speed, int i)
{
	racketSpeed[i] = new_speed;
}

int Racket::getRacketSpeed(int i)
{
	return racketSpeed[i];
}