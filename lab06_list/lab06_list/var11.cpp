#include "stdafx.h"

struct listChar11
{
	char sim;
	listChar11* next;
};

void input11(listChar11*& p, char* tmp_char);
void output11(listChar11* p);
void writeF11(char* tmp_char, ofstream& f, listChar11* p);
void readF11(char* tmp_char, ifstream& f, listChar11*& p);
void Delete11(listChar11*& p, char* tmp_char, listChar11*& lastp);
void findCh11(listChar11* p, char* tmp_char);
listChar11* first11 = nullptr;

int var11()
{
	setlocale(LC_CTYPE, "Russian");
	listChar11* tm = first11;
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
			output11(first11);
		else if (!strcmp(tmp_char, "input"))
			input11(tm, strtok(NULL, " "));
		else if (!strcmp(tmp_char, "delete"))
			Delete11(first11, strtok(NULL, " "), tm);
		else if (!strcmp(tmp_char, "readF"))
			readF11(tmp_char, fin, tm);
		else if (!strcmp(tmp_char, "writeF"))
			writeF11(tmp_char, fout, first11);
		else if (!strcmp(tmp_char, "find"))
			findCh11(first11, strtok(NULL, " "));
		else if (!strcmp(tmp_char, "exit"))
		{
			char s[] = "all ";
			tmp_char = strtok(s, " ");
			Delete11(first11, tmp_char, tm);
			cout << "выход" << endl;
			return 0;
		}
		else
			cout << "неверная команда" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}

bool IsEmpty(listChar11* p)
{
	return p == NULL;
}

void Delete11(listChar11*& p, char* tmp_char, listChar11*& lastp) {
	listChar11* previous = p, * current, * next;
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
		char ch = tmp_char[0];
		//cout << ch << endl;
		int n = strtoi(strtok(NULL, " "));
		while (previous->sim == ch && n != 0 && previous->next != NULL)
		{
			n--;
			p = previous->next;
			delete previous;
			previous = p;
		}
		while (previous->next != NULL)
		{
			if (previous->next->sim == ch && n != 0)
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

void output11(listChar11* p) {
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->sim;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}

}

void input11(listChar11*& p, char* tmp_char) {
	char ch = tmp_char[0];
	if (ch == '#')
		return;
	listChar11* pNew = new listChar11;
	if (p == NULL)
	{
		first11 = pNew;
		pNew->sim = ch;
		p = pNew;
		p->next = NULL;
	}
	else if (pNew != NULL)
	{
		pNew->sim = ch;
		p->next = pNew;
		p = pNew;
		p->next = NULL;
	}
	else
		cout << "Операция добавления не выполнена" << endl;

}

void readF11(char* tmp_char, ifstream& f, listChar11*& p) {
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
	char str[256] = {};
	f.getline(str, 256);
	strcat(str, "\n\n\n");
	char* pch = &str[0];
	int n = 0;
	while (*pch != '\n') {
		//cout << *pch << endl;
		input11(p, pch);
		pch += 2;
		n++;
	}
	cout << "успешно прочитано " << n << " символов " << endl;
	f.close();
}
void writeF11(char* tmp_char, ofstream& f, listChar11* p) {
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
			f << p->sim << " ";
			p = p->next;
		}
	}
	cout << "записано в файл " << tmp_char << endl;
	f.close();
}

void findCh11(listChar11* p, char* tmp_char) {
	char ch = tmp_char[0];
	while (p->next != NULL) {
		if (p->next->sim == ch) {
			cout << p->sim << " " << p->next->sim << endl;
			return;
		}
		p = p->next;
	}
}