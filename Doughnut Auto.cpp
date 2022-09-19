
#include <iostream>
#include "gl/glut.h"
#define INIT_WIN_X 400
#define INIT_WIN_Y 400
#define MAX(x,y) x>y?x:y                                                
#define MIN(x,y) x<y?x:y                                               

GLfloat inner_radius = 0.2f;
GLfloat outer_radius = 0.5f;
GLfloat scale_factor = 0.002f;
GLint sides = 30;                                                      
GLint rings = 40;                                                      

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    glutWireTorus(inner_radius, outer_radius, sides, rings);
    glFlush();
}

void MyReshape(int NewWidth, int NewHeight)
{
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)INIT_WIN_X;
    GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)INIT_WIN_Y;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
    glRotated(70, .3, .3, .3);
}

void Timer(int x)
{
    outer_radius = outer_radius + scale_factor;
    if (outer_radius > (GLfloat)0.5f || outer_radius < (GLfloat)0.45f)
        scale_factor *= -1;
          
    glutTimerFunc(30, Timer, 1);
    glutPostRedisplay();
}

int main(int argc, char** argv)                 
{
    glutInit(&argc, argv);                      
    glutInitDisplayMode(GLUT_RGB);              
    glutInitWindowSize(INIT_WIN_X, INIT_WIN_Y);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL TEST");            

    glClearColor(1.0, 1.0, 1.0, 1.0);           

    glutDisplayFunc(Draw);                      
    glutReshapeFunc(MyReshape);

    glutTimerFunc(30, Timer, 1);

    glutMainLoop();                            

    return 0;
}
