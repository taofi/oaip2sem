#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>


using namespace std;

int var16_2()
{
    setlocale(LC_ALL, "");
    errno_t err;
    FILE* fr;
    err = fopen_s(&fr, "file116.txt", "r");  //Открытие для чтения
    if (err != NULL)                 //Проверка открытия файла
    {
        printf("Ошибка открытия файла\n"); return -1;
    }
    int neg = 0, pos = 0;
    int mNeg[1000], mPos[1000], ch;
    while (fscanf(fr, "%d ", &ch) != EOF)
    {
        if (ch > 0)
            mPos[pos++] = ch;
        else
            mNeg[neg++] = ch;
    }
    
    fclose(fr);
    int n = neg + pos;
    neg = 0;
    pos = 0;
    int mNew[1000];
    for (int i = 0; i < n; i++)
    {
        if ((i / 10) % 2 == 0)
            mNew[i] = mPos[pos++];
        else
            mNew[i] = mNeg[neg++];
    }
    FILE* fw;
    err = fopen_s(&fw, "file216.txt", "w");
    if (err != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; i++)
    {
        cout << mNew[i] << " ";
        fprintf(fw, "%d ", mNew[i]);
    }
    printf("\nДанные записаны в файл file216.txt\n");
    fclose(fw);
    return 0;
}

