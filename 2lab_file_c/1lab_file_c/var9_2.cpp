#include <stdio.h>
#include <iostream>


using namespace std;

int var9_2()
{
    setlocale(LC_ALL, "");
    errno_t err;
    FILE* fr;
    err = fopen_s(&fr, "f19.txt", "r");  //Открытие для чтения
    if (err != NULL)                 //Проверка открытия файла
    {
        printf("Ошибка открытия файла\n"); return -1;
    }
    FILE* fw;
    err = fopen_s(&fw, "f29.txt", "w");
    if (err != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    int size, sizeOfStr;
    char str[50];
    cout << "введите число" << endl;
    cin >> size;
    while (fgets(str, sizeof(str), fr) != NULL)
    {
        if (strlen(str) > size)
            fputs(str, fw);
    }
    printf("\nДанные записаны в файл f29.txt\n");
    fclose(fr);
    fclose(fw);
    return 0;
}

