#include <GL/glut.h>
void display()
{
    glColor3f(0,1,0);///���
    glBegin(GL_POLYGON);///�}�l�e�h���
        glColor3f(1,0,0); glVertex2f( 0, 1);///���⳻�IVertex
        glColor3f(0,1,0); glVertex2f(-1,-1);///��⳻�IVertex
        glColor3f(0,0,1); glVertex2f( 1,-1);///�Ŧ⳻�IVertex
    glEnd();///�����e


    glColor3f(1,1,0);///����
    glutSolidTeapot(0.3);///�e�X�@�ӹ�ߪ�����
    glutSwapBuffers();///��GLUT��e��swap�e����ܦ�m
}
int main(int argc, char *argv[])///�S�O��main�禡(���ܦh�Ѽ�)
{
	glutInit(&argc, argv);///��GLUT�}�_��
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GLUT Shapes");///�}����
	glutDisplayFunc(display);///��ܹ����禡
	glutMainLoop();///��main�j�����b�̫᭱
}
