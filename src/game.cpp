#include "game.h"

extern Game game = {GameStatus::MENU};

void initGame()
{
	game.status = GameStatus::IN_GAME;
}

void gameLoop()
{
	if (game.status == GameStatus::IN_GAME)
	{
		drawScene();
		moveBall();
	}
}