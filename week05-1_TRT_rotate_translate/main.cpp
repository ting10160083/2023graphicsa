#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///step02-2 �M�I��

    glColor3f(0, 1, 0);///���
    glPushMatrix();
        glTranslatef(0.8, 0, 0);///�̫�O��⪺����
        glRotatef(angle, 0, 0, 1 );///���Z�b��
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glColor3f(1, 0, 0);///����
    glPushMatrix();
        glRotatef(angle, 0, 0, 1 );///���Z�b��A�̫�O���⪺���
        glTranslatef(0.8, 0, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();



    glutSwapBuffers();
    angle++;///�⨤��++
}

int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///����idle�ɭ��e�e��

    glutMainLoop();
}
