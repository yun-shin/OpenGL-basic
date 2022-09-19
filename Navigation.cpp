
#include <iostream>
#include "gl/glut.h"
#include <math.h>
#include <windows.h>

int Width, Height;
int x_mouse = 0, y_mouse = 0, distance = 2000;

GLfloat squareR1 = 0.0f, squareR2 = 0.52f, squareG1 = 0.0f, squareG2 = 0.52f, squareB1 = 0.0f, squareB2 = 0.52f;
GLfloat x = 0.0f, y = 0.0f, zzz = 0.0f;

GLfloat lookX = 30.0f, lookY = 1.0f, lookZ = 00.0f;
GLfloat atX = 0.0, atY = 0.0, atZ = 0.0;
GLfloat angleX = 0.0, angleY = 1.0, angleZ = 0.0;

void Timer2(int x);

void InitLight()
{
    GLfloat mat_diffuse[] = { 0.5, 0.5, 0.6, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat mat_shininess[] = { 15.0 };

    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat light_ambidnt[] = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat light_position[] = { -3, 6, 3.0, 0.0 };

    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambidnt);

    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
}

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);            
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
}

void swap(GLfloat* a, GLfloat* b)                       
{
    GLfloat temp = *a;
    *a = *b;
    *b = temp;
}

void DrawFloor()                                        
{
    GLfloat* squareColor[6] = { &squareR1, &squareG1, &squareB1, &squareR2, &squareG2,  &squareB2 };

     for (x = 0.0; x < 100.0; x += 2.0)
    {
        glPushMatrix();

        glColor3f(squareR1, squareG1, squareB1);
        glTranslatef(x, -1.0, zzz);

        glBegin(GL_QUADS);                                 
        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, -0.5);
        glVertex3f(-0.5, 0.0, -0.5);
        glVertex3f(-0.5, 0.0, 0.5);
        glEnd();

        glPopMatrix();
    }

    for (x = 1.0; x < 100.0; x += 2.0)
    {
        glPushMatrix();

        glColor3f(squareR2, squareG2, squareB2);            
        glTranslatef(x, -1.0, zzz);

        glBegin(GL_QUADS);                                  
        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, -0.5);
        glVertex3f(-0.5, 0.0, -0.5);
        glVertex3f(-0.5, 0.0, 0.5);
        glEnd();

        glPopMatrix();
    }
    for (int i = 0; i < 3; i++)
        swap(squareColor[i], squareColor[i + 3]);

    zzz++;

    if (zzz > 100)
        zzz = 0;
}

void DrawCube()                                                               
{
    GLfloat cubeColor[3] = { 0 }, cubeTrans =2;

	for (int i = 0; i < 10; i++)                                           
	{
        glPushMatrix();
		cubeTrans += 2.5;

		glColor3f(cubeColor[0], cubeColor[1], cubeColor[2]);
		glTranslatef(3.0, 0.0, cubeTrans);
		glutSolidCube(1.0);

        cubeColor[1] += 0.1;
        cubeColor[2] += 0.1;
        glPopMatrix();
	}

    cubeTrans = 2;
	for (int i = 0; i < 10; i++)                                           
	{
        glPushMatrix();
        cubeTrans += 2.5;

        glColor3f(cubeColor[0], cubeColor[1], cubeColor[2]);
        glTranslatef(10.0, 0.0, cubeTrans);
		glutSolidCube(1.0);

        cubeColor[0] -= 0.1;
        cubeColor[1] -= 0.2;
        glPopMatrix();
	}

    cubeTrans = 2;
    for (int i = 0; i < 10; i++)                                           
    {
        glPushMatrix();
        cubeTrans += 2.5;

        glColor3f(cubeColor[0], cubeColor[1], cubeColor[2]);
        glTranslatef(17.0, 0.0, cubeTrans);
        glutWireCube(1.0);
        glutSolidCube(0.3);

        cubeColor[0] += 0.1;
        cubeColor[2] -= 0.1;
        glPopMatrix();
    }

    cubeTrans = 2;
    for (int i = 0; i < 10; i++)                                         
    {
        glPushMatrix();
        cubeTrans += 2.5;

        glColor3f(cubeColor[0], cubeColor[1], cubeColor[2]);
        glTranslatef(24.0, 0.0, cubeTrans);
        glutSolidCube(1.0);

        cubeColor[0] -= 0.1;
        cubeColor[1] += 0.2;
        glPopMatrix();
    }

    cubeTrans = 2;
    for (int i = 0; i < 10; i++)                                          
    {
        glPushMatrix();
        cubeTrans += 2.5;

        glColor3f(cubeColor[0], cubeColor[1], cubeColor[2]);
        glTranslatef(31.0, 0.0, cubeTrans);
        glutSolidCube(1.0);

        cubeColor[2] += 0.1;
        cubeColor[1] -= 0.2;
        glPopMatrix();
    }

    cubeTrans = 2;
    for (int i = 0; i < 10; i++)                                           
    {
        glPushMatrix();
        cubeTrans += 2.5;

        glColor3f(cubeColor[0], cubeColor[1], cubeColor[2]);
        glTranslatef(38.0, 0.0, cubeTrans);
        glutSolidCube(1.0);

        cubeColor[0] += 0.1;
        glPopMatrix();
    }
}

void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glPushMatrix();

	glLoadIdentity();
	gluPerspective(30, 1.0, 3.0, 50.0);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

	gluLookAt(lookX, lookY, lookZ, atX, atY, atZ, angleX, angleY, angleZ);

	glDisable(GL_LIGHTING);
	for (int i = 0; i < 100; i++)
		DrawFloor();

	glEnable(GL_LIGHTING);                                                      
	glEnable(GL_COLOR_MATERIAL);                                                
    glEnable(GL_DEPTH_TEST);                                                    
    glEnable(GL_CULL_FACE);
    DrawCube();
	

	glPopMatrix();

	glMatrixMode(GL_PROJECTION);

	glPopMatrix();

	glutSwapBuffers();
}



void MyMouseMotion(int x, int y)
{
    int incX = x - x_mouse;
    int incY = y - y_mouse;

	if (incX > incY && incX > 0)
	{
        if (atZ < 50 && atZ > -30)
            atZ -= atan2(y, distance);
        else atZ = 0;
	}

	if (incX > incY && incY < 0)
            atY += atan2(x, distance);

	else if (incX < incY && incX < 0)
	{
		if (atZ < 50 && atZ > -50)
			atZ += atan2(y, distance);
        else atZ = 0;
	}

	else if (incX < incY && incY > 0)
            atY -= atan2(x, distance);
	
    x_mouse = x;
    y_mouse = y;

    glutPostRedisplay();
}

void Timer1(int x)                                                              
{    
	lookY += 0.5;
	atY += 0.5;

    if (lookY == 3)
    {
        glutTimerFunc(70, Timer2, 1);
        return;
    }

    if (lookY > 5)
        return;

	glutTimerFunc(70, Timer1, 1);
    glutPostRedisplay();
}

void Timer2(int x)                                                             
{
    lookY -= 0.5;
    atY -= 0.5;

    if (lookY == 1)
        return;

    if (lookY < 0)
        return;

    glutTimerFunc(70, Timer2, 1);
    glutPostRedisplay();
}

void Keyboard(unsigned char Key, int X, int Y)                                 
{
	switch (Key)
	{
	case 'w':
        atX -= 1;
		lookX--;
        glutTimerFunc(70, Timer1, 1);
		break;

	case 's':
		lookX++;
        glutTimerFunc(70, Timer1, 1);
		break;

	case 'a':
		lookZ++;
		atX -= 1;
        glutTimerFunc(70, Timer1, 1);
		break;

	case 'd':
		lookZ--;
		atX -= 1;
        glutTimerFunc(70, Timer1, 1);
		break;
	}

    glutPostRedisplay();
}

void MyReshape(int w, int h)
{
    Width = w;
    Height = h;
}

int main(int argc, char** argv)
{
    Width = 1000;
    Height = 800;

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(Width, Height);;
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Sample Drawing");

    InitLight();                                                                                       
	Init();   

	glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);

	glutKeyboardFunc(Keyboard);
	glutPassiveMotionFunc(MyMouseMotion);

	glutMainLoop();

    return 0;
}
