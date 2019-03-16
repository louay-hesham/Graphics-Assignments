#include <GL/gl.h>
#include <GL/glut.h>
#include <unistd.h>

int angle = 0;

void display(void);
void idle(void);
void init();
void renderPrimitive();

int main(int argc, char** argv)
{
    int mode = GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA;
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitDisplayMode(mode);
    glutCreateWindow("Letter Z");
    // init();
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
    glTranslatef(0.0f,0.0f,-0.5f);
    renderPrimitive();
    glPopMatrix();
    glutSwapBuffers();

    //glClearColor(0.0, 1, 1, 0);
    //glClear(GL_COLOR_BUFFER_BIT);
    //glScalef(0.5f,0.5f,0.5f);
    //glutSwapBuffers();
}

void renderPrimitive()
{
    glScaled(2.0,2.0,0.0);
    glTranslated(-0.7, -0.5, 0.0);
    glBegin(GL_QUADS);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(0.5,0);
        glVertex2f(0.5,0.1);
        glVertex2f(0.0,0.1);

        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0,0.1);
        glVertex2f(0.1,0.1);
        glVertex2f(0.5,0.5);
        glVertex2f(0.4,0.5);

        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.0,0.5);
        glVertex2f(0.5,0.5);
        glVertex2f(0.5,0.6);
        glVertex2f(0.0,0.6);
    glEnd();

    glTranslated(1.0, 0.0, 0.0);
    usleep(10000);
    glRotated(angle, 0, 1, 0);
    angle += 2;
    angle %= 360;
    //angle -= 180;
    glRotated(-20.0, 1, 0, 0);
    glBegin(GL_QUAD_STRIP);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.1, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.1, 0.5, 0.0);

        glColor3f(0.0, 0.5, 0.0);
        glVertex3f(0.1, 0.0, 0.1);
        glVertex3f(0.1, 0.5, 0.1);

        glVertex3f(0.0, 0.5, 0.1);
        glVertex3f(0.0, 0.0, 0.1);

        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.4, 0.0, 0.0);
        glVertex3f(0.1, 0.0, 0.0);
        glVertex3f(0.4, 0.1, 0.0);
        glVertex3f(0.1, 0.1, 0.0);

        glColor3f(0.0, 0.0, 0.5);
        glVertex3f(0.4, 0.1, 0.1);
        glVertex3f(0.1, 0.1, 0.1);

        glVertex3f(0.4, 0.0, 0.1);
        glVertex3f(0.1, 0.0, 0.1);

        glVertex3f(0.4, 0.0, 0.0);
        glVertex3f(0.1, 0.0, 0.0);
    glEnd();
    glBegin(GL_QUAD_STRIP);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(0.4, 0.2, 0.0);
        glVertex3f(0.1, 0.2, 0.0);
        glVertex3f(0.4, 0.3, 0.0);
        glVertex3f(0.1, 0.3, 0.0);

        glColor3f(0.5, 0.0, 0.0);
        glVertex3f(0.4, 0.3, 0.1);
        glVertex3f(0.1, 0.3, 0.1);

        glVertex3f(0.4, 0.2, 0.1);
        glVertex3f(0.1, 0.2, 0.1);

        glVertex3f(0.4, 0.2, 0.0);
        glVertex3f(0.1, 0.2, 0.0);
    glEnd();
    glBegin(GL_QUAD_STRIP);
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(0.4, 0.4, 0.0);
        glVertex3f(0.1, 0.4, 0.0);
        glVertex3f(0.4, 0.5, 0.0);
        glVertex3f(0.1, 0.5, 0.0);

        glColor3f(0.0, 0.5, 0.5);
        glVertex3f(0.4, 0.5, 0.1);
        glVertex3f(0.1, 0.5, 0.1);

        glVertex3f(0.4, 0.4, 0.1);
        glVertex3f(0.1, 0.4, 0.1);

        glVertex3f(0.4, 0.4, 0.0);
        glVertex3f(0.1, 0.4, 0.0);
    glEnd();
}

void idle(void)
{
    display();
}

void init()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glViewport(0, 0, 700, 700);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -10, 20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable( GL_LIGHT0 );
    glEnable( GL_LIGHTING );

}
