#include "draw_scene.h"

void drawScene(Racket *racket, Ball *ball, std::vector<Obstacle *> *obstacles)
{
    drawWalls();
    drawLines();
    drawRacket(racket);
    drawBall(ball);
    drawObstacles(obstacles);
}