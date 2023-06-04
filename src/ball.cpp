#include "ball.h"

void drawBall(Ball *ball)
{
	glPushMatrix();
	glTranslatef(ball->coordinate.pos_x, ball->coordinate.pos_y, ball->coordinate.pos_z);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	drawSphere(ball->size, ball->color);
	glPopMatrix();
}

void handleCollision(Ball *ball, Racket *racket, std::vector<Obstacle *> *obstacles, GameStatus *status, Life *lifeCount)
{
	// collision with the corridor (left, right)
	if ((ball->coordinate.pos_y > (10 - ball->size)) || (ball->coordinate.pos_y < (-10 + ball->size)))
	{
		ball->speed.y = -ball->speed.y;
		return;
	}

	// collision with the corridor (top, bottom)
	if ((ball->coordinate.pos_z > (5.5 - ball->size)) || (ball->coordinate.pos_z < (-4.5 + ball->size)))
	{
		ball->speed.z = -ball->speed.z;
		return;
	}

	// collision with the end of the corridor
	if (ball->coordinate.pos_x < (-50 + ball->size))
	{
		ball->speed.x = -ball->speed.x;
		return;
	}

	// collision with the obstacles (TODO: not perfectly implemented)
	for (size_t i = 0; i < obstacles->size(); i++)
	{
		Obstacle *obstacle = obstacles->at(i);

		float ballX = ball->coordinate.pos_x + (10 - ball->size);
		float obstacleX = obstacle->coordinate.pos_x;

		float margin = .8;

		bool isCollisionX = ((ballX + ball->size >= (obstacleX - margin)) && (ballX <= (obstacleX + margin)));

		bool isCollsionY = ((ball->coordinate.pos_y - ball->size < (obstacle->coordinate.pos_y + obstacle->width)) &&
							(ball->coordinate.pos_y + ball->size > (obstacle->coordinate.pos_y - obstacle->width)));

		bool isCollsionZ = ((ball->coordinate.pos_z - ball->size < (obstacle->coordinate.pos_z + obstacle->height)) &&
							(ball->coordinate.pos_z + ball->size > (obstacle->coordinate.pos_z - obstacle->height)));

		if (isCollisionX && isCollsionY && isCollsionZ)
		{
			ball->speed.x = -ball->speed.x;
			// *status = GameStatus::PAUSE;
			return;
		}
	}

	// collison with the racket
	if ((ball->coordinate.pos_x > (-10 - ball->size)) &&
		(ball->coordinate.pos_y < (racket->coordinate.pos_y + racket->size)) &&
		(ball->coordinate.pos_y > (racket->coordinate.pos_y - racket->size)) &&
		(ball->coordinate.pos_z < (racket->coordinate.pos_z + racket->size)) &&
		ball->coordinate.pos_z > (racket->coordinate.pos_z - racket->size))
	{

		// max speed of the ball
		float maxSpeed = 0.2;

		// change the direction of the ball
		ball->speed.x = -fabs(ball->speed.x);

		ball->speed.y = ((ball->coordinate.pos_y - racket->coordinate.pos_y) / racket->size) / 5;
		ball->speed.z = ((ball->coordinate.pos_z - racket->coordinate.pos_z) / racket->size) / 5;

		// normalize the speed
		double norm = sqrt(pow(ball->speed.x, 2) + pow(ball->speed.y, 2) + pow(ball->speed.z, 2));

		ball->speed.x = (ball->speed.x / norm) * maxSpeed;
		ball->speed.y = (ball->speed.y / norm) * maxSpeed;
		ball->speed.z = (ball->speed.z / norm) * maxSpeed;

		return;
	}

	// collision with the start of the corridor (out of the game, game over), (-5 is ball behind the racket)
	if (ball->coordinate.pos_x > (-5 - ball->size))
	{
		if (lifeCount->current > 0)
		{
			ball->isSticky = true;
			lifeCount->current--;
			return;
		}
		else
		{
			*status = GameStatus::GAME_OVER;
			return;
		}
	}
}

void moveBall(Ball *ball, Racket *racket, std::vector<Obstacle *> *obstactes, GameStatus *status, Life *lifeCount)
{
	// todo: isSticky ?
	if (ball->isSticky)
		return;

	handleCollision(ball, racket, obstactes, status, lifeCount);

	ball->coordinate.pos_x += ball->speed.x;
	ball->coordinate.pos_y += ball->speed.y;
	ball->coordinate.pos_z += ball->speed.z;
}

void moveBallOnKey(Ball *ball)
{
	if (ball->isSticky)
		return;

	// TODO: handle collision (un oubli oups)
	ball->coordinate.pos_x += std::abs(ball->speed.x);
}