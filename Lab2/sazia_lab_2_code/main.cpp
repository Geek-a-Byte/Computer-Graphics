#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1416

static GLfloat spin = 0.0;
static float	tx	=  0.0;
static float	ty	=  0.0;

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  //sets the color value to clear buffer
    glOrtho(-5,5,-5,5,-5,5); //left,right,bottom,top, near, far
//    glOrtho(-100.0, 100.0, -100.0,100.0, -1.0, 1.0); // for easy calculation
}

void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

	glEnd();
}

void spinDisplay_left(void)
{
   spin = spin + .2;

   glutPostRedisplay();
}

void spinDisplay_right(void)
{
   spin = spin - .2;

   glutPostRedisplay();
}


void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'l':
			spinDisplay_left();
//			PlaySound("C:\\Users\\Hp\\Desktop\\CSE414\\lab02\\test\\bin\\Debug\\sound1.wav", NULL, SND_ASYNC|SND_FILENAME);
			PlaySound("sound1.wav", NULL, SND_ASYNC|SND_FILENAME);
			break;

		case 'r':
			spinDisplay_right();
			break;

		case 's':
			 glutIdleFunc(NULL);
			 break;

	  default:
			break;
	}
}

void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
				tx -=.5;
				glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:
				tx +=.5;
				glutPostRedisplay();
				break;

        case GLUT_KEY_DOWN:
				ty -=.5;
				glutPostRedisplay();
				break;

		case GLUT_KEY_UP:
				ty +=.5;
				glutPostRedisplay();
				break;
	  default:
			break;
	}
}

void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay_right);

         break;
      default:
         break;
   }
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT); //clear buffer, buffer_bit indicates the buffers currently enabled for color writing

    glColor3f(1.0f, 0.0f, 0.0f); //RGB Color
    glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glVertex2d(4.0, 4.0);
        glVertex2d(-4.0, 4.0);
        glVertex2d(-4.0, -4.0);
        glVertex2d(4.0, -4.0);
    glEnd();


    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glVertex2d(2.0, 0.0);
        glVertex2d(-2.0, 0.0);
        glVertex2d(-2.0, -4.0);
        glVertex2d(2.0, -4.0);
    glEnd();



    glColor3f(0.0f, 1.0f, 0.0f); //RGB Color
    glBegin(GL_TRIANGLES); // It can be any type Gl_POINT,_LINE
        glVertex2d(0.0, 2.0);
        glVertex2d(-2.0, 0.0);
        glVertex2d(2.0, 0.0);
    glEnd();
 glColor3f(0.0f, 1.0f, 0.0f);
 glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glVertex2f(2.5, -4.0);
        glVertex2f(2.5, -3.5);
        glVertex2f(-2.5, -3.5);
        glVertex2f(-2.5, -4.0);
    glEnd();

     glColor3f(0.0f, 0.0f, 0.0f);
 glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glVertex2f(0.5, -3.5);
        glVertex2f(0.5, -1.5);
        glVertex2f(-0.5, -1.5);
        glVertex2f(-0.5, -3.5);
    glEnd();

    glColor3f(1.0, 1.0, 0.0);
//
	glPushMatrix();
//
    glTranslatef(tx,ty,0);
	circle(.3,.3);

	glPopMatrix();
//
//
//
	glPushMatrix();
//
	glRotatef(spin, 0.0, 0.0, 1.0);
//
//
	glTranslatef(tx,ty,0);

	glBegin(GL_TRIANGLES); // It can be any type Gl_POINT,_LINE
	glColor3f(0, 0, 0);
        glVertex2f(0.3, 0);
        glVertex2f(3.0, 0.0);
        glVertex2f(0.5, 0.4);
    glEnd();

    glBegin(GL_TRIANGLES); // It can be any type Gl_POINT,_LINE
        glVertex2d(0.0, 0.3);
        glVertex2d(0.0, 3.0);
        glVertex2d(-.5, 0.4);
    glEnd();


    glBegin(GL_TRIANGLES); // It can be any type Gl_POINT,_LINE
        glVertex2d(-0.3, -0.2);
        glVertex2d(-3.0, -0.6);
        glVertex2d(-.5, -.7);
    glEnd();
//
	glPopMatrix();


    glFlush(); //force execution of Gl commands
}
int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Size of the window0
    glutInitWindowPosition(100, 100); // location of the window
    glutCreateWindow("CSE 19"); // Create window with this name
    init(); // call initialize function
    glutDisplayFunc(myDisplay); // call display function
    glutKeyboardFunc(my_keyboard); //control with keyboard
	glutMouseFunc(my_mouse);//control with mouse
	glutSpecialFunc(spe_key);//control with up,down,left......
	glutMainLoop();
	return 0;
}

