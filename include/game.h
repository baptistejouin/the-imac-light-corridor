#pragma once

#include <vector>
#include <map>

#include "3D_tools.h"
#include "texture.h"
#include "ball.h"
#include "racket.h"
#include "corridor.h"
#include "obstacle.h"
#include "lives.h"
#include "menu.h"

struct Ball;

typedef struct Life
{
	int max;
	int current;
} Life;

enum class GameStatus
{
	MENU,
	IN_GAME,
	PAUSE,
	GAME_OVER
};

typedef struct Game
{
	GameStatus status;
	Racket *racket;
	Ball *ball;
	bool isMoving;
	float movingSpeed;
	Life *life;
	std::vector<Obstacle *> *obstacles;
	std::vector<Line *> *lines;
	Cursor *cursor;
	std::map<const char *, TextureLoaded> *textures;
	GLFWwindow *window;
} Game;

void initGame(Game *game, bool softInit = false);
void gameLoop(GLFWwindow *window, Game *game);
void closeGame(Game *game);
void resetGame(Game *game);