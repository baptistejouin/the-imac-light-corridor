#include "racket.h"

void drawRacket(Racket *racket)
{
	Color lineColor = {1.0f, 1.0f, 1.0f, 1.0f};

	glPushMatrix();

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

void moveRacket(Racket *racket) {}