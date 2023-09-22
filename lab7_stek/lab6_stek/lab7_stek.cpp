#include "stdafx.h"

using namespace std;

struct STACK
{
    int data;
    STACK* next;
};

int pop(STACK* &st);
void push(STACK*& st, int d);
void clear(STACK*& st);
void writeF(char* tmp_char, ofstream& f, STACK* p);
void readF(char* tmp_char, ifstream& f, STACK*& p);
void findS(STACK* st);
void countS(STACK* st);
void dop1();
void dop2(char* tmp_char, ifstream& f, STACK*& p);
void showStack(STACK* st);
void findMin(STACK* st);

int main()
{
    setlocale(LC_ALL, "rus");
    STACK* p = nullptr;
	ifstream fin;
	ofstream fout;
	char buff[256];
	char* tmp_char;
	cout << "Для получения команд введите help" << endl;
	do {
		cout << "Введите команду" << endl;
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(buff);
		strcat(buff, " #/n");
		tmp_char = strtok(buff, " ");
		if (!strcmp(tmp_char, "help")) {
			cout << "input" << endl;
			cout << "pop" << endl;
			cout << "findS" << endl;
			cout << "countS" << endl;
			cout << "clear" << endl;
			cout << "writeF" << endl;
			cout << "readF" << endl;
			cout << "dop1" << endl;
			cout << "exit" << endl;
		}
		else if (!strcmp(tmp_char, "pop"))
			pop(p);
		else if (!strcmp(tmp_char, "push"))
			push(p, strtoi(strtok(NULL, " ")));
		else if (!strcmp(tmp_char, "clear"))
			clear(p);
		else if (!strcmp(tmp_char, "readF"))
			readF(tmp_char, fin, p);
		else if (!strcmp(tmp_char, "writeF"))
			writeF(tmp_char, fout, p);
		else if (!strcmp(tmp_char, "findS"))
			findS(p);
		else if (!strcmp(tmp_char, "countS"))
			countS(p);
		else if (!strcmp(tmp_char, "dop1"))
			dop1();
		else if (!strcmp(tmp_char, "dop2"))
			dop2(tmp_char, fin, p);
		else if (!strcmp(tmp_char, "show"))
			showStack(p);
		else if (!strcmp(tmp_char, "exit"))
		{
			clear(p);
			cout << "выход" << endl;
			return 0;
		}
		else
			cout << "неверная команда" << endl;
	} while (strcmp(tmp_char, "exit"));
}

int pop(STACK*& st) 
{
	if (st != NULL)
	{
		int tmp = st->data;
		STACK* pv = st;
		st = st->next;
		delete pv;
		cout << tmp << endl;
		return tmp;
	}
	else
	{
		cout << "пусто" << endl;
		return 0;
	}
	
}

void push(STACK*& st, int d)
{
	STACK* pv = new STACK;
	pv->data = d;      
	pv->next = st;
	st = pv;
}

void findS(STACK* st) {
	if (st == NULL)
	{
		cout << "пустo" << endl;
		return;
	}
	bool isFindSame = false;
	while (st-> next != NULL && st != NULL)
	{
		if (st->data == st->next->data)
			isFindSame = true;
		st = st->next;
	}
	if (isFindSame)
		cout << "есть" << endl;
	else
		cout << "нету" << endl;
}

void countS(STACK* st) {
	if (st == NULL)
	{
		cout << "пустo" << endl;
		return;
	}
	int amount = 0;
	while (st->next != NULL)
	{
		if (st->data == st->next->data)
			amount++;
		st = st->next;
	}
	cout << "количество равных соседий: " << amount << endl;
}

void clear(STACK*& st) {
	STACK* pv = st;
	while(st != NULL) {
		pv = st;
		st = st->next;
		delete pv;
	}
	cout << "очищено" << endl;
}

void readF(char* tmp_char, ifstream& f, STACK*& p) {
	tmp_char = strtok(NULL, " ");
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	f.open(tmp_char);
	if (f.fail())
	{
		cout << "\n Ошибка открытия файла";
		return;
	}
	int digit, n = 0;
	while (f >> digit) {
		push(p, digit);
		n++;
	}
	cout << "успешно прочитано " << n << " чисел " << endl;
	f.close();
}

void writeF(char* tmp_char, ofstream& f, STACK* p) {
	tmp_char = strtok(NULL, " ");
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	f.open(tmp_char);
	if (f.fail())
	{
		cout << "\n Ошибка открытия файла";
		return;
	}
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			f << p->data << " ";
			p = p->next;
		}
	}
	cout << "записано в файл " << tmp_char << endl;
	f.close();
}


void dop1() {
	STACK* dop1 = nullptr;
	char str[256], str2[256];
	int n;
	cout << "введте строку" << endl;
	cin >> str;
	n = strlen(str);
	if (n % 2 != 0)
	{
		cout << "неверная строка" << endl;
		return;
	}
	int i = 0;
	while (str[i] != '\0')
	{
		push(dop1, int(str[i]));
		i++;
	}
	//showStack(dop1);
	for (int j = n / 2; j < n; j++)
		str2[j] = char(pop(dop1));
	for(int j = 0; j < n/2; j ++)
		str2[j] = char(pop(dop1));
	str2[n] = '\0';
	cout << str2 << endl;
}

void dop2(char* tmp_char, ifstream& f, STACK*& p) {
	tmp_char = strtok(NULL, " ");
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	f.open(tmp_char);
	if (f.fail())
	{
		cout << "\n Ошибка открытия файла";
		return;
	}
	STACK* pdop2 = nullptr;
	char str[256];
	while (f.getline(str, 256)) {
		cout << str << endl;
		push(pdop2, strlen(str));
	}
	showStack(pdop2);
	findMin(pdop2);
	f.close();
}


void showStack(STACK* st) {
	if (st == NULL)
	{
		cout << "пустo" << endl;
		return;
	}
	int n = 0;
	while (st != NULL)
	{
		cout << n << " " << st->data << endl;
		n++;
		st = st->next;
	}
}


void findMin(STACK* st) {
	if (st == NULL)
	{
		cout << "пустo" << endl;
		return;
	}
	int minSize = st->data, index = 0;
	int n = 1;
	st = st->next;
	while (st != NULL)
	{
		if (minSize >= st->data)
		{
			index = n;
			minSize = st->data;
		}
		n++;
		st = st->next;
	}
	cout << "index = " << index << " minSize = " << minSize << endl;
}