#include "draw_scene.h"

// Initialiser la couleur du mur
Wall wall_right = {0.0f, 1.0f, 1.0f, 1.0f, 100, 200, 300}; //TODO

// wall_right.c.r = 0.0f;
// wall_right.c.g = 0.0f;
// wall_right.c.b = 1.0f;
// wall_right.c.a = 1.0f;
// wall_right.pos = 100;     // Position du mur
// wall_right.largeur = 200; // Largeur du mur
// wall_right.hauteur = 300; // Hauteur du mur

void render_wall_right(Wall wall_right)
{
    // Définir la couleur de dessin en bleu
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f); //TODO 

    // Dessiner un rectangle pour représenter le mur
    glBegin(GL_QUADS);
    glVertex3f(wall_right.pos_x, wall_right.pos_y, wall_right.pos_z);
    glVertex3f(wall_right.pos_x + wall_right.largeur, wall_right.pos_y, wall_right.pos_z);
    glVertex3f(wall_right.pos_x + wall_right.largeur, wall_right.pos_y + wall_right.hauteur, wall_right.pos_z);
    glVertex3f(wall_right.pos_x, wall_right.pos_y + wall_right.hauteur, wall_right.pos_z);
    glEnd();
}