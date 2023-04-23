#include <algorithm>

#include <3D_tools.h>

typedef struct Color
{
	GLfloat r, g, b, a;
} Color;

typedef struct Coordinate
{
	GLfloat pos_x, pos_y, pos_z;
} Coordinate;

// Structure pour les murs
typedef struct Wall
{
	Color color;
	Coordinate coordinate;
	GLfloat width, height, depth;
} Wall;

Color darkenColor(Color color, GLfloat amount);
void drawWalls();
void drawWall(Color color);
