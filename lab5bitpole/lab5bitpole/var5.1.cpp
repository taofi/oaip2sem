#include "stdafx.h"
#define size 40
#define str_len 13

enum origin
{
	stolen = 1, given, bought
};

struct DATA
{
	unsigned month : 4;
	unsigned day : 6;
	unsigned years : 16;

};

struct LIBRARY
{
	char author[str_len];
	char name[str_len];
	char publishing[str_len];
	char section[str_len];
	int originType;
	bool availability;
	DATA data;
};
LIBRARY list_of_book[size];
int bookCount = 0;


void coutLibHead() {
	cout << "| ����� |";
	cout << "|" << setw(str_len + 1) << "����� |";
	cout << "|" << setw(str_len + 1) << "�������� |";
	cout << "|" << setw(str_len + 1) << "������������ |";
	cout << "|" << setw(str_len + 1) << "������ |";
	cout << "|" << setw(str_len + 1) << " ������������� |";
	cout << "| ������� |";
	cout << "| ���� ��������� |" << endl;;
}
void coutLibBook(int index) {
	cout << "| " << setw(5) << index << " |";
	cout << "|" << setw(str_len) << list_of_book[index].author << "|";
	cout << "|" << setw(str_len) << list_of_book[index].name << "|";
	cout << "|" << setw(str_len) << list_of_book[index].publishing << "|";
	cout << "|" << setw(str_len) << list_of_book[index].section << "|";
	switch (list_of_book[index].originType)
	{
	case stolen:
		cout << "|" << setw(16) << "��������|";
		break;
	case bought:
		cout << "|" << setw(16) << "�������|";
		break;
	case given:
		cout << "|" << setw(16) << "�������|";
		break;
	default:
		cout << "|���������� ���|" << endl;
		break;
	}
	cout << "|" << setw(8) << list_of_book[index].availability << " |";
	cout << "|   " << setfill('0') << setw(2) << list_of_book[index].data.day << " " << setw(2) << list_of_book[index].data.month << " " << setw(4) << list_of_book[index].data.years << "   |" << setfill(' ') << endl;
}



void find(char* tmp_char) {
	tmp_char = strtok(NULL, " ");
	cout << tmp_char << endl;
	int d = strtoi(tmp_char);
	int countF = 0;
	int m[size];
	for (int i = 0; i < bookCount; i++)
	{
		if (d == list_of_book[i].data.years)
		{
			m[countF++] = i;
		}
	}
	cout << "�������: " << countF << endl;
	if (countF != 0) {
		coutLibHead();
		for (int i = 0; i < countF; i++)
		{
			coutLibBook(m[i]);
		}
	}
}
void outPut(char* tmp_char) {
	tmp_char = strtok(NULL, " ");
	//cout << 1 << endl;
	if (tmp_char == NULL)
	{
		cout << "����������� ������� �������" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (bookCount == 0)
			cout << "�������� �����" << endl;
		else
		{
			coutLibHead();
			for (int i = 0; i < bookCount; i++)
				coutLibBook(i);
		}
	}
	else 
	{
		char arr[str_len] = {};
		strcpy(arr, tmp_char);
		int index = strtoi(arr);
		if (index == -1)
		{
			cout << "����� ������������ ����� �����" << endl;
		}
		else
		{
			if (index >= bookCount)
			{
				cout << "������������ ������ ����� � ��������: " << bookCount << endl;
			}
			else {
				coutLibHead();
				coutLibBook(index);
			}
		}
	}
}

void input() {
	cout << "������� ������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(list_of_book[bookCount].author);
	cout << "������� ��������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(list_of_book[bookCount].name);
	cout << "������� ������������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(list_of_book[bookCount].publishing);
	cout << "������� ������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(list_of_book[bookCount].section);
	cout << "������� ����: ���� ����� ���" << endl;
	int n;
	cin >> n;
	if (n < 31)
		list_of_book[bookCount].data.day = n;
	cin >> n;
	if (n < 12)
		list_of_book[bookCount].data.month = n;
	cin >> n;
	if (n < 9999)
		list_of_book[bookCount].data.years = n;
	cout << "������� ��������� stolen = 1, given = 2, bought = 3" << endl;
	cin >> list_of_book[bookCount].originType;
	bookCount++;
}

int var5_1() {
	ifstream fin;
	ofstream fout;
	char buff[256];
	char *tmp_char;
	cout << "��� ��������� ������ ������� help" << endl;
	do {
		cout << "������� �������" << endl;
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(buff);
		tmp_char = strtok(buff, " ");
		if (!strcmp(tmp_char, "help")) {
			cout << "input" << endl;
			cout << "output" << endl;
			cout << "find" << endl;
			cout << "exit" << endl;
		}
		else if (!strcmp(tmp_char, "output"))
			outPut(tmp_char);
		else if (!strcmp(tmp_char, "find"))
			find(tmp_char);
		else if (!strcmp(tmp_char, "input"))
			input();
		else if (!strcmp(tmp_char, "exit"))
			cout << "�����" << endl;
		else
			cout << "�������� �������" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}

