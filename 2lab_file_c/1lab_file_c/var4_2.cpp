#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>


using namespace std;

int var4_2()
{
    setlocale(LC_ALL, "");
    errno_t err;
    FILE* fr;
    err = fopen_s(&fr, "f.txt", "r");  //Открытие для чтения
    if (err != NULL)                 //Проверка открытия файла
    {
        printf("Ошибка открытия файла\n"); return -1;
    }
    FILE* fw;
    err = fopen_s(&fw, "g.txt", "w");
    if (err != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    int ch, a;
    cout << "введите число" << endl;
    cin >> ch;
    while (fscanf(fr, "%d ", &a) != EOF)
    {
        if(a > ch)
            fprintf(fw, "%d ", a);
    }
    printf("\nДанные записаны в файл g.txt\n");
    fclose(fr);
    fclose(fw);
    return 0;
}

