#pragma once

#include <math.h>
#include <algorithm>

#include "game.h"
#include "3D_tools.h"
#include "racket.h"
#include "obstacle.h"

struct Life;
enum class GameStatus;

typedef struct Ball
{
	Coordinate coordinate;
	float size;
	bool isSticky;
	Speed speed;
	Color color;
} Ball;

void drawBall(Ball *ball);
void moveBall(Ball *ball, Racket *racket, std::vector<Obstacle *> *obstacles, GameStatus *status, Life *lifeCount);
void moveBallOnKey(Ball *ball, float movingSpeed);
void makeBallSticky(Ball *ball);