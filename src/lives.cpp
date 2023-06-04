#include "lives.h"

void drawCurrentHeart(GLuint texture)
{
	TexturePosition texPos = {
		{0.0f, 0.0f},
		{0.0f, 0.5f},
		{0.5f, 0.0f},
		{0.5f, 0.5f},
	};
	drawSquare(true, 1.0f, texture, &texPos);
};

void drawLostHeart(GLuint texture)
{
	TexturePosition TexPos = {
		{0.5f, 0.0f},
		{0.5f, 0.5f},
		{1.0f, 0.0f},
		{1.0f, 0.5f},
	};
	drawSquare(true, 1.0f, texture, &TexPos);
}

void drawLive(GLuint heartTexture, LifeStatus status)
{
	glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();

	glTranslatef(-5, -4.5, -2.25);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(0.4, 0.4, 0.4);

	glPushMatrix();

	if (status == LifeStatus::CURRENT)
		drawCurrentHeart(heartTexture);
	else
		drawLostHeart(heartTexture);

	glPopMatrix();
	glPopMatrix();
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