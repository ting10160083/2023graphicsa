#include <stdio.h>
int main()
{///�ɮ׫��� fout = �}�ɮ�("�ɦW","�άƻ�Ҧ�")
    FILE * fout = fopen("file.txt", "w");

    printf("Hello World\n");
    fprintf(fout, "Hello World�b�ɮ׸�\n");
}
