#include <windows.h> ///標頭檔要放最前面呼叫PlaySound("檔名", NULL, SND_ASYNC);便能播放
#include <GL/glut.h>
void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='1') PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\do.wav", NULL, SND_ASYNC);
    if(key=='2') PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\re.wav", NULL, SND_ASYNC);
    if(key=='3') PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\mi.wav", NULL, SND_ASYNC);
    ///音樂檔 先用絕對路徑
    ///其中NULL代表這個播放音樂沒有掛在任何物件下
    ///SND_ASYNC不等待同步 所以播放會馬上繼續
}
int main(int argc, char**argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
   glutCreateWindow("week11");

   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);

   glutMainLoop();
}
