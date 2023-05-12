#include "draw_scene.h"

void drawScene(Racket *racket)
{
    drawWalls();
    drawLines();
    drawRacket(racket);
}