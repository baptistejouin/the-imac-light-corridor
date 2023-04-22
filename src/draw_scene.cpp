#include "draw_scene.h"

void draw_wall(Wall wall_right)
{
    glColor4f(wall_right.c.r, wall_right.c.g, wall_right.c.b, wall_right.c.a);

    glBegin(GL_QUADS);
    glVertex3f(wall_right.pos_x, wall_right.pos_y, wall_right.pos_z + wall_right.profondeur);
    glVertex3f(wall_right.pos_x + wall_right.largeur, wall_right.pos_y, wall_right.pos_z + wall_right.profondeur);
    glVertex3f(wall_right.pos_x + wall_right.largeur, wall_right.pos_y + wall_right.hauteur, wall_right.pos_z + wall_right.profondeur);
    glVertex3f(wall_right.pos_x, wall_right.pos_y + wall_right.hauteur, wall_right.pos_z + wall_right.profondeur);
    glEnd();
}

void drawScene()
{
    Wall wall_ceilling = {0.0f, 1.0f, 1.0f, 0.0f, 0.0f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f};
    Wall wall_floor = {0.0f, 1.0f, 1.0f, 0.0f, 0.0f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f};
    draw_wall(wall_ceilling);
    draw_wall(wall_floor);
}