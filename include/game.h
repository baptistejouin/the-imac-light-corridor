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
#include "bonus.h"

struct Ball;
struct Bonus;

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
	GLFWwindow *window;
	GameStatus status;
	Ball *ball;
	Racket *racket;
	Life *life;
	Cursor *cursor;
	std::vector<Bonus *> *bonus;
	std::vector<Obstacle *> *obstacles;
	std::vector<Line *> *lines;
	std::map<const char *, TextureLoaded> *textures;
	bool isMoving;
	int score;
	float movingSpeed;
} Game;

void initGame(Game *game, bool softInit = false);
void gameLoop(GLFWwindow *window, Game *game);
void closeGame(Game *game);
void resetGame(Game *game);