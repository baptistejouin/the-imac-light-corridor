#include <iostream>

#include "ball.h"

float speed_x = .1;

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

	if (ball->coordinate.pos_x < -30)
	{
		speed_x *= -1;
	}

	ball->coordinate.pos_x -= speed_x;
	std::cout << "pos_x" << ball->coordinate.pos_x << std::endl;

	if (ball->coordinate.pos_x > -15)
	{
		speed_x *= -1;
	}
}