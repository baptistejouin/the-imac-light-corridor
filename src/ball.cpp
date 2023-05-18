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
void handleCollision(Ball *ball, Racket *racket)
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

	// collison with the racket
	if (ball->coordinate.pos_x > (-10 - ball->size) &&
		ball->coordinate.pos_y < racket->coordinate.pos_y + racket->size &&
		ball->coordinate.pos_y > racket->coordinate.pos_y - racket->size &&
		ball->coordinate.pos_z < racket->coordinate.pos_z + racket->size &&
		ball->coordinate.pos_z > racket->coordinate.pos_z - racket->size)
	{
		ball->coordinate.pos_x = -10 - ball->size;

		ball->speed.x = -ball->speed.x;
		ball->speed.y = std::clamp((ball->coordinate.pos_y - racket->coordinate.pos_y) / racket->size, -0.1f, 0.1f);
		ball->speed.z = std::clamp((ball->coordinate.pos_z - racket->coordinate.pos_z) / racket->size, -0.1f, 0.1f);
		return;
	}

	// collision with the start of the corridor (out of the game, game over)
	if (ball->coordinate.pos_x > (-5 - ball->size))
	{
		// todo: handle lives count

		// todo: delete when lives are implemented
		ball->isSticky = true;
		ball->color.r = 1.0f;
		ball->color.g = 0.0f;
		ball->color.b = 0.0f;
		return;
	}
}

void moveBall(Ball *ball, Racket *racket)
{
	// todo: isSticky ?
	if (ball->isSticky)
		return;

	handleCollision(ball, racket);

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