#pragma once

#include <math.h>
#include "3D_tools.h"

typedef struct Racket
{
	Coordinate coordinate;
	GLfloat size;
} Racket;

void drawRacket(Racket *racket);
void moveRacket(Racket *racket, Cursor *cursor);