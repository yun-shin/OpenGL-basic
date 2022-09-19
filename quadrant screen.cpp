
#include <iostream>
#include "gl/glut.h"

int Width, Height, x;

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

void Init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);            //1
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void DrawScene()
{
    glColor3f(1.0, 1.0, 1.0);

    glPushMatrix();
    glTranslatef(0.0, -1.0, 0.0);

    glBegin(GL_QUADS);                                  //2
    glVertex3f(2.0, 0.0, 2.0);
    glVertex3f(2.0, 0.0, -2.0);
    glVertex3f(-2.0, 0.0, -2.0);
    glVertex3f(-2.0, 0.0, 2.0);

    glEnd();
    glPopMatrix();

    glColor3f(0.3, 0.3, 0.7);

    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.5);
    if (x == 0)
        glutWireTeapot(1.0);                            //3 
    else
        glutSolidTeapot(1.0);
    glPopMatrix();
}

void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glViewport(0, 0, Width / 2, Height / 2);            //4 x축

    glPushMatrix();
    gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);     //5
    glDisable(GL_LIGHTING);
    x = 0;
    DrawScene();
    glPopMatrix();

    glViewport(Width / 2, 0, Width / 2, Height / 2);                //6 y축

    glPushMatrix();
    gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glDisable(GL_LIGHTING);
    x = 0;
    DrawScene();
    glPopMatrix();

    glViewport(0, Height / 2, Width / 2, Height / 2);               //7 top

    glPushMatrix();
    gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
    glDisable(GL_LIGHTING);
    x = 0;
    DrawScene();
    glPopMatrix();

    glViewport(Width / 2, Height / 2, Width / 2, Height / 2);       //8 임의 좌표
    glMatrixMode(GL_PROJECTION);

    glPushMatrix();
    glLoadIdentity();
    gluPerspective(30, 1.0, 3.0, 50.0);                         //9
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    //    gluLookAt(10.0, 10.0, 10.0,    0.0, 0.0, 0.0,    0.0, 1.0, 0.0);       //10
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glEnable(GL_LIGHTING);
    x = 1;
    DrawScene();
    glPopMatrix();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glFlush();
}

void MyReshape(int w, int h)
{
    Width = w;
    Height = h;
}

int main(int argc, char** argv)
{
    Width = 500;
    Height = 500;

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(Width, Height);;
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Sample Drawing");

    InitLight();
    Init();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);

    glutMainLoop();

    return 0;
}
