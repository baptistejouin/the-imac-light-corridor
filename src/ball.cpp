#include "ball.h"
#include <iostream>

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
	float speed_x = .1;

	// todo: isSticky ?

	if (ball->coordinate.pos_x < -30 || ball->coordinate.pos_x > -15)
	{
		speed_x = -speed_x;
	}

	ball->coordinate.pos_x -= speed_x;

	std::cout << "ball x position: " << ball->coordinate.pos_x << std::endl;
}