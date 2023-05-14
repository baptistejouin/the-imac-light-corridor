#pragma once

#include <vector>

#include "corridor.h"
#include "ball.h"
#include "racket.h"
#include "obstacle.h"

void drawScene(Racket *racket, Ball *ball, std::vector<Obstacle *> *obstacles);