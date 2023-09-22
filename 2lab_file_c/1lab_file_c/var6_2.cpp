#include <stdio.h>
#include <iostream>


using namespace std;

int var6_2()
{
    setlocale(LC_ALL, "");
    errno_t err;
    FILE* fr;
    err = fopen_s(&fr, "f1.txt", "r");  //Открытие для чтения
    if (err != NULL)                 //Проверка открытия файла
    {
        printf("Ошибка открытия файла\n"); return -1;
    }
    FILE* fw;
    err = fopen_s(&fw, "f2.txt", "w");
    if (err != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    int i = 1;
    char str[50];
    while (fgets(str, sizeof(str), fr) != NULL)
    {
        if (i % 2 == 0)
            fputs(str, fw); 
        i++;
    }
    printf("\nДанные записаны в файл f2.txt\n");
    fclose(fr);
    fclose(fw);
    return 0;
}

