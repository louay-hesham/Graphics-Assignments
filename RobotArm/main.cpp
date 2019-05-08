#include <GL/gl.h>
#include <GL/glut.h>
#include <unistd.h>
#include <iostream>
#include <math.h>

#define step 30
#define PI acos(-1)
#define DEG2RAD PI/180

using namespace std;

void display(void);
void idle(void);
void init();
void renderPrimitive(double mult);
double degressToRadian(int d);

double L1, L2;
int th1=0, th2=0, th3=-60, m=6;

int main(int argc, char** argv)
{
    cout << "Enter arms lengths: ";
    cin >> L1 >> L2;
    int mode = GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA;
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitDisplayMode(mode);
    glutCreateWindow("Robot Arm");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glLoadIdentity();
    glutMainLoop();
    return 0;
}

void display(void)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -2, 2, -2, 2, -1, 1 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0f,0.0f,0.0f);
    renderPrimitive(1);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -2, 2, -2, 2, -1, 1 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0f,0.0f,0.0f);
    renderPrimitive(2);
    glPopMatrix();
    glutSwapBuffers();
}

double degressToRadian(int d)
{
    return d * PI / 180;
}

void drawCircle(float radius)
{
   glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 1.0, 1.0);

   for (int i=0; i < 360; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(cos(degInRad)*radius, sin(degInRad)*radius);
   }

   glEnd();
}

void renderPrimitive(double mult)
{
    glLineWidth(50.0);
    glRotated(th1*mult, 0, 0, 1);
    glBegin(GL_LINES);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(L1,0.0);
    glEnd();

    glTranslated(L1, 0.0, 0.0);

    drawCircle(0.1);

    glRotated(th2*mult, 0, 0, 1);
    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(L2,0.0);
    glEnd();
    glRotated(-th2*mult, 0, 0, 1);

    double x_rel = L2 * cos(degressToRadian(th2*mult));
    double y_rel = L2 * sin(degressToRadian(th2*mult));
    glTranslated(x_rel, y_rel, 0.0);
    glRotated(th2*mult, 0, 0, 1);
    glRotated(th3*mult, 0, 0, 1);
    glBegin(GL_LINES);
        glColor3f(0.0, 1.0, 1.0);

        glVertex2f(0.0,-0.1);
        glVertex2f(0.0,0.1);

        glVertex2f(0.0,-0.1);
        glVertex2f(0.1,-0.1);

        glVertex2f(0.0,0.1);
        glVertex2f(0.1,0.1);
    glEnd();

    usleep(10000);
    th1 += 1;
    th2 += 2;
    th1 %= 360;
    th2 %= 360;
    th3 += m;
    if (th3 > 60 || th3 < -60)
        m *= -1;
    glRotated(-th3*mult, 0, 0, 1);
    glRotated(-th2*mult, 0, 0, 1);
    glTranslated(-x_rel, -y_rel, 0.0);
    glRotated(th2*mult, 0, 0, 1);
    glRotated(-th2*mult, 0, 0, 1);
    glTranslated(-L1, 0.0, 0.0);
    glRotated(-th1*mult, 0, 0, 1);
}

void idle(void)
{
    display();
}
