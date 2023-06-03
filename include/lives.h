#pragma once

#include <GL/gl.h>
#include <GL/glu.h>

#include "game.h"

struct Life;

enum LifeStatus
{
	CURRENT,
	LOST
};

void drawLifeCount(Life *lifeCount, GLuint heartTexture);