#include <GL/glut.h>
#include <math.h>///���Fcos,sin�n��
void myCircle(float r, float x, float y)
{
    glBegin(GL_POLYGON);
    for(float a=0;a<2*3.141592;a+=0.01){
        glVertex2f(r*cos(a)+x,r*sin(a)+y);
    }
    glEnd();
}
void display()
{
    glColor3f(1,0,1); myCircle(0.6,0,0);///������

    glColor3f(1,0,0); myCircle(0.3, 0.5,0.5);///�k�W��
    glColor3f(0,1,0); myCircle(0.3,-0.5,0.5);///���W��
    glColor3f(1,1,0); myCircle(0.3,-0.5,-0.5);///���U��
    glColor3f(0,0,1); myCircle(0.3, 0.5,-0.5);///�k�U��

    glutSwapBuffers();///��GLUT��e��swap�e����ܪ��a��
}

int main(int argc, char *argv[])///�S�O��main�禡(���ܦh�Ѽ�)
{
	glutInit(&argc, argv);///��GLUT�}�_��
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GLUT Shapes");///�}����
	glutDisplayFunc(display);///��ܹ����禡
	glutMainLoop();///��main�j�����b�̫᭱
}
