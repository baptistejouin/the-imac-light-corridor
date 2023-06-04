#pragma once

#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>

#include <stb_image.h>

#define NB_SEG_CIRCLE 64

struct TexturePosition;

extern unsigned int WINDOW_WIDTH;
extern unsigned int WINDOW_HEIGHT;
extern unsigned int CAMERA_ZOOM;
extern float FOV;

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

typedef struct Speed
{
	GLfloat x, y, z;
} Speed;

typedef struct TexturePosition
{
	Coordinate topLeft;
	Coordinate topRight;
	Coordinate bottomLeft;
	Coordinate bottomRight;
} TexturePosition;

/* Camera parameters and functions */
static const float Z_NEAR = 0.1f;
static const float Z_FAR = 100.f;

extern float cam_x;
extern float cam_y;
extern float cam_z;

void setCamera();

/* Draw cannonic objet functions */
void drawSquare(bool const filled = true, float const size = 1.0f, GLuint textureID = 0, TexturePosition *texturePosition = nullptr);

void drawCircle();
void drawSphere(float const size, Color color);

/* Small tools */
float toRad(float deg);