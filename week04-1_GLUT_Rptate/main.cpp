#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///step02-2 清背景
    glPushMatrix(); ///step02-1 備份矩陣
        glRotatef(angle, 0, 1, 0 ); ///旋轉angle角度
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///step02-1 還原矩陣

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
