#include "racket.h"

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
	int const fov = 60;

	float pos_y = (((cursor->x * 2 / WINDOW_WIDTH) - 1) * WINDOW_WIDTH / WINDOW_HEIGHT) * tan(((fov * M_PI) / 180) / 2) * CAMERA_ZOOM;
	float pos_z = (-((cursor->y * 2 / WINDOW_HEIGHT) - 1)) * tan(((fov * M_PI) / 180) / 2) * CAMERA_ZOOM;

	// todo: use the size of the corridor (to be defined in "game")
	if (pos_y < (10 - racket->size))
	{
		if (pos_y > (-10 + racket->size))
		{
			racket->coordinate.pos_y = pos_y;
		}
		else
		{
			racket->coordinate.pos_y = -10 + racket->size;
		}
	}
	else
	{
		racket->coordinate.pos_y = 10 - racket->size;
	}

	if (pos_z < (5.5 - racket->size))
	{
		if (pos_z > (-4.5 + racket->size))
		{

			racket->coordinate.pos_z = pos_z;
		}
		else
		{
			racket->coordinate.pos_z = -4.5 + racket->size;
		}
	}
	else
	{
		racket->coordinate.pos_z = 5.5 - racket->size;
	}
}