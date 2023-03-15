#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///step02-2 清背景

    glColor3f(0, 1, 0);///綠色的身體
    glPushMatrix();
        glutSolidCube( 0.5 );

        glPushMatrix();
            glTranslatef(0.25,0.25, 0);///把整個東西掛在右上角
            glRotatef(angle, 0, 0, 1);///轉動
            glTranslatef(0.25,0.25, 0);///把旋轉中心放到中心

///           glTranslatef(0.5,0.5, 0); ///先註解

            glColor3f(1, 0, 0);///紅色的手臂
            glutSolidCube( 0.5);
        glPopMatrix();

    glPopMatrix();



    glutSwapBuffers();
    angle++;///把角度++
}

int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///有空idle時重畫畫面

    glutMainLoop();
}
