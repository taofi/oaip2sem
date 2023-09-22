#define _CRT_SECURE_NO_WARNINGS
#define strsize 26
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
struct Tree          //дерево
{
	int key;         //ключ
	int number;
	char surname[strsize];
	char tarif[strsize];
	Tree* Left, * Right;
};
char mostFrequentWord[strsize];
Tree* list(int key, char* s, char* s1, int numb);       //Создание нового элемента
void insert(Tree*& Root, Tree*& elem);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
void delAll(Tree* t);             //Очистка дерева
bool countRoot(Tree* t, int key, int count);
void countRight(Tree* t, int& count);
void countEven(Tree* t, int& count);
void showLevel(Tree* t, vector <pair<int, Tree*>>& tmpv, int count);


int c = 0;         //количество слов
Tree* Root = NULL; 	//указатель корня


struct WordComparator {
	bool operator()(const char* a, const char* b) const {
		return strcmp(a, b) < 0;
	}
};

void countWordFrequency(Tree* node, std::map<const char*, int, WordComparator>& wordFrequencies) {
	if (node == nullptr) {
		return;
	}

	countWordFrequency(node->Left, wordFrequencies);
	wordFrequencies[node->tarif]++;
	countWordFrequency(node->Right, wordFrequencies);
}

int maxIdenticalWords(Tree* root) {
	std::map<const char*, int, WordComparator> wordFrequencies;

	countWordFrequency(root, wordFrequencies);

	int maxCount = 0;
	for (const auto& wordFrequency : wordFrequencies) {
		if (wordFrequency.second > maxCount) {
			maxCount = wordFrequency.second;
			strncpy(mostFrequentWord, wordFrequency.first, strsize);
		}
	}

	return maxCount;
}
void help() {
	cout << "1 - добавление элемента key + text\n";
	cout << "2 - добавление элемента\n";
	cout << "3 - поиск по ключу\n";
	cout << "4 - удаление элемента\n";
	cout << "5 - вывод дерева\n";
	cout << "6 - подсчет количества букв\n";
	cout << "7 - очистка дерева\n";
	cout << "8 - вывод этой таблицы\n";
	cout << "10 - подсчет максимального количичства тарифа\n";
	cout << "11 - поиск по номеру\n";
	cout << "13 - выход\n";
}
void searchByNumber(Tree* t, int number) //Вывод дерева 
{
	if (t)
	{
		if (t->number == number)
		{
			std::cout << "key: " << t->key << std::endl;
			std::cout << "number: " << t->number << std::endl;
			std::cout << "surname: " << t->surname << std::endl;
			std::cout << "tarif: " << t->tarif << std::endl;
			return;
		}
		view(t->Right, number);	//вывод правого поддерева
		view(t->Left, number);	//вывод левого поддерева
	}
}
void main()
{
	setlocale(0, "Russian");
	vector <pair<int, Tree*>> tmpVect;
	Tree* foundNode;
	int key, choice, n, tmp, numb;
	Tree* rc; char s[25], letter, s2[25];
	Tree* elem;
	bool isFind;
	help();
	int maxCount;
	
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
			cin >> numb;
			cin >> s2;
			elem = list(key, s, s2, numb);
			elem = list(key, s, s2, numb);
			insert(Root, elem);
			break;
		case 2:  cout << "\nВведите ключ: "; cin >> key;
			cout << "Введите имя: "; cin >> s;
			cout << "Введите номер: "; cin >> numb;
			cout << "Введите тариф: "; cin >> s2;
			elem = list(key, s, s2, numb);
			insert(Root, elem);
			break;
		case 3:  cout << "\nВведите номер: ";  cin >> key;
			rc = search(Root, key);
			cout << "Найденный владелец= ";
			puts(rc->surname); break;
		case 4:  cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root->key >= 0)
		{
			cout << "Дерево повернуто на 90 град. влево" << endl;
			view(Root, 0);
		}
			  else cout << "Дерево пустое\n"; break;
		case 7:
			delAll(Root);
			Root = NULL;
			break;
		case 8:  help();  break;
		
		case 10:
			
			maxCount = maxIdenticalWords(Root);
			std::cout << "Самое часто встречающееся слово: " << mostFrequentWord << std::endl;
			std::cout << "Максимальное количество одинаковых тарифов: " << maxCount << std::endl;
			break;
		case 11:
			cin >> numb;
			searchByNumber(Root, numb);
			break;
		case 13:  exit(0);
		}
	}
}



Tree* list(int key, char* s, char* s1, int numb)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = key;
	strcpy(t->surname, s);
	strcpy(t->tarif, s);
	t->number = numb;
	t->Left = t->Right = NULL;
	return t;
}
void insert(Tree*& t, Tree*& elem) {
	if (t == NULL)              //если дерева нет, то создается элемент
	{
		t = elem;
		return;
	}
	if (t->key == elem->key)
	{
		cout << "ключ должен быть уникален" << endl;
		delete elem;
		return;
	}
	if (elem->key > t->key)  //дерево есть, если а больше текущего
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
		if (key < (key, n->number))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "Нет такого номера\n";
	return rc;
}


void view(Tree* t, int level) //Вывод дерева 
{
	if (t)
	{
		view(t->Right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ' << t->number << " "  << t->surname << " " << t->tarif;
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
		showLevel(t->Left, tmpv, count + 1);
		showLevel(t->Right, tmpv, count + 1);
	}
}