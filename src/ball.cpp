#include "ball.h"

void drawBall(Ball *ball)
{
	glPushMatrix();
	glTranslatef(ball->coordinate.pos_x, ball->coordinate.pos_y, ball->coordinate.pos_z);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	drawSphere(ball->size);
	glPopMatrix();
}
void moveBall(Ball *ball)
{

	// todo: isSticky ?

	if (ball->coordinate.pos_x < (-50 + ball->size) || ball->coordinate.pos_x > (-10 - ball->size))
	{
		ball->speed = -ball->speed;
	}
	ball->coordinate.pos_x -= ball->speed;
}