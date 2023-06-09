#pragma once

#include <algorithm>
#include <vector>

#include "3D_tools.h"

typedef struct Wall
{
	Color color;
	Coordinate coordinate;
	GLfloat width, height, depth;
} Wall;
typedef struct Line
{
	Color color;
	Coordinate coordinate;
} Line;

void drawCorridor();
void drawWall(Color color);
void drawLines(std::vector<Line *> *lines);
void addLine(std::vector<Line *> *lines, int i);
void drawLine(Line *line);
void moveLines(std::vector<Line *> *lines, float movingSpeed);