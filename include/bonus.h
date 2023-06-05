#pragma once

#include "3D_tools.h"
#include "ball.h"
#include "texture.h"

struct Ball;

enum class BonusType
{
	ONE_UP,
	STICKY_RACKET,
};

typedef struct Bonus
{
	int id;
	Coordinate coordinate;
	float size;
	int rotation;
	BonusType type;
	Color color;
};

void drawBonuss(std::vector<Bonus *> *bonus);
void moveBonuss(std::vector<Bonus *> *bonus, Ball *ball, Racket *racket, Life *lifeCount, float movingSpeed, bool onKey);
void generateBonus(int score, std::vector<Bonus *> *bonus);