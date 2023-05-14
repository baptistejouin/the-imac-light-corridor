#pragma once

#include <vector>
#include <math.h>

#include "3D_tools.h"

typedef struct Obstacle
{
	Coordinate coordinate;
	GLfloat size;
} Obstacle;

void drawObstacle(Obstacle *obstacle);
void drawObstacles(std::vector<Obstacle *> *obstacles);
void addObstacle(std::vector<Obstacle *> *obstacles, int i);
void moveObstacles(std::vector<Obstacle *> *obstacles);