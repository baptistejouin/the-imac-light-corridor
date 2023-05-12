#include "racket.h"

void drawRacket(Racket *racket)
{
	Color lineColor = {1.0f, 1.0f, 1.0f, 1.0f};

	glPushMatrix();

	glTranslatef(racket->coordinate.pos_x, racket->coordinate.pos_y, racket->coordinate.pos_z);

	glTranslatef(.5, 0.0, 0);

	glRotatef(90, 0.0, 1.0, 0.0);

	glScalef(0.25, .5, .5);

	glPushMatrix();

	glBegin(GL_LINE_LOOP);

	glColor4f(lineColor.r, lineColor.b, lineColor.b, lineColor.a);

	drawSquare(false, racket->size);

	glEnd();

	glPopMatrix();

	glPopMatrix();
}

void moveRacket(Racket *racket, Cursor *cursor)
{
	racket->coordinate.pos_y = (((cursor->x * 2 / 1280) - 1) * 1280 / 720) * tan(((60 * M_PI) / 180) / 2);
	racket->coordinate.pos_z = (-((cursor->y * 2 / 720) - 1)) * tan(((60 * M_PI) / 180) / 2);
}