#include "lives.h"

void drawCurrentHeart()
{
	glTexCoord2f(0.5f, 0.0f); // bottom right
	glVertex3f(-1.0f, 1.0f, 0.0f);

	glTexCoord2f(0.5f, 0.5f); // top right
	glVertex3f(1.0f, 1.0f, 0.0f);

	glTexCoord2f(0.0f, 0.5f); // top left
	glVertex3f(1.0f, -1.0f, 0.0f);

	glTexCoord2f(0.0f, 0.0f); // bottom left
	glVertex3f(-1.0f, -1.0f, 0.0f);
}

void drawLostHeart()
{
	glTexCoord2f(1.0f, 0.0f); // bottom right
	glVertex3f(-1.0f, 1.0f, 0.0f);

	glTexCoord2f(1.0f, 0.5f); // top right
	glVertex3f(1.0f, 1.0f, 0.0f);

	glTexCoord2f(0.5f, 0.5f); // top left
	glVertex3f(1.0f, -1.0f, 0.0f);

	glTexCoord2f(0.5f, 0.0f); // bottom left
	glVertex3f(-1.0f, -1.0f, 0.0f);
}

void drawLive(GLuint heartTexture, LifeStatus status)
{
	glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();

	glTranslatef(-5, -4.5, -2.25);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(0.4, 0.4, 0.4);

	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, heartTexture);

	glBegin(GL_QUADS);

	if (status == LifeStatus::CURRENT)
		drawCurrentHeart();
	else
		drawLostHeart();

	glEnd();

	glPopMatrix();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
}

void drawLifeCount(Life *lifeCount, GLuint heartTexture)
{
	float xOffset = 0.0f;

	for (int i = 0; i < lifeCount->current; i++)
	{
		glPushMatrix();
		glTranslatef(0, xOffset, 0.0);
		drawLive(heartTexture, LifeStatus::CURRENT);
		glPopMatrix();

		xOffset += 0.5;
	}
	for (int i = 0; i < lifeCount->max - lifeCount->current; i++)
	{
		glPushMatrix();
		glTranslatef(0, xOffset, 0.0);
		drawLive(heartTexture, LifeStatus::LOST);
		glPopMatrix();

		xOffset += 0.5;
	}
}