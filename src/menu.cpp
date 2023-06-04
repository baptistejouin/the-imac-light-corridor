#include "menu.h"
#include <stdio.h>

void drawMenu(GameStatus *status)
{
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -5.0f);
	drawSquare(false, 1.0f);
	glPopMatrix();
}