#include <stdio.h>
#include <iostream>

using namespace std;

int var4_1();
int var4_2();

int var6_1();
int var6_2();

int var9_1();
int var9_2();

int var16_1();
int var16_2();

int main()
{
    setlocale(LC_ALL, "rus");
    int action;
    do {
        cin >> action;
        switch (action) {
        case 4:
            cout << "номер задания (1 2)" << endl;
            cin >> action;
            if (action == 1)
                var4_1();
            else
                var4_2();
            break;
        case 6:
            cout << "номер задания (1 2)" << endl;
            cin >> action;
            if (action == 1)
                var6_1();
            else
                var6_2();
            break;
        case 9:
            cout << "номер задания (1 2)" << endl;
            cin >> action;
            if (action == 1)
                var9_1();
            else
                var9_2();
            break;
        case 16:
            cout << "номер задания (1 2)" << endl;
            cin >> action;
            if (action == 1)
                var16_1();
            else
                var16_2();
            break;
        }
    } while (action != -1);
    return 0;
}

