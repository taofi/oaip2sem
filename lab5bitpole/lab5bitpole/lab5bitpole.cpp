#include "stdafx.h"

int var4_1();
int var4_2();
int var6_1();
int var6_2();
int var5_1();
int var5_2();
int var16_1();
int var16_2();


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int action;
    do {
        cout << "варианты: 4 5 6 16" << endl;
        cin >> action;
        switch (action)
        {
       
        case 4:
            cin >> action;
            if (action == 1)
                var4_1();
            else
                var4_2();
            break;
        case 5:
            cin >> action;
            if (action == 1)
                var5_1();
            else
                var5_2();
            break;
        case 6:
            cin >> action;
            if (action == 1)
                var6_1();
            else
                var6_2();
            break;
        case 16:
            cin >> action;
            if (action == 1)
                var16_1();
            else
                var16_2();
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