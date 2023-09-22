#include "stdafx.h"

int var4();
void dop1();
void dop2();
void dop3();

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int action;
    do {
        cout << "варианты:1 2 3 4" << endl;
        cin >> action;
        switch (action)
        {
        case 1:
            dop1();
            break;
        case 2:
            dop2();
            break;
        case 3:
            dop3();
            break;
        case 4:
            var4();
            break;
        case -1: 
            cout << "выход" << endl;
            break;
        default:cout << "неверный вариант" << endl;
            break;
        }
    } while (action != -1);
    return 0;
}