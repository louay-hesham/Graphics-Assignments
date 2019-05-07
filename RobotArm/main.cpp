#include <GL/gl.h>
#include <GL/glut.h>
#include <unistd.h>
#include <iostream>
#include <math.h>

#define step 30
#define PI acos(-1)

using namespace std;

void display(void);
void idle(void);
void init();
void renderPrimitive();
double degressToRadian(int d);

double L1, L2;
int th1=0, th2=0;

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
    renderPrimitive();
    glPopMatrix();
    glutSwapBuffers();
}

double degressToRadian(int d)
{
    return d * PI / 180;
}

void renderPrimitive()
{
    glLineWidth(50.0);
    glRotated(th1, 0, 0, 1);
    glBegin(GL_LINES);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(L1,0.0);
    glEnd();
    glRotated(-th1, 0, 0, 1);
    double x = L1 * cos(degressToRadian(th1));
    double y = L1 * sin(degressToRadian(th1));
    glTranslated(x, y, 0.0);

    glRotated(th2, 0, 0, 1);
    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(L2,0.0);
    glEnd();

    usleep(10000);
    th1 += 1;
    th2 += 4;
    th1 %= 360;
    th2 %= 360;
}

void idle(void)
{
    display();
}

/*int main()
{
    cout << PI << endl;
    int L1, L2;

    int n_coordinates = pow(360/step, 2);
    int x[n_coordinates], y[n_coordinates];
    int i = 0;
    for (int th1 = 0; th1 < 360; th1 += step)
    {
        for (int th2 = 0; th2 < 360; th2 += step)
        {
            cout << th1 << " " << th2 << endl;
            x[i] = L1*cos(degressToRadian(th1)) + L2*cos(degressToRadian(th1 + th2));
            y[i] = L1*sin(degressToRadian(th1)) + L2*sin(degressToRadian(th1 + th2));
            i++;
        }
    }

    for (int j = 0; j < n_coordinates; j++)
    {
        cout << x[j] << " " << y[j] << endl;
    }
    return 0;
}
*/
