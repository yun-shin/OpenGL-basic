
#include <iostream>
#include "GL/glut.h"
#include <math.h>

#define angle_inc 1;

float subArmRot = 0.0f, baseArmRot = 0.0f;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	{
		glRotatef(baseArmRot, 0, 0, 1);

		glBegin(GL_LINES);
		glVertex2f(0.0f, 0.4f);
		glVertex2f(0.0f, 0.0f);
		glEnd();

		glTranslatef(0, 0.4, 0);
		glRotatef(subArmRot, 0, 0, 1);

		glBegin(GL_LINES);
		glVertex2f(0.0f, 0.2f);
		glVertex2f(0.0f, 0.0f);
		glEnd();
	}
	glPopMatrix();

	glutSwapBuffers();
}

void Keyboard(unsigned char Key, int X, int Y)
{
	switch (Key)
	{
	case 'q':
		baseArmRot += angle_inc;
		break;

	case 'a':
		baseArmRot -= angle_inc;
		break;

	case 'w':
		subArmRot += angle_inc;
		break;

	case 's':
		subArmRot -= angle_inc;
		break;
	}

	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutCreateWindow("opengl project");

	glutDisplayFunc(display);
	glutKeyboardFunc(Keyboard);

	glutMainLoop();
	return 0;
}

