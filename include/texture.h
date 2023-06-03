#pragma once

#include "game.h"
#include "3D_tools.h"

struct Game;

typedef struct TextureLoaded
{
	GLuint textureID;
	unsigned char *stbImage;
	int width, height, nbChannels;

} TextureLoaded;

void initTextures(Game *game);