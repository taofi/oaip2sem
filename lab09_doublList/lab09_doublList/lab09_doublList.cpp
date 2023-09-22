﻿#include "stdafx.h"
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;



struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
//-----------------------------------------------------------
int menu(void)
{
	int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Запись в файл" << endl;
	cout << "6. Чтения файла" << endl;
	cout << "7. удаления К последних элементов" << endl;
	cout << "8. dop1" << endl;
	cout << "9. dop2" << endl;
	cout << "10. dop3" << endl;
	cout << "11. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		cin >> c;
	} while (c < 0 || c > 12);
	cin.ignore(cin.rdbuf()->in_avail());
	return c;
}
//-----------------------------------------------------------
void insert(Address* e, Address*& phead, Address*& plast) //Добавление в конец списка
{
	Address* p = plast;
	if (plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		plast = e;
		phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имен
{	struct Address *t = *phead;	
while (t)
{
	if (!strcmp(name, t->name))  break;
	t = t->next;
}
if (!t)
cerr << "Имя не найдено" << endl;
else
{
	if (*phead == t)
	{
		*phead = t->next;
		if (*phead)
			(*phead)->prev = NULL;
		else
			*plast = NULL;
	}
	else
	{
		t->prev->next = t->next;
		if (t != *plast)
			t->next->prev = t->prev;
		else
			*plast = t->prev;
	}
	delete t;
	cout << "Элемент удален" << endl;
}
}
//-----------------------------------------------------------
void writeToFile(Address** phead)       //Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
void readFromFile(Address*& phead, Address*& plast)          //Считывание из файла
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (phead)
	{
		plast = (phead)->next;
		delete phead;
		phead = plast;
	}
	phead = plast = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}

void deleteKLast(int k, Address*& phead, Address*& plast) {
	Address* t;
	for (int i = 0; i < k; i++)
	{
		t = plast;
		if (phead == t)
		{
			phead = t->next;
			if (phead)
				(phead)->prev = NULL;
			else
				plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != plast)
				t->next->prev = t->prev;
			else
				plast = t->prev;
		}
		delete t;
	}
	cout << "Элементы удалены" << endl;
}



int main(void)
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), head, last);
			break;
		case 2: {	  char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {	  char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}break;
		case 5:  writeToFile(&head);
			break;
		case 6: 
			readFromFile(head, last);
			break;
		case 7:
			int k;
			cout << "k=";
			cin >> k;
			deleteKLast(k, head, last);
			break;
		case 8:  
			dop1();
			break;
		case 9:
			dop2();
			break;
		case 10:  
			dop3();
			break;
		case 11:  exit(0);
			break;
		default: exit(1);
		}
	}
	return 0;
}

