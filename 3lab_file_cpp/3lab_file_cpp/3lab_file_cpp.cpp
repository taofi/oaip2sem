#include <iostream>

using namespace std;

void var4_1();
void var4_2();

void var7_1();
void var7_2();

void var9_1();
void var9_2();

void var11_1();
void var11_2();

int main()
{
    setlocale(0, "Rus");
    int action;
    do {
        cin >> action;
        switch (action)
        {
        case 4:
            cout << "номер задания (1 2)" << endl;
            cin >> action;
            if (action == 1)
                var4_1();
            else
                var4_2();
            break;
        case 7:
            cout << "номер задания (1 2)" << endl;
            cin >> action;
            if (action == 1)
                var7_1();
            else
                var7_2();
            break;
        case 9:
            cout << "номер задания (1 2)" << endl;
            cin >> action;
            if (action == 1)
                var9_1();
            else
                var9_2();
            break;
        case 11:
            cout << "номер задания (1 2)" << endl;
            cin >> action;
            if (action == 1)
                var11_1();
            else
                var11_2();
            break;
        }
    } while (action != -1);
}