#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>


using namespace std;

int var16_1()
{
    setlocale(LC_ALL, "");
    errno_t err;
    FILE* fra;
    err = fopen_s(&fra, "fileA16.txt", "r");  //�������� ��� ������
    if (err != NULL)                 //�������� �������� �����
    {
        printf("������ �������� �����\n"); return -1;
    }
    FILE* frb;
    err = fopen_s(&frb, "fileB16.txt", "r");  //�������� ��� ������
    if (err != NULL)                 //�������� �������� �����
    {
        printf("������ �������� �����\n"); return -1;
    }
   
    FILE* fw;
    err = fopen_s(&fw, "fileC16.txt", "w");
    if (err != 0)
    {
        perror("���������� ������� ����\n");
        return EXIT_FAILURE;
    }
    int a, b;
    while (fscanf(fra, "%d ", &a) != EOF) {
        fscanf(frb, "%d ", &b);
        fprintf(fw, "%d ", a + b);
    }
    printf("\n������ �������� � ���� fileC16.txt\n");
    fclose(fw);
    fclose(fra);
    fclose(frb);
    return 0;
}

