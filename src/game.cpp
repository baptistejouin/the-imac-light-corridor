#include "game.h"

void *initGame(Game *game)
{
	int nbObstacte = 2;

	// TODO: When the menu is implemented, the game should start in the menu
	game->status = GameStatus::IN_GAME;
	game->cursor = new Cursor;
	game->ball = new Ball;
	game->racket = new Racket;
	game->lines = new std::vector<Line *>;
	game->obstacles = new std::vector<Obstacle *>;
	game->life = new Life;
	game->textures = new std::map<const char *, TextureLoaded>;

	game->life->max = 5;
	game->life->current = 3;

	game->cursor->x = 0.0f;
	game->cursor->y = 0.0f;

	game->racket->coordinate.pos_x = 0.0f;
	game->racket->coordinate.pos_y = 0.0f;
	game->racket->coordinate.pos_z = 0.0f;
	game->racket->size = 2.0f;

	game->ball->size = 1.0f;
	game->ball->coordinate.pos_x = -10.0f + game->ball->size;
	game->ball->coordinate.pos_y = 0.0f;
	game->ball->coordinate.pos_z = 0.0f;
	game->ball->speed.x = -0.3f;
	game->ball->isSticky = false;
	game->ball->color.r = 1.0f;
	game->ball->color.g = 1.0f;
	game->ball->color.b = 1.0f;
	game->ball->color.a = 1.0f;

	for (int i = 0; i < nbObstacte; i++)
	{
		addObstacle(game->obstacles, i, game->racket);
	}

	for (int i = 0; i < 4; i++)
	{
		addLine(game->lines, i);
	}

	initTextures(game);
}

void gameLoop(GLFWwindow *window, Game *game)
{

	if (game->status == GameStatus::IN_GAME || game->status == GameStatus::PAUSE)
	{
		if (game->status != GameStatus::PAUSE)
		{
			glfwGetCursorPos(window, &game->cursor->x, &game->cursor->y);
			/*
			 *	Move the objects (auto)
			 */
			moveRacket(game->racket, game->cursor);
			moveBall(game->ball, game->racket, game->obstacles, &game->status, game->life);

			/*
			 *	Move the objects (on key)
			 */
			if (game->isMoving && !isCollidingWithRacket(game->obstacles, game->racket))
			{
				moveObstacles(game->obstacles, game->racket);
				moveLines(game->lines);
				moveBallOnKey(game->ball);
			}
		}

		/*
		 *	Draw the scene
		 */
		drawCorridor();
		drawLines(game->lines);
		drawRacket(game->racket);
		drawBall(game->ball);
		drawObstacles(game->obstacles);

		// if we have the heart texture
		if (game->textures->count("heart") > 0)
			drawLifeCount(game->life, game->textures->at("heart").textureID);

		// for (auto &texture : *game->textures)
		// {
		// 	stbi_image_free(texture.second.stbImage);
		// 	glDeleteTextures(1, &texture.second.GLtexture);
		// 	glBindTexture(GL_TEXTURE_2D, 0);
		// }
	}

	if (game->status == GameStatus::GAME_OVER)
	{
		// todo: make menu for game over

		glPushMatrix();
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 0.0f, -5.0f);
		drawSquare(false, 1.0f);
		glPopMatrix();
	}

	if (game->status == GameStatus::MENU)
	{
	}
}

void closeGame(Game *game)
{
	delete game->cursor;
	delete game->ball;
	delete game->racket;
	delete game->obstacles;
	delete game->lines;

	for (auto &texture : *game->textures)
	{
		stbi_image_free(&texture.second.stbImage);
		glDeleteTextures(1, &texture.second.textureID);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	glfwTerminate();
}