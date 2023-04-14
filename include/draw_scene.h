#pragma once

// #include <GL/gl.h>
// #include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Structure pour la gestion de la couleur
typedef struct Color
{
    GLfloat r, g, b, a;
} Color;

// Structure pour les murs
typedef struct Wall
{
    Color c;
    float pos_x, pos_y, pos_z;
    float largeur, hauteur;
} Wall;

void render_wall_right(Wall wall);