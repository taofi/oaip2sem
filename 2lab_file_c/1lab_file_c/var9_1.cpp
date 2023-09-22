#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>


using namespace std;

int var9_1()
{
    setlocale(LC_ALL, "");
    errno_t err;
    FILE* fr;
    err = fopen_s(&fr, "fileA9.txt", "r");  //Открытие для чтения
    if (err != NULL)                 //Проверка открытия файла
    {
        printf("Ошибка открытия файла\n"); return -1;
    }
    int n = 0;
    int mNum[50];
    while (fscanf(fr, "%d ", &mNum[n]) != EOF)
    {
        n++;
    }
    fclose(fr);
    bool isSame;
    int nNew = 0, mNew[50];
    for (int i = 0; i < n; i++)
    {
        isSame = false;
        for (int j = 0; j < nNew; j++)
        {
            if (mNum[i] == mNew[j])
            {
                isSame = true;
                break;
            }
        }
        if (!isSame)
        {
            mNew[nNew] = mNum[i];
            nNew++;
        }
    }
    FILE* fw;
    err = fopen_s(&fw, "fileB9.txt", "w");
    if (err != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < nNew; i++)
        fprintf(fw, "%d ", mNew[i]);
    printf("\nДанные записаны в файл fileB9.txt\n");
    fclose(fw);
    return 0;
}

