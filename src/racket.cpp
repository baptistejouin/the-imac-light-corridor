#include "racket.h"
#include <iostream>

void drawRacket(Racket *racket)
{
	Color lineColor = {1.0f, 1.0f, 1.0f, 1.0f};

	glPushMatrix();

	glTranslatef(racket->coordinate.pos_x, racket->coordinate.pos_y, racket->coordinate.pos_z);

	glTranslatef(-10.0, 0.0, 0);

	glRotatef(90, 0.0, 1.0, 0.0);

	glPushMatrix();

	glColor4f(lineColor.r, lineColor.b, lineColor.b, lineColor.a);

	drawSquare(false, racket->size);

	glPopMatrix();

	glPopMatrix();
}

void moveRacket(Racket *racket, Cursor *cursor)
{
	int const width = 1280;
	int const height = 720;
	int const fov = 60;

	// 10 for the translate ratio
	float pos_y = (((cursor->x * 2 / width) - 1) * width / height) * tan(((fov * M_PI) / 180) / 2) * 10;
	float pos_z = (-((cursor->y * 2 / height) - 1)) * tan(((fov * M_PI) / 180) / 2) * 10;

	// std::cout << "pos_y" << pos_y << std::endl;
	// std::cout << "pos_z" << pos_z << std::endl;

	// récup les coordinées du rectangle au premier plan, puis vérifier si la raket sort du rectangle, si oui, on bloque la raket
	// if (pos_z > 0.37 || pos_z < -0.37)
	// {
	// 	pos_z = racket->coordinate.pos_z;
	// }
	// if (pos_y > 0.37 || pos_y < -0.37)
	// {
	// 	pos_y = racket->coordinate.pos_y;
	// }
	racket->coordinate.pos_y = pos_y;
	racket->coordinate.pos_z = pos_z;
}