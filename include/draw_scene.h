#pragma once

#include <vector>

#include "walls.h"
#include "ball.h"
#include "racket.h"
#include "obstacle.h"

void drawScene(Racket *racket, Ball *ball, std::vector<Obstacle *> *obstacles);