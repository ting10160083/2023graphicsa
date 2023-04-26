#include <windows.h>
int main()
{
    PlaySound("do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\re.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\re.wav", NULL, SND_SYNC);
}

///Build log 會寫 Checking for existence: C:\Users\Administrator\Desktop\week11-3_PlaySound.exe
///Executing: '"C:\Program Files (x86)\CodeBlocks/cb_console_runner.exe" "C:\Users\Administrator\Desktop\week11-3_PlaySound.exe"' (in 'C:\Users\Administrator\Desktop')
///他的執行目錄是在 C:\Users\Administrator\Desktop 我們的 do.wav re.wav在相對目錄裡
