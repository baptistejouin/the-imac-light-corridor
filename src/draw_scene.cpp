#include "draw_scene.h"

static const unsigned int aspectRatio = 1280 / 720;

void drawWalls()
{
    glPushMatrix();

    glTranslatef(0.0, 0.0, -0.5);

    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(2.0f, 4.0f * aspectRatio, 1.0f);
    drawSquare();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 1, 0);
    glScalef(2.0f, 4.0f * aspectRatio, 1.0f);
    glTranslatef(0.0, 0.0, 1);
    drawSquare();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 1);
    glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(2.0f, 1.0f, 1.0f);
    glTranslatef(0, 0.5, 2);
    drawSquare();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 1, 1);
    glRotatef(90, 1.0, 0.0, 0.0);
    glScalef(2.0f, 1.0f, 1.0f);
    glTranslatef(0, 0.5, -2);
    drawSquare();
    glPopMatrix();

    glPopMatrix();
}

void drawScene()
{
    drawWalls();
}