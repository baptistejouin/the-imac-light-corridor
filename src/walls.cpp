#include "walls.h"

static const unsigned int aspectRatio = 1280 / 720;

void drawWall(Color color)
{
	glPushMatrix();

	glTranslatef(0.0, 0.0, -0.5);

	glPushMatrix();
	glColor4f(color.r, color.b, color.b, color.a);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(1.0f, 4.0f * aspectRatio, 1.0f);
	drawSquare();
	glPopMatrix();

	glPushMatrix();
	glColor4f(color.r, color.b, color.b, color.a);
	glScalef(1.0f, 4.0f * aspectRatio, 1.0f);
	glTranslatef(0.0, 0.0, 1);
	drawSquare();
	glPopMatrix();

	glPushMatrix();
	glColor4f(color.r - 0.1, color.b - 0.1, color.b - 0.1, color.a);
	glRotatef(90, 1.0, 0.0, 0.0);
	glScalef(1.0f, 1.0f, 1.0f);
	glTranslatef(0, 0.5, 2);
	drawSquare();
	glPopMatrix();

	glPushMatrix();
	glColor4f(color.r - 0.1, color.b - 0.1, color.b - 0.1, color.a);
	glRotatef(90, 1.0, 0.0, 0.0);
	glScalef(1.0f, 1.0f, 1.0f);
	glTranslatef(0, 0.5, -2);
	drawSquare();
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
		glTranslatef(-1, 0, 0);
		wallColor.b += 0.1;
		drawWall(wallColor);
	}

	glPopMatrix();
}

void drawLine()
{
	Color lineColor = {1.0f, 1.0f, 1.0f, 1.0f};

	glPushMatrix();

	glTranslatef(0.0, 0.0, -0.5);

	glPushMatrix();
	glColor4f(lineColor.r, lineColor.b, lineColor.b, lineColor.a);
	glTranslatef(0.5, 0.0, 0.5);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(1.0f, 4.0f * aspectRatio, 1.0f);
	drawSquare(false);
	glPopMatrix();

	glPopMatrix();
}

void drawLines()
{
	glPushMatrix();

	drawLine();

	for (size_t i = 0; i < 4; i++)
	{
		glTranslatef(-1, 0, 0);
		drawLine();
	}

	glPopMatrix();
}