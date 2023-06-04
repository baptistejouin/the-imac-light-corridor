#include "lives.h"

void drawCurrentHeart(TextureLoaded *texture)
{
	TexturePosition texPos = {
		{0.0f, 0.0f},
		{0.0f, 0.5f},
		{0.5f, 0.0f},
		{0.5f, 0.5f},
	};
	drawSquare(true, 1.0f, texture, &texPos);
};

void drawLostHeart(TextureLoaded *texture)
{
	TexturePosition TexPos = {
		{0.5f, 0.0f},
		{0.5f, 0.5f},
		{1.0f, 0.0f},
		{1.0f, 0.5f},
	};
	drawSquare(true, 1.0f, texture, &TexPos);
}

void drawLive(TextureLoaded *texture, LifeStatus status)
{
	glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();

	glTranslatef(-5, -4.5, -2.25);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(0.4, 0.4, 0.4);

	glPushMatrix();

	if (status == LifeStatus::CURRENT)
		drawCurrentHeart(texture);
	else if (status == LifeStatus::LOST)
		drawLostHeart(texture);

	glPopMatrix();
	glPopMatrix();
}

void drawLifeCount(Life *lifeCount, std::map<const char *, TextureLoaded> *textures)
{
	float xOffset = 0.0f;
	int temp = 0;

	for (int i = 0; i < lifeCount->max; i++)
	{

		glPushMatrix();
		glTranslatef(0, xOffset, 0.0);
		drawLive(&textures->at("heart"), temp >= lifeCount->current ? LifeStatus::LOST : LifeStatus::CURRENT);
		glPopMatrix();

		temp++;
		xOffset += 0.5;
	}
}