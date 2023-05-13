#include "game.h"

Game game = {GameStatus::MENU};
Racket *racket = new Racket;
Cursor *cursor = new Cursor;
Ball *ball = new Ball;

void initGame()
{
	game.status = GameStatus::IN_GAME;

	racket->coordinate.pos_x = 0.0f;
	racket->coordinate.pos_y = 0.0f;
	racket->coordinate.pos_z = 0.0f;
	racket->size = 2.0f;

	cursor->x = 0.0f;
	cursor->y = 0.0f;

	ball->coordinate.pos_x = -15.0f;
	ball->coordinate.pos_y = 0.0f;
	ball->coordinate.pos_z = 0.0f;
}

void gameLoop(GLFWwindow *window)
{
	glfwGetCursorPos(window, &cursor->x, &cursor->y);

	if (game.status == GameStatus::IN_GAME)
	{
		drawScene(racket, ball);

		moveRacket(racket, cursor);
		moveBall(ball);
	}
}