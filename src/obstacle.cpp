#include "obstacle.h"

void drawObstacle(Obstacle *obstacle)
{
	Color lineColor = {1.0f, 0.0f, 1.0f, 1.0f};

	glPushMatrix();

	glTranslatef(obstacle->coordinate.pos_x, obstacle->coordinate.pos_y, obstacle->coordinate.pos_z);

	glTranslatef(-10.0, 0, 0.5);

	glRotatef(90, 0.0, 1.0, 0.0);

	glPushMatrix();

	glColor4f(lineColor.r, lineColor.b, lineColor.b, lineColor.a);

	drawSquare(true, obstacle->size);

	glPopMatrix();

	glPopMatrix();
}

void drawObstacles(std::vector<Obstacle *> *obstacles)
{
	for (int i = 0; i < obstacles->size(); i++)
	{
		drawObstacle(obstacles->at(i));
	}
};

void addObstacle(std::vector<Obstacle *> *obstacles, int i)
{
	Obstacle *obstacle = new Obstacle;

	// todo: use the size of the corridor (to be defined in "game")
	// the obstacle is on the back of the corridor
	obstacle->coordinate.pos_x = -40.0f;

	obstacle->coordinate.pos_z = 0;

	// random size between 2 and 3
	obstacle->size = (rand() % 3) + 1;

	obstacle->coordinate.pos_y = 10 - obstacle->size;

	printf("obstacle %d x position: %f\n", i, obstacle->coordinate.pos_x);
	printf("obstacle %d z position: %f\n", i, obstacle->coordinate.pos_z);
	printf("obstacle %d y position: %f\n", i, obstacle->coordinate.pos_y);
	printf("obstacle %d size: %f\n", i, obstacle->size);

	obstacles->push_back(obstacle);
}

void moveObstacles(std::vector<Obstacle *> *obstacles)
{
	for (int i = 0; i < obstacles->size(); i++)
	{
		Obstacle *current = obstacles->at(i);

		// todo: use the size of the corridor (to be defined in "game")
		if (current->coordinate.pos_x > 0)
		{
			current->coordinate.pos_x = -40.0f;
		}

		current->coordinate.pos_x += current->speed;
	}
}