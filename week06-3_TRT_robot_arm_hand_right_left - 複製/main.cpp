#include <GL/glut.h>
float angle=0;
void drawHand()
{
    glPushMatrix();
        glScalef(1,0.3,0.3);///�j�p
        glutSolidCube(0.5);
    glPopMatrix();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glPushMatrix();///�k�W���u
        glTranslatef(0.25, 0, 0);///���W�h
        glRotatef(angle, 0, 0, 1);///�i�H���
        glTranslatef(0.25, 0, 0);///����ʪ����ߩ�b����

        drawHand();///�k�U��y
        glPushMatrix();
            glTranslatef(0.25, 0, 0);///���W�h
            glRotatef(angle, 0, 0, 1);///�i�H���
            glTranslatef(0.25, 0, 0);///����ʪ����ߩ�b����
            drawHand();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///���W���u
        glTranslatef(-0.25, 0, 0);///���W�h
        glRotatef(angle, 0, 0, 1);///�i�H���
        glTranslatef(-0.25, 0, 0);///����ʪ����ߩ�b����

        drawHand();///���U��y
        glPushMatrix();
            glTranslatef(-0.25, 0, 0);///���W�h
            glRotatef(angle, 0, 0, 1);///�i�H���
            glTranslatef(-0.25, 0, 0);///����ʪ����ߩ�b����
            drawHand();
        glPopMatrix();
    glPopMatrix();


    glutSwapBuffers();
    angle++;
}

int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
}
