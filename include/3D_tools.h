#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>
#include <math.h>

#define NB_SEG_CIRCLE 64

typedef struct Color
{
	GLfloat r, g, b, a;
} Color;

typedef struct Cursor
{
	double x, y;
} Cursor;

typedef struct Coordinate
{
	GLfloat pos_x, pos_y, pos_z;
} Coordinate;

/* Camera parameters and functions */
static const float Z_NEAR = 0.1f;
static const float Z_FAR = 100.f;

extern float cam_x;
extern float cam_y;
extern float cam_z;

void setCamera();

/* Draw cannonic objet functions */
void drawSquare(bool const filled = true, float const size = 0.5f);

void drawCircle();

void drawSphere();

/* Small tools */
float toRad(float deg);
