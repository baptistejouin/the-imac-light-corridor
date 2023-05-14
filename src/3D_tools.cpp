#include "3D_tools.h"

float cam_x = 0.0f;
float cam_y = 0.0f;
float cam_z = 0.0f;

void setCamera()
{
	gluLookAt(cam_x,				 // x
			  cam_y,				 // y
			  cam_z,				 // z
			  cam_x - 1, 0.0, cam_z, // point visé
			  0.0, 0.0, 1.0);		 // vecteur qui indique la direction du haut (unitaire de préférence comme l'axe z)
}

/* Convert degree to radians */
float toRad(float deg)
{
	return deg * M_PI / 180.0f;
}

void drawSquare(bool const filled, float const size)
{
	if (filled)
		glBegin(GL_TRIANGLE_FAN);
	else
		glBegin(GL_LINE_LOOP);

	glVertex3f(-size, -size, 0.0);
	glVertex3f(size, -size, 0.0);
	glVertex3f(size, size, 0.0);
	glVertex3f(-size, size, 0.0);
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

void drawSphere(float const size)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	gluSphere(gluNewQuadric(), size, NB_SEG_CIRCLE, NB_SEG_CIRCLE);
}