#include "3D_tools.h"

/* Camera parameters and functions */
float theta = 45.0f;	// Angle between x axis and viewpoint
float phy = 60.0f;		// Angle between z axis and viewpoint
float dist_zoom = 1.0f; // Distance between origin and viewpoint

void setCamera()
{
	gluLookAt(2,			  // x
			  0,			  // y
			  0,			  // z
			  0.0, 0.0, 0.0,  // point visé
			  0.0, 0.0, 1.0); // vecteur qui indique la direction du haut (unitaire de préférence comme l'axe z)
}

/* Convert degree to radians */
float toRad(float deg)
{
	return deg * M_PI / 180.0f;
}

void drawSquare()
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
}

void drawCircle()
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0, 0.0, 0.0);
	float step_rad = 2 * M_PI / (float)NB_SEG_CIRCLE;
	for (int i = 0; i <= NB_SEG_CIRCLE; i++)
	{
		glVertex3f(cos(i * step_rad), sin(i * step_rad), 0.0f);
	}
	glEnd();
}

void drawSphere()
{
	gluSphere(gluNewQuadric(), 1.0, NB_SEG_CIRCLE, NB_SEG_CIRCLE);
}