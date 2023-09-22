#include "stdafx.h"

struct listInt8
{
	int numI;
	listInt8* next;
};

void input8(listInt8*& p, int digit);
void output8(listInt8* p);
void writeF8(char* tmp_char, ofstream& f, listInt8* p);
void readF8(char* tmp_char, ifstream& f, listInt8*& p);
void Delete8(listInt8*& p, char* tmp_char, listInt8*& lastp);
void findCh8(listInt8* p);
listInt8* first8 = nullptr;

int var8()
{
	setlocale(LC_CTYPE, "Russian");
	listInt8* tm = first8;
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
			cout << "output" << endl;
			cout << "find" << endl;
			cout << "delete" << endl;
			cout << "writeF" << endl;
			cout << "readF" << endl;
			cout << "exit" << endl;
		}
		else if (!strcmp(tmp_char, "output"))
			output8(first8);
		else if (!strcmp(tmp_char, "input"))
			input8(tm, strtoi(strtok(NULL, " ")));
		else if (!strcmp(tmp_char, "delete"))
			Delete8(first8, strtok(NULL, " "), tm);
		else if (!strcmp(tmp_char, "readF"))
			readF8(tmp_char, fin, tm);
		else if (!strcmp(tmp_char, "writeF"))
			writeF8(tmp_char, fout, first8);
		else if (!strcmp(tmp_char, "find"))
			findCh8(first8);
		else if (!strcmp(tmp_char, "exit"))
		{
			char s[] = "all ";
			tmp_char = strtok(s, " ");
			Delete8(first8, tmp_char, tm);
			cout << "выход" << endl;
			return 0;
		}
		else
			cout << "неверная команда" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}

bool IsEmpty(listInt8* p)
{
	return p == NULL;
}

void Delete8(listInt8*& p, char* tmp_char, listInt8*& lastp) {
	listInt8* previous = p, * current, * next;
	if (!strcmp(tmp_char, "all")) {
		while (previous->next != NULL)
		{
			current = previous->next;
			next = current->next;
			delete current;
			previous->next = next;
		}
		delete previous;
		p = nullptr;
		lastp = p;
	}
	else {
		int digit = strtoi(tmp_char);
		if (digit == -1)
			return;
		int n = strtoi(strtok(NULL, " "));
		while (previous->numI == digit && n != 0 && previous->next != NULL)
		{
			n--;
			p = previous->next;
			delete previous;
			previous = p;
		}
		while (previous->next != NULL)
		{
			if (previous->next->numI == digit && n != 0)
			{
				current = previous->next;
				next = current->next;
				delete current;
				previous->next = next;
				n--;
			}
			else
				previous = previous->next;
		}
	}
}

void output8(listInt8* p) {
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << p->numI << " ";
			p = p->next;
		}
		cout << "\n";
	}

}

void input8(listInt8*& p, int digit) {
	
	//cout << digit << endl;
	listInt8* pNew = new listInt8;
	if (p == NULL)
	{
		first8 = pNew;
		pNew->numI = digit;
		p = pNew;
		p->next = NULL;
	}
	else if (pNew != NULL)
	{
		pNew->numI = digit;
		p->next = pNew;
		p = pNew;
		p->next = NULL;
	}
	else
		cout << "Операция добавления не выполнена" << endl;

}

void readF8(char* tmp_char, ifstream& f, listInt8*& p) {
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
		input8(p, digit);
		n++;
	}
	cout << "успешно прочитано " << n << " символов " << endl;
	f.close();
}
void writeF8(char* tmp_char, ofstream& f, listInt8* p) {
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
			f << p->numI << " ";
			p = p->next;
		}
	}
	cout << "записано в файл " << tmp_char << endl;
	f.close();
}

void findCh8(listInt8* p) {
	int n = 0;
	while (p->next != NULL) {
		if (p->numI < 0 && p->numI % 2 == 0) {
			n += p->numI;
		}
		p = p->next;
	}
	if (n != 0)
	{
		cout << "sum = " << n << endl;
	}
	else
		cout << "такиех чисел нет" << endl;
}