#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

float xx1,xx2,yy1,yy2;

void init()
{
     glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
     glOrtho (-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);
}


static void idle(void)
{
    glutPostRedisplay();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT); //clear buffer, buffer_bit indicates the buffers currently enabled for color writing
    while(xx1!=xx2 and yy1!=yy2){
        float m=(yy2-yy1)/(xx2-xx1);
        cout<<xx1<<" "<<yy1<<" "<<xx2<<" "<<yy2<<" "<<m<<endl;
        if(abs(m)<=1)
        {
            float step=abs(xx2-xx1)/2;
            glBegin(GL_POINTS);
            glColor3f(1.0f, 0, 0);
            glVertex2f(xx1,yy1);
            glEnd();
            xx1=xx1+step;
            yy1=yy1+m*step;

        }
        else
        {
             float step=abs(yy2-yy1)/2;
             glBegin(GL_POINTS);
             glColor3f(1.0f, 0, 0);
             glVertex2f(xx1,yy1);
             glEnd();
             xx1=xx1+step/m;
             yy1=yy1+step;
        }
    }
    glFlush(); //force execution of Gl commands
}


/* Program entry point */

int main(int argc, char *argv[])
{

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Size of the window
    glutInitWindowPosition(100, 100); // location of the window
    glutCreateWindow("CSE 19"); // Create window with this name
    init();
    cin>>xx1>>xx2>>yy1>>yy2; // 1 2 3 4
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}
