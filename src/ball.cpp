#include "ball.h"
#include "3D_tools.h"
#include <cmath>


struct Ball ball;

double pos_cur_x, pos_cur_y; // Position du curseur de la souris

void drawBall()
{
    if (ball.pos_x <= 0)
    {
        glPushMatrix();
            glColor3f(1 + ball.pos_z/10, 0, 0);
            glTranslatef((ball.pos_x-640)/720, (-ball.pos_x+360)/720, ball.pos_z);
            glScalef(0.075, 0.075, 0.075);
            drawSphere();
        glPopMatrix();
    }
}

void moveBall()
{
    if (ball.isSticky)
    {
        ball.pos_x = pos_cur_x;
        ball.pos_y = pos_cur_y;
        ball.pos_z = -2;
    }

    else
    {
        ball.pos_x = ball.pos_x + ball.speed_x;
        ball.pos_y = ball.pos_y + ball.speed_y;
        ball.pos_z = ball.pos_z + ball.speed_z; // Si obstable que faire ?
    }
}

void collision_walls()
{
    if (ball.pos_x-1 <= 0 || ball.pos_x+1 >= 1280)
    {
        ball.speed_x = - ball.speed_x;
        ball.pos_x = round(ball.pos_x/1280)*1280;
    }

        if (ball.pos_y-1 <= 0 || ball.pos_x+1 >= 720)
    {
        ball.speed_x = - ball.speed_x;
        ball.pos_x = round(ball.pos_x/720)*720;
    }
}

void collision_racket()
{
    if (ball.pos_z >= -2 && !(ball.isSticky))
    {
        ball.isSticky = 1;
        ball.speed_x = 0;
        ball.speed_y = 0;
        ball.speed_z = 0.5;
    }

    if (ball.pos_z >= -2 && !(ball.isSticky) && abs(pos_cur_x - ball.pos_x) <= 148 && abs(pos_cur_y - ball.pos_y) <= 148 ) // TODO, fonction valeur absolue ne fonctionne pas, rip
    {
        ball.speed_x = - pos_cur_x + ball.pos_x;
        ball.speed_y = - pos_cur_y + ball.pos_y;
        ball.speed_z = - ball.speed_z;
        ball.pos_z = -2;
    }
}