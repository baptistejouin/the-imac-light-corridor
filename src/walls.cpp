#include "walls.h"

void drawWall(Color color)
{
	glPushMatrix();

	glTranslatef(-15.0, 0.0, 5.5);

	// mur du bas
	glPushMatrix();
	glColor4f(color.r, color.b, color.b, color.a);
	glScalef(1.0f, 2.0f, 1.0f);
	drawSquare(true, 5.0f);
	glPopMatrix();

	// mur du haut
	glPushMatrix();
	glTranslatef(0.0, 0.0, -10.0);
	glColor4f(color.r, color.b, color.b, color.a);
	glScalef(1.0f, 2.0f, 1.0f);
	drawSquare(true, 5.0f);
	glPopMatrix();

	// mur de gauche
	glPushMatrix();
	glColor4f(color.r - 0.1, color.b - 0.1, color.b - 0.1, color.a);
	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(0, -5.0f, 10.0f);
	drawSquare(true, 5.0f);
	glPopMatrix();

	// mur de droite
	glPushMatrix();
	glColor4f(color.r - 0.1, color.b - 0.1, color.b - 0.1, color.a);
	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(0, -5.0f, -10.0f);
	drawSquare(true, 5.0f);
	glPopMatrix();

	glPopMatrix();
}

void drawWalls()
{
	Color wallColor = {0.06f, 0.08f, 0.4f, 1.0f};

	glPushMatrix();

	drawWall(wallColor);

	for (size_t i = 0; i < 3; i++)
	{
		glTranslatef(-10.0, 0, 0);
		wallColor.b += 0.1;
		drawWall(wallColor);
	}

	glPopMatrix();
}

void drawLine()
{
	Color lineColor = {1.0f, 1.0f, 1.0f, 1.0f};

	glPushMatrix();

	glTranslatef(-15.0, 0.0, -4.5);

	glPushMatrix();
	glColor4f(lineColor.r, lineColor.b, lineColor.b, lineColor.a);
	glTranslatef(5.0, 0.0, 5.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(.99f, 1.99f, .99f);
	drawSquare(false, 5.0f);
	glPopMatrix();

	glPopMatrix();
}

void drawLines()
{
	glPushMatrix();

	drawLine();

	for (size_t i = 0; i < 4; i++)
	{
		glTranslatef(-10.0f, 0, 0);
		drawLine();
	}

	glPopMatrix();
}