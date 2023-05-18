#include "obstacle.h"

void drawObstacle(Obstacle *obstacle)
{
	Color obstacleColor = {0.5f, 0.8f, 0.0f, 1.0f};

	glPushMatrix();

	glTranslatef(obstacle->coordinate.pos_x, obstacle->coordinate.pos_y, obstacle->coordinate.pos_z);

	glTranslatef(-10.0, 0.0, 0.0);

	glRotatef(90, 0.0, 1.0, 0.0);

	glPushMatrix();

	glColor4f(obstacleColor.r, obstacleColor.g, obstacleColor.b, obstacleColor.a);

	glScalef(obstacle->height, obstacle->width, 1.0f);

	drawSquare(true, 1.0f);

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

void randomizeObstacle(Obstacle *obstacle, Racket *racket)
{
	// generate a random width size between 1.0 and 10.0
	obstacle->width = static_cast<float>(rand() % (10 + 1));

	if (obstacle->width > (10 - racket->size))
	{
		// if width > 10.0 - racket size, then generate a height between 1.0 and (3 - racket->size)
		obstacle->height = static_cast<float>(rand() % ((5 - static_cast<int>(racket->size)) + 1));
	}
	else
	{
		// otherwise generate a height between 1.0 and 5.0
		obstacle->height = static_cast<float>(rand() % (5 + 1));
	}

	obstacle->coordinate.pos_y = -10 + obstacle->width;
	obstacle->coordinate.pos_z = -4.5 + obstacle->height;
}

void addObstacle(std::vector<Obstacle *> *obstacles, int i, Racket *racket)
{
	Obstacle *obstacle = new Obstacle;

	// todo: use the size of the corridor (to be defined in "game")
	// the obstacle is on the back of the corridor
	obstacle->coordinate.pos_x = -40.0f + i * 20.0;

	obstacle->coordinate.pos_z = 0;

	randomizeObstacle(obstacle, racket);

	obstacle->speed.x = 0.2f;

	printf("obstacle %d x position: %f\n", i, obstacle->coordinate.pos_x);
	printf("obstacle %d z position: %f\n", i, obstacle->coordinate.pos_z);
	printf("obstacle %d y position: %f\n", i, obstacle->coordinate.pos_y);
	printf("obstacle %d width: %f\n", i, obstacle->width);
	printf("obstacle %d height: %f\n", i, obstacle->height);

	obstacles->push_back(obstacle);
}

void moveObstacles(std::vector<Obstacle *> *obstacles, Racket *racket)
{
	for (int i = 0; i < obstacles->size(); i++)
	{
		Obstacle *current = obstacles->at(i);

		// todo: use the size of the corridor (to be defined in "game")
		if (current->coordinate.pos_x > 0)
		{
			current->coordinate.pos_x = -40.0f;
			randomizeObstacle(current, racket);
		}

		current->coordinate.pos_x += current->speed.x;
	}
}