#pragma once

#include <GL/glu.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "3D_tools.h"

// Structure pour la gestion de la couleur
typedef struct Color
{
    GLfloat r, g, b, a;
} Color;

typedef struct Coordinate
{
    GLfloat pos_x, pos_y, pos_z;
} Coordinate;

// Structure pour les murs
typedef struct Wall
{
    Color color;
    Coordinate coordinate;
    GLfloat width, height, depth;
} Wall;

void drawWalls(Color color);
void drawScene();