#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>


using namespace std;

int var4_1()
{
    std::system("chcp 65001");
    //setlocale(LC_ALL, "");
    errno_t err;
    FILE* fr;
    err = fopen_s(&fr, "fileA.txt", "r");  //Открытие для чтения
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
    wchar_t wc = L'❅';
    cout << wc << endl;
    fclose(fr);
    FILE* fw;
    err = fopen_s(&fw, "fileB.txt", "w");
    if (err != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < pos; i++)
        fprintf(fw, "%d %d ", mPos[i], mNeg[i]);
    printf("\nДанные записаны в файл fileB.txt\n");
    fclose(fw);
    return 0;
}

