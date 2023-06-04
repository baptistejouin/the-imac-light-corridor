#pragma once

#include <map>

#include "3D_tools.h"
#include "texture.h"
#include "game.h"

enum class GameStatus;
struct TextureLoaded;
struct TexturePosition;

void drawTitle(TextureLoaded *texture);
void drawPlayButton(TextureLoaded *texture);
void drawQuitButton(TextureLoaded *texture);
void drawMenu(GameStatus *status, std::map<const char *, TextureLoaded> *textures);
void drawGameOver(GameStatus *status, std::map<const char *, TextureLoaded> *textures);