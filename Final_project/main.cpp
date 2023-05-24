#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4] = {1, 1, 1, 1};
int ID=3; ///0:�Y 1:���� 2:�W���u 3:�U���u
FILE * fout = NULL;
FILE * fin = NULL;
float teapotX=0,teapotY=0;
///float angle=0, angle2=0, angle3=0;
float angle[20] = {}; ///�ܰ}�C
void keyboard(unsigned char key, int x, int y){
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;
    if(key=='s'){
        if(fout==NULL) fout = fopen("motion.txt", "w"); ///�g�ɮ�
        for(int i=0;i<20;i++){ ///�g�ɮ�
            fprintf(fout, "%0.2f ", angle[i]); ///�g�ɮ� �᭱������
        }
        fprintf(fout, "\n"); ///�g�ɮ� �᭱������
    }else if(key=='r'){
        if(fin==NULL) fin = fopen("motion.txt", "r"); ///Ū�ɮ�
        for(int i=0;i<20;i++){
            fscanf(fin, "%f", &angle[i]);
        }
        glutPostRedisplay();
    }
    ///if(key=='0')show[0] = !show[0];
    ///if(key=='1')show[1] = !show[1];
    ///if(key=='2')show[2] = !show[2];
    ///if(key=='3')show[3] = !show[3];

    glutPostRedisplay();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2, 0.2, 0.2);
        if(body==NULL){
            head = glmReadOBJ("model/head.obj");
            body = glmReadOBJ("model/body.obj");
            uparmR = glmReadOBJ("model/uparmR.obj");
            lowarmR = glmReadOBJ("model/lowarmR.obj");
            ///glmUnitize(body);
        }
        if(ID==0) glColor3f(1, 0, 0); ///��w�]����
        else glColor3f(1, 1, 1);
        if(show[0]) glmDraw(head, GLM_MATERIAL);

        if(ID==1) glColor3f(1, 0, 0); ///��w�]����
        else glColor3f(1, 1, 1); ///�S��w�]�զ�
        if(show[1]) glmDraw(body, GLM_MATERIAL);

        glPushMatrix();
            glTranslatef(-1.106666, +0.480000, 0); ///�n���t�ۤ�
            glRotatef(angle[2], 0, 0, 1); ///��ΰ}�C
            glTranslatef(1.106666, -0.480000, 0); ///��Ӫ��I

            if(ID==2) glColor3f(1, 0, 0); ///��w�]����
            else glColor3f(1, 1, 1); ///�S��w�]�զ�
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);
            glPushMatrix();
                glTranslatef(-2.019998, +0.200000, 0); ///�n���t�ۤ�
                glRotatef(angle[3], 0, 0, 1); ///��ΰ}�C
                glTranslatef(2.019998, -0.200000, 0); ///��Ӫ��I

                if(ID==3) glColor3f(1, 0, 0); ///��w�]����
                else glColor3f(1, 1, 1); ///�S��w�]�զ�
                if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);
            glPopMatrix();

        glPopMatrix();



    glPopMatrix();
    glColor3f(0, 1, 0); ///��@�Ӥp�����b��������Ѧ��I
    glutSolidTeapot(0.02);
    glutSwapBuffers();
}
int oldX=0,oldY=0;
void motion(int x, int y){
    teapotX += (x - oldX)/150.0;
    teapotY -= (y - oldY)/150.0;
    angle[ID] += (x-oldX); ///��ΰ}�C
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        oldX = x;///teapotX = (x-150)/150.0;
        oldY = y;///teapotY = (150-y)/150.0;

        ///printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
        ///if(fout=NULL) fout = fopen("file4.txt", "w");///�S�}�ɮ� �N�}�ɮ�
        ///fprintf(fout, "%f %f\n", teapotX, teapotY);///�n�A�s�y��
    }
    display();
}
/*void keyboard(unsigned char key, int x, int y)
{
    if(fin==NULL){///�p�G�ɮרS��fopen() �N�}��
        fclose(fout);///�e��mouse�|�}fout���� �ҥH�n����
        fin = fopen("file4.txt", "r");///�S�}�ɮ� �N�}
    }
    fscanf(fin, "%f %f", &teapotX, &teapotY);///�u��Ū��
    display();///���e�e��
}*/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
