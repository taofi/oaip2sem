#include <iostream>
#include <vector>
#include <algorithm>
#define strsize 26
using namespace std;
struct Tree          //дерево
{
	int key;         //ключ
	char text[strsize];
	Tree* Left, * Right;
};

Tree* list(int i, char* s);       //Создание нового элемента
void insert(Tree*& Root, Tree *&elem);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
int count(Tree* t, char letter);  //Подсчет количества слов
void delAll(Tree* t);             //Очистка дерева
bool countRoot(Tree* t, int key, int count);
void countRight(Tree* t, int& count);
void countEven(Tree* t, int& count);
void showLevel(Tree* t, vector <pair<int, Tree*>> & tmpv, int count);


int c = 0;         //количество слов
Tree* Root = NULL; 	//указатель корня

void help() {
	cout << "1 - добавление элемента key + text\n";
	cout << "2 - добавление элемента\n";
	cout << "3 - поиск по ключу\n";
	cout << "4 - удаление элемента\n";
	cout << "5 - вывод дерева\n";
	cout << "6 - подсчет количества букв\n";
	cout << "7 - очистка дерева\n";
	cout << "8 - вывод этой таблицы\n";
	cout << "9 - число ветвей от корня до вершины\n";
	cout << "10 - число правых дочерних вершин 2\n";
	cout << "11 - число четныйх вершин 12\n";
	cout << "12 - вывод по уровням\n";
	cout << "13 - выход\n";
}

void main()
{
	setlocale(0, "Russian");
	vector <pair<int, Tree*>> tmpVect;
	int key, choice, n, tmp;
	Tree* rc; char s[5], letter;
	Tree* elem;
	bool isFind;
	help();
	for (;;)
	{
		
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1: 
			cin >> key;
			cin >> s;
			elem = list(key, s);
			insert(Root, elem);
			break;
		case 2:  cout << "\nВведите ключ: "; cin >> key;
			cout << "Введите слово: "; cin >> s;
			elem = list(key, s);
			insert(Root, elem);
			break;
		case 3:  cout << "\nВведите ключ: ";  cin >> key;
			rc = search(Root, key);
			cout << "Найденное слово= ";
			puts(rc->text); break;
		case 4:  cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root->key >= 0)
		{
			cout << "Дерево повернуто на 90 град. влево" << endl;
			view(Root, 0);
		}
			  else cout << "Дерево пустое\n"; break;
		case 6:  cout << "\nВведите букву: "; cin >> letter;
			n = count(Root, letter);
			cout << "Количество слов, начинающихся с буквы " << letter;
			cout << " равно " << n << endl; break;
		case 7:  
			delAll(Root);
			Root = NULL;
			break;
		case 8:  help();  break;
		case 9:
			cout << "\nВведите ключ: ";  cin >> key;
			isFind = countRoot(Root, key, 0);
			if (!isFind)
				cout << "не найден ключ" << endl;
			break;
		case 10:
			tmp = 0;
			countRight(Root, tmp);
			cout << "количество правых ветвей: " << tmp << endl;
			break;
		case 11:
			tmp = 0;
			countEven(Root, tmp);
			cout << "количество четныйх ключей: " << tmp << endl;
			break;
		case 12:  
			showLevel(Root, tmpVect, 0);
			sort(tmpVect.begin(), tmpVect.end());
			if (tmpVect.size() == 0)
				break;
			cout << "корень:" << tmpVect[0].second->key << " " << tmpVect[0].second->text << endl;
			for (int i = 1; i < tmpVect.size(); i++)
			{
				if (tmpVect[i].first != tmpVect[i - 1].first)
					cout << "уровень " << tmpVect[i].first << ":\n";
				cout << tmpVect[i].second->key << " " << tmpVect[i].second->text << endl;
			}

			break;
		case 13:  exit(0);
		}
	}
}



Tree* list(int key, char* s)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = key;
	t->Left = t->Right = NULL;
	return t;
}
void insert(Tree *&t, Tree *&elem) {
	if (t == NULL)              //если дерева нет, то создается элемент
	{
		t = elem;
		return;
	}
	if (t->key == elem -> key)
	{
		cout << "ключ должен быть уникален" << endl;
		delete elem;
		return;
	}
	if (elem -> key > t->key)  //дерево есть, если а больше текущего
		insert(t->Right, elem);  //то элемент помещается вправо
	else
		insert(t->Left, elem);   //иначе - влево

}

Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь 
		else
			Prev_Del->Right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}

int count(Tree* t, char letter) //Подсчет количества слов
{
	if (t)
	{
		count(t->Right, letter);
		if (*(t->text) == letter)
			c++;
		count(t->Left, letter);
	}
	return c;
}

void view(Tree* t, int level) //Вывод дерева 
{
	if (t)
	{
		view(t->Right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		puts(t->text);
		view(t->Left, level + 1);	//вывод левого поддерева
	}
}

void delAll(Tree* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

bool countRoot(Tree* t, int key, int count) 
{
	if (t != NULL)
	{
		if (key == t->key)
		{
			cout << "количество ветвей: " << count << endl;
			return true;
		}
		if (key < t->key)
			return countRoot(t->Left, key, count + 1);
		else
			return countRoot(t->Right, key, count + 1);
	}
	return false;
}

void countRight(Tree* t, int& count) {
	if (t != NULL)
	{
		if (t->Right != NULL)
		{
			count++;
			countRight(t->Right, count);
		}
		countRight(t->Left, count);
	}
}

void countEven(Tree* t, int& count) {
	if (t != NULL)
	{
		if (t->key % 2 == 0)
			count++;
		countRight(t->Right, count);
		countRight(t->Left, count);
	}
}

void showLevel(Tree* t, vector <pair<int, Tree*>>& tmpv, int count)
{
	if (t != NULL)
	{
		tmpv.push_back(make_pair(count, t));
		showLevel(t->Left, tmpv, count+1);
		showLevel(t->Right, tmpv, count+1);
	}
}