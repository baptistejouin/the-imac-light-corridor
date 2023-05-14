#include "game.h"

void *initGame(Game *game)
{
	int nbObstacte = 1;

	// TODO: When the menu is implemented, the game should start in the menu
	game->status = GameStatus::IN_GAME;
	game->ball = new Ball;
	game->racket = new Racket;
	game->obstacles = new std::vector<Obstacle *>;
	game->cursor = new Cursor;

	game->cursor->x = 0.0f;
	game->cursor->y = 0.0f;

	game->racket->coordinate.pos_x = 0.0f;
	game->racket->coordinate.pos_y = 0.0f;
	game->racket->coordinate.pos_z = 0.0f;
	game->racket->size = 2.0f;

	game->ball->coordinate.pos_x = -15.0f;
	game->ball->coordinate.pos_y = 0.0f;
	game->ball->coordinate.pos_z = 0.0f;

	for (int i = 0; i < nbObstacte; i++)
	{
		addObstacle(game->obstacles, i);
	}
}

void gameLoop(GLFWwindow *window, Game *game)
{

	if (game->status == GameStatus::IN_GAME)
	{
		glfwGetCursorPos(window, &game->cursor->x, &game->cursor->y);

		/*
		 *	Move the objects
		 */
		moveRacket(game->racket, game->cursor);
		// moveObstacles(game->obstacles);
		moveBall(game->ball);
		// todo: moveLines

		/*
		 *	Draw the scene
		 */
		drawCorridor();
		drawLines();
		drawRacket(game->racket);
		drawBall(game->ball);
		drawObstacles(game->obstacles);
		// todo: drawLives
	}
}