#pragma once

#include "draw_scene.h"
#include "ball.h"

enum class GameStatus
{
	MENU,
	IN_GAME
};

typedef struct Game
{
	GameStatus status;
} Game;

extern Game game;
extern Cursor *cursor;

void initGame();
void gameLoop(GLFWwindow *window);