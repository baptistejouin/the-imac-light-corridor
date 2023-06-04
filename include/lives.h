#pragma once

#include <GL/gl.h>
#include <GL/glu.h>

#include "game.h"
#include "texture.h"

struct Life;
struct TextureLoaded;

enum LifeStatus
{
	CURRENT,
	LOST
};

void drawLifeCount(Life *lifeCount, std::map<const char *, TextureLoaded> *textures);