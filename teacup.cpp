#include <iostream>
#include <glut.h>
#include <math.h>

#define INIT_WIN_X 400
#define INIT_WIN_Y 400

GLfloat teapot_size = 0.5f;
float xRot = 0.0f, yRot = 0.0f;
float distance = 10.0f;
int x_mouse = 0, y_mouse = 0;


void Draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0.3, 0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);

   
    glutWireTeapot(teapot_size);

    glFlush();
    glutSwapBuffers();
}



void MyMouseMotion(int x, int y)
{
    int incX = x - x_mouse;
    int incY = y - y_mouse;   

    if (incX > incY && incX > 0)
        yRot += atan2(x, distance);
        
    else if (incX < incY && incY > 0)
        xRot += atan2(y, distance);
    
    else if (incX < incY && incX < 0 )
        yRot -= atan2(x, distance);   

    else if (incX > incY && incY < 0)
        xRot -= atan2(y, distance);
    x_mouse = x;
    y_mouse = y;

    glutPostRedisplay();
}

void MyReshape(int NewWidth, int NewHeight)
{
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)INIT_WIN_X;
    GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)INIT_WIN_Y;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
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
    glutMotionFunc(MyMouseMotion);
    glutMainLoop();


    return 0;
}
