#include "game.h"
#include "ball.h"

Game game = {GameStatus::MENU};
Racket *racket = new Racket;
Cursor *cursor = new Cursor;
Ball ball;

void initGame()
{
	game.status = GameStatus::IN_GAME;

	racket->coordinate.pos_x = 0.0f;
	racket->coordinate.pos_y = 0.0f;
	racket->coordinate.pos_z = 0.0f;
	racket->size = 0.5f;

	cursor->x = 0.0f;
	cursor->y = 0.0f;
}

void gameLoop(GLFWwindow *window)
{
	glfwGetCursorPos(window, &cursor->x, &cursor->y);

	if (game.status == GameStatus::IN_GAME)
	{
		drawScene(racket);

		// log cursor pos
		// fprintf(stdout, "xpos: %f, ypos: %f\n", cursor->x, cursor->y);
		// log racket pos
		// fprintf(stdout, "xpos: %f, ypos: %f, zpos: %f\n", racket->coordinate.pos_x, racket->coordinate.pos_y, racket->coordinate.pos_z);

		moveRacket(racket, cursor);
		moveBall();

		if (!(ball.isSticky))
		{
			collision_walls();
			collision_racket();
		}
		
	}
}