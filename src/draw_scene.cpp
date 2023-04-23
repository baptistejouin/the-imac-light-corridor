#include "draw_scene.h"

static const unsigned int aspectRatio = 1280 / 720;

void drawWalls(Color color)
{
    glPushMatrix();

    glTranslatef(0.0, 0.0, -0.5);

    glPushMatrix();
    glColor4f(color.r, color.b, color.b, color.a);
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(1.0f, 4.0f * aspectRatio, 1.0f);
    drawSquare();
    glPopMatrix();

    glPushMatrix();
    glColor4f(color.r, color.b, color.b, color.a);
    glScalef(1.0f, 4.0f * aspectRatio, 1.0f);
    glTranslatef(0.0, 0.0, 1);
    drawSquare();
    glPopMatrix();

    glPushMatrix();
    glColor4f(color.r + 0.1, color.b + 0.1, color.b + 0.1, color.a);
    glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(1.0f, 1.0f, 1.0f);
    glTranslatef(0, 0.5, 2);
    drawSquare();
    glPopMatrix();

    glPushMatrix();
    glColor4f(color.r + 0.1, color.b + 0.1, color.b + 0.1, color.a);
    glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(1.0f, 1.0f, 1.0f);
    glTranslatef(0, 0.5, -2);
    drawSquare();
    glPopMatrix();

    glPopMatrix();
}

void drawScene()
{
    glPushMatrix();
    drawWalls({0.0f, 0.0f, 0.6f, 1.0f});

    glTranslatef(-1, 0, 0);
    drawWalls({0.0f, 0.0f, 0.7f, 1.0f});

    glTranslatef(-1, 0, 0);
    drawWalls({0.0f, 0.0f, 0.8f, 1.0f});

    glPopMatrix();
}