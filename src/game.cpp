#include "game.h"

extern Game game = {GameStatus::MENU};

Racket *racket = new Racket;

void initGame()
{
	game.status = GameStatus::IN_GAME;

	racket->coordinate.pos_x = 0.0f;
	racket->coordinate.pos_y = 0.0f;
	racket->coordinate.pos_z = 0.0f;
	racket->size = 0.5f;
}

void gameLoop()
{
	if (game.status == GameStatus::IN_GAME)
	{
		drawScene(racket);
		moveBall();
	}
}