#include "draw_scene.h"

void drawScene(Racket *racket, Ball *ball)
{
    drawWalls();
    drawLines();
    drawRacket(racket);
    drawBall(ball);
}