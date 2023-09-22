#include "stdafx.h"

struct listInt7
{
	int numI;
	listInt7* next;
};

void input7(listInt7*& p, int digit);
void output7(listInt7* p);
void writeF7(char* tmp_char, ofstream& f, listInt7* p);
void readF7(char* tmp_char, ifstream& f, listInt7*& p);
void Delete7(listInt7*& p, char* tmp_char, listInt7*& lastp);
void findCh7(listInt7* p);
listInt7* first7 = nullptr;

int var7()
{
	setlocale(LC_CTYPE, "Russian");
	listInt7* tm = first7;
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
			output7(first7);
		else if (!strcmp(tmp_char, "input"))
			input7(tm, strtoi(strtok(NULL, " ")));
		else if (!strcmp(tmp_char, "delete"))
			Delete7(first7, strtok(NULL, " "), tm);
		else if (!strcmp(tmp_char, "readF"))
			readF7(tmp_char, fin, tm);
		else if (!strcmp(tmp_char, "writeF"))
			writeF7(tmp_char, fout, first7);
		else if (!strcmp(tmp_char, "find"))
			findCh7(first7);
		else if (!strcmp(tmp_char, "exit"))
		{
			char s[] = "all ";
			tmp_char = strtok(s, " ");
			Delete7(first7, tmp_char, tm);
			cout << "выход" << endl;
			return 0;
		}
		else
			cout << "неверная команда" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}

bool IsEmpty(listInt7* p)
{
	return p == NULL;
}

void Delete7(listInt7*& p, char* tmp_char, listInt7*& lastp) {
	listInt7* previous = p, * current, * next;
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

void output7(listInt7* p) {
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

void input7(listInt7*& p, int digit) {

	//cout << digit << endl;
	listInt7* pNew = new listInt7;
	if (p == NULL)
	{
		first7 = pNew;
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

void readF7(char* tmp_char, ifstream& f, listInt7*& p) {
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
		input7(p, digit);
		n++;
	}
	cout << "успешно прочитано " << n << " символов " << endl;
	f.close();
}
void writeF7(char* tmp_char, ofstream& f, listInt7* p) {
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

void findCh7(listInt7* p) {
	int n = 0;
	if (p == NULL)
	{
		cout << "Список пуст" << endl;
		return;
	}
	while (p->next != NULL) {
		if (p->numI % 10 == -3) {
			n += p->numI;
		}
		p = p->next;
	}
	if (p->numI % 10 == -3) {
		n += p->numI;
	}
	//cout << p->numI % 10 << endl;
	if (n != 0)
	{
		cout << "sum = " << n << endl;
	}
	else
		cout << "такиех чисел нет" << endl;
}