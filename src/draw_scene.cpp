#include "draw_scene.h"

void draw_wall(Wall wall_right)
{
    /* SOL */
    // Définir la couleur de dessin en bleu
    glColor4f(wall_right.c.r, wall_right.c.g, wall_right.c.b, wall_right.c.a);

    // Dessiner un rectangle pour représenter le sol
    glBegin(GL_QUADS);
    glVertex3f(wall_right.pos_x, wall_right.pos_y, wall_right.pos_z);
    glVertex3f(wall_right.pos_x + wall_right.largeur, wall_right.pos_y, wall_right.pos_z);
    glVertex3f(wall_right.pos_x + wall_right.largeur, wall_right.pos_y + wall_right.hauteur, wall_right.pos_z);
    glVertex3f(wall_right.pos_x, wall_right.pos_y + wall_right.hauteur, wall_right.pos_z);
    glEnd();

    /* PLAFOND */
    // Définir la couleur de dessin en bleu + 0.2f 
    glColor4f(wall_right.c.r, wall_right.c.g, wall_right.c.b + 0.2f , wall_right.c.a); //TODO

    // Dessiner un rectangle pour représenter le plafond
    glBegin(GL_QUADS);
    glVertex3f(wall_right.pos_x, wall_right.pos_y, wall_right.pos_z + wall_right.profondeur);
    glVertex3f(wall_right.pos_x , wall_right.pos_y, wall_right.pos_z + wall_right.profondeur);
    glVertex3f(wall_right.pos_x + wall_right.largeur, wall_right.pos_y + wall_right.hauteur, wall_right.pos_z + wall_right.profondeur);
    glVertex3f(wall_right.pos_x, wall_right.pos_y + wall_right.hauteur, wall_right.pos_z + wall_right.profondeur);
    glEnd();
}