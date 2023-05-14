#pragma once

#include "3D_tools.h"
#include "draw_scene.h"
#include "ball.h"
#include "racket.h"
#include "walls.h"

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