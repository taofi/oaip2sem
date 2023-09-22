#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>

using namespace std;


void ShakerSort(int* a, int n) {
    int left, right, i;
    left = 1;
    right = n - 1;
    while (left <= right) {
        for (i = right; i >= left; i--) {
            if (a[i - 1] < a[i]) {
                swap(a[i - 1], a[i]);
            }
        }
        left++;
        for (i = left; i <= right; i++) {
            if (a[i - 1] < a[i]) {
                swap(a[i - 1], a[i]);
            }
        }
        right--;
    }
}
void Shell(int *A, int n) {
    int d = n;
    int count;
    d = d / 2;
    int j = 0;
    while (d > 0) {
        for (int i = 0; i < n - d; i++) {
            j = i;
            while (j >= 0 && A[j] < A[j + d]) {
                count = A[j];
                A[j] = A[j + d];
                A[j + d] = count;
                j--;
            }
        }
        d = d / 2;
    }
}

void insertSort(int *a, int N) {
    int buff, j;
    for (int i = 1; i < N; i++) {
        buff = a[i];
        for (j = i - 1; j >= 0 && a[j] < buff; j--)
            a[j + 1] = a[j];

        a[j + 1] = buff;
    }

}


void buS(int *a, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }

}



void buS2(int* a, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }

}

void viborSort(int* a, int N) {
    int min, buf;
    for (int i = 0; i < N; i++) {
        min = i;

        for (int j = i + 1; j < N; j++)
            min = (a[j] < a[min]) ? j : min;

        if (i != min) {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }

}


void hoarasort(int* a, int first, int last)
{

    int i = first, j = last;
    int tmp, x = a[(first + last) / 2];

    do {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;

        if (i <= j)
        {
            if (i > j)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        hoarasort(a, i, last);
    if (first < j)
        hoarasort(a, first, j);
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int a[100];
    int b[100];
    int c1[100];
    int c2[100];
    int n = 20;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
        cout << a[i] << " ";
    }
    cout << "\n\n";
    int Min = 999999;
    for (int i = 0; i < n; i++)
    {
        b[i] = rand() % 1000;
        Min = min(Min, b[i]);
        cout << b[i] << " ";
    }
    cout << "\n\n";
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > Min)
        {
            c1[k] = c2[k] = a[i];
            k++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << c1[i] << " ";
    }
    cout << "\n\n\nшейкерная \n";
    ShakerSort(c1, k);
    for (int i = 0; i < k; i++)
    {
        cout << c1[i] << " ";
    }
    cout << "\n\n\nШелла\n";
    Shell(c2, k);
    for (int i = 0; i < k; i++)
    {
        cout << c2[i] << " ";
    }

    cout << "\nVar1\n\na\n";
    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
        cout << a[i] << " ";
    }
    cout << "\n\n";
    int b1[50];
    int b2[50];
    k = 0;
    for (int i = 0; i < n; i+=2) {
        b1[k] = b2[k] = a[i];
        k++;
    }
    cout << "пузырек\n";
    buS(b1, k);
    for (int i = 0; i < k; i++)
    {
        cout << b1[i] << " ";
    }
    cout << "\n\nвставкой\n";
    insertSort(b2, k);
    for (int i = 0; i < k; i++)
    {
        cout << b2[i] << " ";
    }

    int c3[50];
    int c4[50];
    cout << "\n var5\n";
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
        cout << a[i] << " ";
    }
    cout << "\n\n";
   


    for (int i = 0; i < n; i++)
    {
        b[i] = rand() % 1000;
        Min = min(Min, b[i]);
        cout << b[i] << " ";
    }
    cout << "\n\n";
    k = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]%2 == 0)
        {
            c3[k] = c4[k] = a[i];
            k++;
        }
        if (b[i] % 2 != 0)
        {
            c3[k] = c4[k] = b[i];
            k++;
        }
    }
    cout << "\n\nпузырек\n";
    buS2(c3, k);
    for (int i = 0; i < k; i++)
    {
        cout << c3[i] << " ";
    }
    cout << "\n\nвыбор\n";
    viborSort(c4, k);
    for (int i = 0; i < k; i++)
    {
        cout << c4[i] << " ";
    }

    cout << "\n var3\n";
    int Max = -1, index = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
        cout << a[i] << " ";
        if (Max < a[i]) {
            Max = a[i];
            index = i;
        }
    }
    cout << "\n\n";
    int b3[50], b4[50];
    k = 0;
    for (int i = index; i < n; i+=2) {
        b3[k] = b4[k] = a[i];
        k++;
    }

    cout << "\n\n\n";

    cout << "\n\nпузырек\n";
    buS(b3, k);
    for (int i = 0; i < k; i++)
    {
        cout << b3[i] << " ";
    }
    cout << "\n\nХоара\n";
    hoarasort(b4, 0, k - 1);
    for (int i = 0; i < k; i++)
    {
        cout << b4[i] << " ";
    }
}


