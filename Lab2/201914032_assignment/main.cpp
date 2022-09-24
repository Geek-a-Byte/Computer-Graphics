// window ke dekhar jonno
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
//  background color = black, r,g,b,alpha=opacity
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);//white);  //sets the color value to clear buffer
    glOrtho(-50,50,-50,50,-50,50); //(left,right)-x,(bottom,top)-y, (near,far)-z
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
			glutIdleFunc(spinDisplay_left);
//			PlaySound("C:\\Users\\Hp\\Desktop\\CSE414\\lab02\\test\\bin\\Debug\\sound1.wav", NULL, SND_ASYNC|SND_FILENAME);
			PlaySound("sound1.wav", NULL, SND_ASYNC|SND_FILENAME);
			break;

		case 'r':
		    // shob movement ke null kore dibe
		    glutIdleFunc(spinDisplay_right);
			break;

		case 's':
		    // shob movement ke null kore dibe
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
				// ager jinish theke jay, notun render er jonno
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
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2d(-260, 0.0);
        glVertex2d(260, 0.0);
        glVertex2d(260, 300.0);
        glVertex2d(-260, 300.0);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);//Green
    glBegin(GL_QUADS);
        glVertex2d(-260, 0.0);
        glVertex2d(260, 0.0);
        glVertex2d(260, -300.0);
        glVertex2d(-260, -300.0);
    glEnd();

    // niche theke 1st polygon
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glBegin(GL_QUADS);
        glVertex2d(-8.02, -34.09);
        glVertex2d(-8.08, -32.17);
        glVertex2d(8.73, -32.16);
        glVertex2d(8.73, -34.09);
    glEnd();

    // 2nd polygon
    glColor3f(0.25f, 0.0f, 0.0f);//Brown
    glBegin(GL_QUADS);
        glVertex2d(-6.09, -32.16);
        glVertex2d(-8.07, -19.00);
        glVertex2d(8.73, -19.00);
        glVertex2d(6.75, -32.16);
    glEnd();

    //2nd polygon er majhe 1st line
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
    glBegin(GL_QUADS);
        glVertex2d(-6.57, -29.23);
        glVertex2d(7.14, -29.23);
        glVertex2d(7.30, -28.36);
        glVertex2d(-6.65, -28.36);
    glEnd();

    //2nd polygon er majhe 2nd line
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
    glBegin(GL_QUADS);
        glVertex2d(-7.36, -23.60);
        glVertex2d(8.02, -23.68);
        glVertex2d(8.18, -22.65);
        glVertex2d(-7.52, -22.73);
    glEnd();


    glColor3f(0.1f, 0.0f, 0.1f);//Dark Purple
    glBegin(GL_QUADS);
        glVertex2d(-11.01, -18.92);
        glVertex2d(-11.01, -17.02);
        glVertex2d(11.69, -17.05);
        glVertex2d(11.74, -18.93);
    glEnd();

    //line
    glColor3f(0.2f, 0.1f, 0.4f);//Dark grey
    glBegin(GL_QUADS);
        glVertex2d(-1.16, -17.03);
        glVertex2d(0.85, -17.03);
        glVertex2d(0.85, -0.02);
        glVertex2d(-1.16, -0.02);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);

     // 1st blade
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white;
    glBegin(GL_QUADS);
        glVertex2d(-.13, -.02);
        glVertex2d(-10.03, -5.63);
        glVertex2d(-8.05, -9.49);
        glVertex2d(1.80, -3.74);
    glEnd();

     // 2nd blade
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glBegin(GL_QUADS);
        glVertex2d(-0.13, -0.02);
        glVertex2d(-4.14, -1.89);
        glVertex2d(-9.05, 7.57);
        glVertex2d(-5.10, 9.47);
    glEnd();

     // 3rd blade
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
    glBegin(GL_QUADS);
        glVertex2d(-.13, -.02);
        glVertex2d(-2.12, 3.75);
        glVertex2d(6.76, 8.54);
        glVertex2d(8.70, 4.72);
    glEnd();

     // 4th blade
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glBegin(GL_QUADS);
        glVertex2d(-0.18, -.07);
        glVertex2d(4.77, -9.49);
        glVertex2d(8.70, -7.55);
        glVertex2d(3.80, 1.87);
    glEnd();

    glPopMatrix();

    // first push, then movement, then pop
 	glPushMatrix();
 	glColor3f(0.0f, 0.0f, 0.0f);//Black
	circle(0.5,0.5);
 	glTranslatef(18.0,4.0,0);
	glPopMatrix();


    glFlush(); //force execution of Gl commands
}
int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(520,550); // Size of the window
    glutInitWindowPosition(100, 100); // location of the window
    glutCreateWindow("CSE 19"); // Create window with this name
    init(); // call initialize function
    glutDisplayFunc(myDisplay); // call display function
    glutKeyboardFunc(my_keyboard); //control with keyboard
	glutMouseFunc(my_mouse);//control with mouse
	glutSpecialFunc(spe_key);//control with up,down,left......
	glutMainLoop(); //continuous display running rakhar jonno
	return 0;
}

