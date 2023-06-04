#include "game.h"

int nbObstacte = 2;

void initGame(Game *game, bool softInit)
{
	game->status = softInit ? game->status : GameStatus::MENU;
	game->cursor = new Cursor;
	game->ball = new Ball;
	game->racket = new Racket;
	game->lines = new std::vector<Line *>;
	game->obstacles = new std::vector<Obstacle *>;
	game->life = new Life;
	game->textures = softInit ? game->textures : new std::map<const char *, TextureLoaded>;
	game->life->max = 3;
	game->life->current = 2;

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

	// TODO: handle isSticky, (true when implemented)
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
		drawLifeCount(game->life, game->textures);
	}

	if (game->status == GameStatus::GAME_OVER)
	{
		drawGameOver(&game->status, game->textures);
	}

	if (game->status == GameStatus::MENU)
	{
		drawMenu(&game->status, game->textures);
	}
}

void closeGame(Game *game)
{
	delete game->cursor;
	delete game->ball;
	delete game->racket;
	delete game->obstacles;
	delete game->lines;
	delete game->life;

	for (auto texture = game->textures->begin(); texture != game->textures->end(); ++texture)
	{
		printf("Freeing texture: %s\n", texture->first);
		glDeleteTextures(1, &texture->second.textureID);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	printf("Closing game\n");
	glfwSetWindowShouldClose(game->window, GLFW_TRUE);

	delete game;
}

void resetGame(Game *game)
{
	game->status = GameStatus::IN_GAME;
	initGame(game, true);
}