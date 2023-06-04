#include "texture.h"

TextureLoaded loadTexture(const char *path, Game *game)
{
	int x, y, n;
	unsigned char *image = stbi_load(path, &x, &y, &n, STBI_rgb_alpha);

	if (!image)
	{
		printf("Image non chargée\n");
		stbi_image_free(image);
		closeGame(game);
	}

	GLuint texture;

	GLenum formatTexture;
	if (n == 1)
		formatTexture = GL_RED;
	else if (n == 3)
		formatTexture = GL_RGB;
	else if (n == 4)
		formatTexture = GL_RGBA;

	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, formatTexture, x, y, 0, formatTexture, GL_UNSIGNED_BYTE, image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// garder la pixelisation (sinon GL_LINEAR pour lisser)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	if (formatTexture == GL_RGBA)
	{
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.0f);
	}

	stbi_image_free(image);

	return {texture, image, x, y, n};
}

void initTextures(Game *game)
{
	TextureLoaded heartTexture = loadTexture("assets/lifebar_16x16.png", game);
	TextureLoaded logoTexture = loadTexture("assets/logo.png", game);
	TextureLoaded gameOverTexture = loadTexture("assets/game-over.png", game);
	TextureLoaded gamePausedTexture = loadTexture("assets/game-paused.png", game);
	TextureLoaded buttonPLay = loadTexture("assets/button-play.png", game);
	TextureLoaded buttonQuit = loadTexture("assets/button-quit.png", game);
	TextureLoaded buttonRetry = loadTexture("assets/button-retry.png", game);

	game->textures->insert(std::make_pair("heart", heartTexture));
	game->textures->insert(std::make_pair("logo", logoTexture));
	game->textures->insert(std::make_pair("game_over", gameOverTexture));
	game->textures->insert(std::make_pair("game_paused", gamePausedTexture));
	game->textures->insert(std::make_pair("play", buttonPLay));
	game->textures->insert(std::make_pair("quit", buttonQuit));
	game->textures->insert(std::make_pair("retry", buttonRetry));
}