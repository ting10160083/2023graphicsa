#include <stdio.h>
int main()
{
    FILE * fin = fopen("file.txt", "r");///�e�@�ӽd�Ҧ��g�ɤF

    char line[100];
    fscanf(fin, "%s", line);
    printf("�qfile.txtŪ��F: %s\n", line);

    fscanf(fin, "%s", line);
    printf("�qfile.txtŪ��F: %s\n", line);
}
