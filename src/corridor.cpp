#include "corridor.h"

static Color defaultColor = {0.36f, 0.38f, 0.7f, 1.0f};

void drawWall(Color color)
{
	glPushMatrix();

	glTranslatef(-15.0, 0.0, 5.5);

	// bottom wall
	glPushMatrix();
	glColor4f(color.r, color.g, color.b, color.a);
	glScalef(1.0f, 2.0f, 1.0f);
	drawSquare(true, 5.0f);
	glPopMatrix();

	// top wall
	glPushMatrix();
	glTranslatef(0.0, 0.0, -10.0);
	glColor4f(color.r, color.g, color.b, color.a);
	glScalef(1.0f, 2.0f, 1.0f);
	drawSquare(true, 5.0f);
	glPopMatrix();

	// left wall
	glPushMatrix();
	glColor4f(color.r - 0.1, color.g - 0.1, color.b - 0.1, color.a);
	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(0, -5.0f, 10.0f);
	drawSquare(true, 5.0f);
	glPopMatrix();

	// right wall
	glPushMatrix();
	glColor4f(color.r - 0.1, color.g - 0.1, color.b - 0.1, color.a);
	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(0, -5.0f, -10.0f);
	drawSquare(true, 5.0f);
	glPopMatrix();

	glPopMatrix();
}

void drawCorridor()
{
	Color colorOffset = {0.0f, 0.0f, 0.0f, 0.0f};

	glPushMatrix();

	drawWall(defaultColor);

	for (size_t i = 0; i < 3; i++)
	{
		glTranslatef(-10.0, 0, 0);

		colorOffset += {0.1f, 0.1f, 0.1f, 0.0f};

		drawWall(defaultColor - colorOffset);
	}

	glPopMatrix();
}

void drawLine(Line *line)
{
	glPushMatrix();

	glTranslatef(line->coordinate.pos_x, line->coordinate.pos_y, line->coordinate.pos_z);

	glTranslatef(-15.0, 0.0, -4.5);

	glPushMatrix();
	glColor4f(line->color.r, line->color.g, line->color.b, line->color.a);
	glTranslatef(5.0, 0.0, 5.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(.99f, 1.99f, .99f);
	drawSquare(false, 5.0f);
	glPopMatrix();

	glPopMatrix();
}

void addLine(std::vector<Line *> *lines, int i)
{
	Line *line = new Line;

	line->color.r = 1.0f;
	line->color.g = 1.0f;
	line->color.b = 1.0f;
	line->color.a = 1.0f;
	line->coordinate.pos_x = -(float)(i * 10);
	line->coordinate.pos_y = 0.0f;
	line->coordinate.pos_z = 0.0f;

	lines->push_back(line);
}

void drawLines(std::vector<Line *> *lines)
{
	glPushMatrix();

	for (size_t i = 0; i < lines->size(); i++)
	{
		drawLine(lines->at(i));
	}

	glPopMatrix();
}

void moveLines(std::vector<Line *> *lines, float movingSpeed)
{
	for (int i = 0; i < lines->size(); i++)
	{
		Line *current = lines->at(i);

		// todo: use the size of the corridor (to be defined in "game")
		if (current->coordinate.pos_x > 0)
		{
			current->coordinate.pos_x = -40.0f;
		}

		current->coordinate.pos_x += movingSpeed;
	}
}