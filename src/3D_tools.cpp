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

void drawSquare(bool const filled, float const size, TextureLoaded *texture, TexturePosition *texturePosition)
{
	if (texture != nullptr)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture->textureID);
	}

	if (filled && texture == nullptr)
		glBegin(GL_TRIANGLE_FAN);
	else if (!filled && texture == nullptr)
		glBegin(GL_LINE_LOOP);
	else
		glBegin(GL_QUADS);

	if (texture != nullptr)
	{
		if (texturePosition == nullptr)
		{
			TexturePosition defaultTexPos = {{0.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}};
			texturePosition = new TexturePosition(defaultTexPos);
		}

		// respect aspect ratio of the texture
		float textureAspect = static_cast<float>(texture->width) / texture->height;
		float height = size * textureAspect;
		float width = size;

		glTexCoord2f(texturePosition->bottomLeft.pos_x, texturePosition->bottomLeft.pos_y);
		glVertex3f(-width, height, 0.0);

		glTexCoord2f(texturePosition->bottomRight.pos_x, texturePosition->bottomRight.pos_y);
		glVertex3f(width, height, 0.0);

		glTexCoord2f(texturePosition->topRight.pos_x, texturePosition->topRight.pos_y);
		glVertex3f(width, -height, 0.0);

		glTexCoord2f(texturePosition->topLeft.pos_x, texturePosition->topLeft.pos_y);
		glVertex3f(-width, -height, 0.0);

		// draw order :
		// 1 2
		// 4 3
	}
	else
	{
		glVertex3f(-size, -size, 0.0);
		glVertex3f(size, -size, 0.0);
		glVertex3f(size, size, 0.0);
		glVertex3f(-size, size, 0.0);

		// draw order :
		// 1 2
		// 4 3
	}
	glEnd();

	if (texture != nullptr)
	{

		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
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

void drawSphere(float const size, Color color)
{
	glColor4f(color.r, color.g, color.b, color.a);
	gluSphere(gluNewQuadric(), size, NB_SEG_CIRCLE, NB_SEG_CIRCLE);
}