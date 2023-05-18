#include "ball.h"

void drawBall(Ball *ball)
{
	glPushMatrix();
	glTranslatef(ball->coordinate.pos_x, ball->coordinate.pos_y, ball->coordinate.pos_z);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	drawSphere(ball->size, ball->color);
	glPopMatrix();
}

// todo: to improve
void handleCollision(Ball *ball, Racket *racket, std::vector<Obstacle *> *obstacles, GameStatus *status)
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

		// check x axis for coolision between ball and obstacle we accept a margin of 0.1 of error
		if (ball->coordinate.pos_x - 0.1 < obstacle->coordinate.pos_x && ball->coordinate.pos_x + 0.1 > obstacle->coordinate.pos_x)
		{
			printf("collision x\n");
			// check y and z axis, we use obstacle->width / obstacle->height to get the size of the obstacle
			if (ball->coordinate.pos_y < obstacle->coordinate.pos_y + obstacle->width / 2 &&
				ball->coordinate.pos_y > obstacle->coordinate.pos_y - obstacle->width / 2 &&
				ball->coordinate.pos_z < obstacle->coordinate.pos_z + obstacle->height / 2 &&
				ball->coordinate.pos_z > obstacle->coordinate.pos_z - obstacle->height / 2)
			{
				printf("collision z\n");
				*status = GameStatus::PAUSE;
			}
		}
	}

	// collison with the racket
	if (ball->coordinate.pos_x > (-10 - ball->size) &&
		ball->coordinate.pos_y < racket->coordinate.pos_y + racket->size &&
		ball->coordinate.pos_y > racket->coordinate.pos_y - racket->size &&
		ball->coordinate.pos_z < racket->coordinate.pos_z + racket->size &&
		ball->coordinate.pos_z > racket->coordinate.pos_z - racket->size)
	{
		ball->coordinate.pos_x = -10 - ball->size;

		// max speed of the ball
		float maxSpeed = ball->speed.x;

		// change the direction of the ball
		ball->speed.x = -ball->speed.x;
		ball->speed.y = std::clamp((ball->coordinate.pos_y - racket->coordinate.pos_y) / racket->size, -0.1f, 0.1f);
		ball->speed.z = std::clamp((ball->coordinate.pos_z - racket->coordinate.pos_z) / racket->size, -0.1f, 0.1f);

		// normalize the speed
		float norm = sqrt(ball->speed.x * ball->speed.x + ball->speed.y * ball->speed.y + ball->speed.z * ball->speed.z);

		if (norm > maxSpeed)
		{
			ball->speed.x = (ball->speed.x / norm) * maxSpeed;
			ball->speed.y = (ball->speed.y / norm) * maxSpeed;
			ball->speed.z = (ball->speed.z / norm) * maxSpeed;
		}
		return;
	}

	// collision with the start of the corridor (out of the game, game over)
	if (ball->coordinate.pos_x > (-5 - ball->size))
	{
		// todo: handle lives count

		// todo: delete when lives are implemented
		ball->isSticky = true;
		*status = GameStatus::GAME_OVER;
		return;
	}
}

void moveBall(Ball *ball, Racket *racket, std::vector<Obstacle *> *obstactes, GameStatus *status)
{
	// todo: isSticky ?
	if (ball->isSticky)
		return;

	handleCollision(ball, racket, obstactes, status);

	ball->coordinate.pos_x += ball->speed.x;
	ball->coordinate.pos_y += ball->speed.y;
	ball->coordinate.pos_z += ball->speed.z;
}

void moveBallOnKey(Ball *ball)
{
	// todo: isSticky ?
	if (ball->isSticky)
		return;

	ball->coordinate.pos_x += std::abs(ball->speed.x);
}