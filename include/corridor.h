#pragma once

#include <algorithm>
#include "3D_tools.h"

// Structure pour les murs
typedef struct Wall
{
	Color color;
	Coordinate coordinate;
	GLfloat width, height, depth;
} Wall;

void drawCorridor();
void drawWall(Color color);
void drawLines();
void drawLine();