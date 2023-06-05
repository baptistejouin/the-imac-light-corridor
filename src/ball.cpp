#include "ball.h"

// max speed of the ball
static float maxSpeed = 0.2;

void drawBall(Ball *ball)
{
	glPushMatrix();
	glTranslatef(ball->coordinate.pos_x, ball->coordinate.pos_y, ball->coordinate.pos_z);
	glColor4f(ball->color.r, ball->color.g, ball->color.b, ball->color.a);
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

	// collision with the obstacles
	for (size_t i = 0; i < obstacles->size(); i++)
	{
		Obstacle *obstacle = obstacles->at(i);

		float ballX = ball->coordinate.pos_x + (10 - ball->size);
		float obstacleX = obstacle->coordinate.pos_x;

		float margin = 1.0;

		bool wasBallBehind = (ballX + ball->size <= obstacleX + margin);
		bool wasBallInFront = (ballX + ball->size >= obstacleX - margin);

		bool isCollisionX = wasBallBehind && wasBallInFront;

		bool isCollisionY = (ball->coordinate.pos_y - ball->size < obstacle->coordinate.pos_y + obstacle->width) &&
							(ball->coordinate.pos_y + ball->size > obstacle->coordinate.pos_y - obstacle->width);
		bool isCollisionZ = (ball->coordinate.pos_z - ball->size < obstacle->coordinate.pos_z + obstacle->height) &&
							(ball->coordinate.pos_z + ball->size > obstacle->coordinate.pos_z - obstacle->height);

		if (isCollisionX && isCollisionY && isCollisionZ)
		{
			// Check the velocity of the ball relative to the obstacle
			bool isBallBehind = ball->speed.x > 0;

			if (isBallBehind)
			{
				printf("Ball is behind\n");
				ball->speed.x = -fabs(ball->speed.x);
			}
			else
			{
				printf("Ball is in front\n");
				ball->speed.x = fabs(ball->speed.x);
			}

			return;
		}
	}

	// collison with the racket
	if ((ball->coordinate.pos_x > (-10 - ball->size)) &&
		(ball->coordinate.pos_y - ball->size < (racket->coordinate.pos_y + racket->size)) &&
		(ball->coordinate.pos_y + ball->size > (racket->coordinate.pos_y - racket->size)) &&
		(ball->coordinate.pos_z - ball->size < (racket->coordinate.pos_z + racket->size)) &&
		ball->coordinate.pos_z + ball->size > (racket->coordinate.pos_z - racket->size))
	{
		// change the direction of the ball
		ball->speed.x = -fabs(ball->speed.x);

		// weighting of speed according to the position of the ball on the racket
		int weighting = 6;

		ball->speed.y = ((ball->coordinate.pos_y - racket->coordinate.pos_y) / racket->size) / weighting;
		ball->speed.z = ((ball->coordinate.pos_z - racket->coordinate.pos_z) / racket->size) / weighting;

		// normalize the speed
		double norm = sqrt(pow(ball->speed.x, 2) + pow(ball->speed.y, 2) + pow(ball->speed.z, 2));

		ball->speed.x = (ball->speed.x / norm) * maxSpeed;
		ball->speed.y = (ball->speed.y / norm) * maxSpeed;
		ball->speed.z = (ball->speed.z / norm) * maxSpeed;

		return;
	}

	// collision with the start of the corridor (out of the game, game over)
	if (ball->coordinate.pos_x > (-10 - ball->size))
	{
		if (lifeCount->current > 1)
		{
			ball->isSticky = true;
			ball->speed.x = maxSpeed;
			ball->speed.y = 0;
			ball->speed.z = 0;
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
	if (ball->isSticky)
	{
		ball->coordinate.pos_x = racket->coordinate.pos_x - 10 - ball->size;
		ball->coordinate.pos_y = racket->coordinate.pos_y;
		ball->coordinate.pos_z = racket->coordinate.pos_z;
	}
	else
	{
		handleCollision(ball, racket, obstactes, status, lifeCount);

		ball->coordinate.pos_x += ball->speed.x;
		ball->coordinate.pos_y += ball->speed.y;
		ball->coordinate.pos_z += ball->speed.z;
	}
}

void moveBallOnKey(Ball *ball, float movingSpeed)
{
	if (ball->isSticky)
		return;

	ball->coordinate.pos_x += movingSpeed;
}