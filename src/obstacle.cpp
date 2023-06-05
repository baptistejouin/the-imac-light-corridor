#include "obstacle.h"

static Color defaultColor = {0.36f, 0.38f, 0.7f, 1.0f};

void updateObstacleColor(Obstacle *obstacle)
{
	// obstacle color is darken when it is near -40.0 and lighter when it is near 0.0
	obstacle->color.b = defaultColor.b + (obstacle->coordinate.pos_x / 80.0);
	obstacle->color.r = defaultColor.r + (obstacle->coordinate.pos_x / 80.0);
	obstacle->color.g = defaultColor.g + (obstacle->coordinate.pos_x / 80.0);

	// add transparency when obstacle is between -3 and 0, near to zero is more transparent
	if (obstacle->coordinate.pos_x > -3.0)
		obstacle->color.a = 0.3f + (obstacle->coordinate.pos_x / -3.0);
	else
		obstacle->color.a = 1.0f;
}
void drawObstacle(Obstacle *obstacle)
{
	glPushMatrix();

	glTranslatef(obstacle->coordinate.pos_x, obstacle->coordinate.pos_y, obstacle->coordinate.pos_z);

	glTranslatef(-10.0, 0.0, 0.0);

	glRotatef(90, 0.0, 1.0, 0.0);

	glPushMatrix();

	glColor4f(obstacle->color.r, obstacle->color.g, obstacle->color.b, obstacle->color.a);

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
	obstacle->width = fmax(static_cast<float>(rand() % (10 + 1)), 1.5);

	if (obstacle->width > (10 - racket->size))
	{
		// if width > 10.0 - racket size, then generate a height between 1.0 and (3 - racket->size)
		obstacle->height = fmax(static_cast<float>(rand() % ((5 - static_cast<int>(racket->size)) + 1)), 1.5);
	}
	else
	{
		// otherwise generate a height between 1.0 and 5.0
		obstacle->height = fmax(static_cast<float>(rand() % (5 + 1)), 1.5);
	}

	if (rand() % 2 == 0)
		obstacle->coordinate.pos_y = -10 + obstacle->width;
	else
		obstacle->coordinate.pos_y = -(-10 + obstacle->width);

	if (rand() % 2 == 0)
		obstacle->coordinate.pos_z = -4.5 + obstacle->height;
	else
		obstacle->coordinate.pos_z = 1 - (-4.5 + obstacle->height);
}

void addObstacle(std::vector<Obstacle *> *obstacles, int i, Racket *racket)
{
	Obstacle *obstacle = new Obstacle;

	// todo: use the size of the corridor (to be defined in "game")
	// the obstacle is on the back of the corridor
	obstacle->coordinate.pos_x = -40.0f + i * 20.0;
	obstacle->coordinate.pos_z = 0;

	obstacle->color = defaultColor;

	obstacle->id = i;

	randomizeObstacle(obstacle, racket);

	updateObstacleColor(obstacle);

	obstacles->push_back(obstacle);
}

void moveObstacles(std::vector<Obstacle *> *obstacles, Racket *racket, float movingSpeed)
{
	for (int i = 0; i < obstacles->size(); i++)
	{
		Obstacle *obstacle = obstacles->at(i);

		// todo: use the size of the corridor (to be defined in "game")
		if (obstacle->coordinate.pos_x > 0)
		{
			obstacle->coordinate.pos_x = -40.0f;
			randomizeObstacle(obstacle, racket);
		}

		obstacle->coordinate.pos_x += movingSpeed;

		updateObstacleColor(obstacle);
	}
}

bool isCollidingWithRacket(std::vector<Obstacle *> *obstacles, Racket *racket)
{
	for (int i = 0; i < obstacles->size(); i++)
	{
		Obstacle *obstacle = obstacles->at(i);

		if (obstacle->coordinate.pos_x < 0)
			continue;

		if (racket->coordinate.pos_y + racket->size > obstacle->coordinate.pos_y - obstacle->width &&
			racket->coordinate.pos_y - racket->size < obstacle->coordinate.pos_y + obstacle->width &&
			racket->coordinate.pos_z + racket->size > obstacle->coordinate.pos_z - obstacle->height &&
			racket->coordinate.pos_z - racket->size < obstacle->coordinate.pos_z + obstacle->height)
			return true;
	}

	return false;
}