#include "menu.h"

void drawTitle(TextureLoaded *texture)
{
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.75f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	drawSquare(true, 1.0f, texture);
	glPopMatrix();
}

void drawPlayButton(TextureLoaded *texture)
{
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(0.0f, -1.25f, -1.25f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	drawSquare(true, 0.35f, texture);
	glPopMatrix();
}

void drawQuitButton(TextureLoaded *texture)
{
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(0.0f, 1.25f, -1.25f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	drawSquare(true, 0.35f, texture);
	glPopMatrix();
}

void drawMenu(std::map<const char *, TextureLoaded> *textures)
{
	glPushMatrix();
	glTranslatef(-4.0f, 0.0f, 0.0f);

	drawTitle(&textures->at("logo"));
	drawPlayButton(&textures->at("play"));
	drawQuitButton(&textures->at("quit"));

	glPopMatrix();
}

void drawGameOver(std::map<const char *, TextureLoaded> *textures)
{
	glPushMatrix();
	glTranslatef(-4.0f, 0.0f, 0.0f);

	drawTitle(&textures->at("game_over"));
	drawPlayButton(&textures->at("retry"));
	drawQuitButton(&textures->at("quit"));

	glPopMatrix();
}

void drawPause(std::map<const char *, TextureLoaded> *textures)
{
	glPushMatrix();
	glTranslatef(-4.0f, 0.0f, -1.0f);

	glPushMatrix();

	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 0.0f, 0.5f);

	drawSquare(true, 10.0f);

	glPopMatrix();

	glScalef(0.5f, 0.5f, 0.5f);
	glTranslatef(0.5f, 0.0f, 1.0f);

	drawTitle(&textures->at("game_paused"));

	glPopMatrix();
}