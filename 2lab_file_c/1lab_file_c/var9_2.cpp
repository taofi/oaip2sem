#include <stdio.h>
#include <iostream>


using namespace std;

int var9_2()
{
    setlocale(LC_ALL, "");
    errno_t err;
    FILE* fr;
    err = fopen_s(&fr, "f19.txt", "r");  //�������� ��� ������
    if (err != NULL)                 //�������� �������� �����
    {
        printf("������ �������� �����\n"); return -1;
    }
    FILE* fw;
    err = fopen_s(&fw, "f29.txt", "w");
    if (err != 0)
    {
        perror("���������� ������� ����\n");
        return EXIT_FAILURE;
    }
    int size, sizeOfStr;
    char str[50];
    cout << "������� �����" << endl;
    cin >> size;
    while (fgets(str, sizeof(str), fr) != NULL)
    {
        if (strlen(str) > size)
            fputs(str, fw);
    }
    printf("\n������ �������� � ���� f29.txt\n");
    fclose(fr);
    fclose(fw);
    return 0;
}

