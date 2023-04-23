#include "walls.h"

static const unsigned int aspectRatio = 1280 / 720;

Color darkenColor(Color color, GLfloat amount)
{
	// Calculate the new color values
	GLfloat newR = color.r - amount;
	GLfloat newG = color.g - amount;
	GLfloat newB = color.b - amount;

	// Clamp the values to make sure they stay within the 0-1 range
	newR = std::max(newR, 0.0f);
	newG = std::max(newG, 0.0f);
	newB = std::max(newB, 0.0f);

	// Create a new Color struct with the new values
	Color newColor = {newR, newG, newB, color.a};
	return newColor;
}

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
	Color blueWall = {0.06f, 0.08f, 0.4f, 1.0f};

	glPushMatrix();

	drawWall(blueWall);

	for (size_t i = 0; i < 3; i++)
	{
		glTranslatef(-1, 0, 0);
		blueWall.b += 0.1;
		drawWall(blueWall);
	}

	glPopMatrix();
}