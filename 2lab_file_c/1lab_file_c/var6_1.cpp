#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>


using namespace std;

int var6_1()
{
    setlocale(LC_ALL, "");
    errno_t err;
    FILE* fr;
    err = fopen_s(&fr, "fa.txt", "r");  //�������� ��� ������
    if (err != NULL)                 //�������� �������� �����
    {
        printf("������ �������� �����\n"); return -1;
    }
    int ch, a, minRaz = 0 , index = -1, i = 0;
    cout << "������� �����" << endl;
    cin >> ch;
    while (fscanf(fr, "%d ", &a) != EOF)
    {
        if (index == -1 || minRaz > abs(a - ch) )
        {
            index = i;
            minRaz = abs(a - ch);
        }
        i++;
    }
    cout << "������ ����� " << index << endl;
    fclose(fr);
    return 0;
}

