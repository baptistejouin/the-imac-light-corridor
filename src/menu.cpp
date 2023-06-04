#include "menu.h"

void drawTitle(TextureLoaded *texture)
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.75f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	drawSquare(true, 1.0f, texture);
	glPopMatrix();
}

void drawPlayButton(TextureLoaded *texture)
{
	glPushMatrix();
	glTranslatef(0.0f, -1.25f, -1.25f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	drawSquare(true, 0.35f, texture);
	glPopMatrix();
}

void drawQuitButton(TextureLoaded *texture)
{
	glPushMatrix();
	glTranslatef(0.0f, 1.25f, -1.25f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	drawSquare(true, 0.35f, texture);
	glPopMatrix();
}

void drawMenu(GameStatus *status, std::map<const char *, TextureLoaded> *textures)
{
	glPushMatrix();
	glTranslatef(-4.0f, 0.0f, 0.0f);

	drawTitle(&textures->at("logo"));
	drawPlayButton(&textures->at("play"));
	drawQuitButton(&textures->at("quit"));

	glPopMatrix();
}

void drawGameOver(GameStatus *status, std::map<const char *, TextureLoaded> *textures)
{
	glPushMatrix();
	glTranslatef(-4.0f, 0.0f, 0.0f);

	drawTitle(&textures->at("game_over"));
	drawPlayButton(&textures->at("retry"));
	drawQuitButton(&textures->at("quit"));

	glPopMatrix();
}