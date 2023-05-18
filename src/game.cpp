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

	game->cursor->x = 0.0f;
	game->cursor->y = 0.0f;

	game->racket->coordinate.pos_x = 0.0f;
	game->racket->coordinate.pos_y = 0.0f;
	game->racket->coordinate.pos_z = 0.0f;
	game->racket->size = 2.0f;

	game->ball->size = 1.0f;
	game->ball->coordinate.pos_x = -50.0f + game->ball->size;
	game->ball->coordinate.pos_y = 0.0f;
	game->ball->coordinate.pos_z = 0.0f;
	game->ball->speed.x = 0.5f;
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

	if (game->status == GameStatus::IN_GAME)
	{
		glfwGetCursorPos(window, &game->cursor->x, &game->cursor->y);

		/*
		 *	Move the objects (auto)
		 */
		moveRacket(game->racket, game->cursor);
		moveBall(game->ball, game->racket, game->isMoving);

		/*
		 *	Move the objects (on key)
		 */
		if (game->isMoving)
		{
			moveObstacles(game->obstacles, game->racket);
			moveLines(game->lines);
		}

		/*
		 *	Draw the scene
		 */
		drawCorridor();
		drawLines(game->lines);
		drawRacket(game->racket);
		drawBall(game->ball);
		drawObstacles(game->obstacles);
		// todo: drawLives
	}
}