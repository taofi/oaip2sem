#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>


using namespace std;

int var4_2()
{
    setlocale(LC_ALL, "");
    errno_t err;
    FILE* fr;
    err = fopen_s(&fr, "f.txt", "r");  //�������� ��� ������
    if (err != NULL)                 //�������� �������� �����
    {
        printf("������ �������� �����\n"); return -1;
    }
    FILE* fw;
    err = fopen_s(&fw, "g.txt", "w");
    if (err != 0)
    {
        perror("���������� ������� ����\n");
        return EXIT_FAILURE;
    }
    int ch, a;
    cout << "������� �����" << endl;
    cin >> ch;
    while (fscanf(fr, "%d ", &a) != EOF)
    {
        if(a > ch)
            fprintf(fw, "%d ", a);
    }
    printf("\n������ �������� � ���� g.txt\n");
    fclose(fr);
    fclose(fw);
    return 0;
}

