#pragma once

#include <vector>
#include <algorithm>
#include <math.h>

#include "3D_tools.h"
#include "racket.h"

typedef struct Obstacle
{
	int id;
	Coordinate coordinate;
	float width, height;
	Speed speed;
} Obstacle;

void drawObstacle(Obstacle *obstacle);
void drawObstacles(std::vector<Obstacle *> *obstacles);
void addObstacle(std::vector<Obstacle *> *obstacles, int i, Racket *racket);
void moveObstacles(std::vector<Obstacle *> *obstacles, Racket *racket);
void randomizeObstacle(Obstacle *obstacle, Racket *racket);
bool isCollidingWithRacket(std::vector<Obstacle *> *obstacles, Racket *racket);