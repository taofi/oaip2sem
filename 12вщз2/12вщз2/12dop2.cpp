#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
struct El
{
	int data;
	El* left;
	El* right;
};
struct Tree          
{
	int key;    
	Tree* Left, * Right;
};
Tree* Root = NULL;

El* root = NULL;

El* CreateEl(int data)
{
	El* interm = new El[sizeof(El)];
	interm->data = data;
	interm->left = interm->right = NULL;
	return interm;
}

void view(El* t, int level) //Вывод дерева 
{
	if (t)
	{
		view(t->right, level + 1);  //вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->data;
		cout << tm << ' ' << endl;
		view(t->left, level + 1);  //вывод левого поддерева
	}
}

El* f(El* rt, int n, int count)
{
	static int loop = 0, data = 0;
	loop++; data++;

	if (loop <= n)
	{
		if (root == NULL && count == 0)
		{
			root = CreateEl(data);
			++count;
			f(root, n, count);
			return root;
		}
		else if (count == 1)
		{
			rt->left = CreateEl(data);
			++count;
			f(rt, n, count);
		}
		else if (count == 2)
		{
			--count;
			rt->right = CreateEl(data);
			f(rt->right, n, count);
		}
	}
}




int main()
{
	setlocale(LC_ALL, "rus");
	int n = 0;
	cout << "Введите число N (количество вершин) > "; cin >> n;
	root = f(root, n, 0);
	view(root, 0);
}