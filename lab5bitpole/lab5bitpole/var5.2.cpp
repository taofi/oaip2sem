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

union aval {
	bool b;
	char str[str_len];
};

struct LIBRARY
{
	unsigned typea: 4;
	char author[str_len];
	char name[str_len];
	char publishing[str_len];
	char section[str_len];
	int originType;
	aval availability;
	DATA data;
};
LIBRARY list_of_book2[size];
int bookSize2 = 0;


void coutLibHead2() {
	cout << "| номер |";
	cout << "|" << setw(str_len + 1) << "автор |";
	cout << "|" << setw(str_len + 1) << "название |";
	cout << "|" << setw(str_len + 1) << "издательство |";
	cout << "|" << setw(str_len + 1) << "раздел |";
	cout << "|" << setw(str_len + 1) << " происхождение |";
	cout << "| наличие |";
	cout << "| дата получени€ |" << endl;;
}
void coutLibBook2(int index) {
	cout << "| " << setw(5) << index << " |";
	cout << "|" << setw(str_len) << list_of_book2[index].author << "|";
	cout << "|" << setw(str_len) << list_of_book2[index].name << "|";
	cout << "|" << setw(str_len) << list_of_book2[index].publishing << "|";
	cout << "|" << setw(str_len) << list_of_book2[index].section << "|";
	switch (list_of_book2[index].originType)
	{
	case stolen:
		cout << "|" << setw(16) << "украдена|";
		break;
	case bought:
		cout << "|" << setw(16) << "куплена|";
		break;
	case given:
		cout << "|" << setw(16) << "подарок|";
		break;
	default:
		cout << "|неивестный тип|" << endl;
		break;
	}
	if (list_of_book2[index].typea == 1)
		cout << "|" << setw(8) << list_of_book2[index].availability.b << " |";
	else
		cout << "|" << setw(8) << list_of_book2[index].availability.str << " |";
	cout << "|   " << setfill('0') << setw(2) << list_of_book2[index].data.day << " " << setw(2) << list_of_book2[index].data.month << " " << setw(4) << list_of_book2[index].data.years << "   |" << setfill(' ') << endl;
}



void find2(char* tmp_char) {
	tmp_char = strtok(NULL, " ");
	cout << tmp_char << endl;
	int countF = 0;
	int m[size];
	for (int i = 0; i < bookSize2; i++)
	{
		if (!strcmp(tmp_char, list_of_book2[i].author))
		{
			m[countF++] = i;
		}
	}
	cout << "найдено: " << countF << endl;
	if (countF != 0) {
		coutLibHead2();
		for (int i = 0; i < countF; i++)
		{
			coutLibBook2(m[i]);
		}
	}
}
void outPut2(char* tmp_char) {
	tmp_char = strtok(NULL, " ");
	//cout << 1 << endl;
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (bookSize2 == 0)
			cout << "струтура пуста" << endl;
		else
		{
			coutLibHead2();
			for (int i = 0; i < bookSize2; i++)
				coutLibBook2(i);
		}
	}
	else 
	{
		char arr[str_len] = {};
		strcpy(arr, tmp_char);
		int index = strtoi(arr);
		if (index == -1)
		{
			cout << "введЄн неправельный номер книги" << endl;
		}
		else
		{
			if (index >= bookSize2)
			{
				cout << "максимальный индекс книги в струтуре: " << bookSize2 << endl;
			}
			else {
				coutLibHead2();
				coutLibBook2(index);
			}
		}
	}
}

void input2() {
	cout << "введите автора" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(list_of_book2[bookSize2].author);
	cout << "введите название" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(list_of_book2[bookSize2].name);
	cout << "введите издательство" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(list_of_book2[bookSize2].publishing);
	cout << "введите раздел" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(list_of_book2[bookSize2].section);
	cout << "введите дату: день мес€ц год" << endl;
	int n;
	cin >> n;
	if (n < 31)
		list_of_book2[bookSize2].data.day = n;
	cin >> n;
	if (n < 12)
		list_of_book2[bookSize2].data.month = n;
	cin >> n;
	if (n < 9999)
		list_of_book2[bookSize2].data.years = n;
	cout << "введите получение stolen = 1, given = 2, bought = 3" << endl;
	cin >> list_of_book2[bookSize2].originType;
	cout << "введите наличие bool - 1 str - 2" << endl;
	cin >> n;
	list_of_book2[bookSize2].typea = n;
	if (list_of_book2[bookSize2].typea == 1)
	{
		cin >> n;
		list_of_book2[bookSize2].availability.b = bool(n);
	}
	else
		cin >> list_of_book2[bookSize2].availability.str;
	bookSize2++;
}

int var5_2() {
	ifstream fin;
	ofstream fout;
	char buff[256];
	char *tmp_char;
	cout << "ƒл€ получени€ команд введите help" << endl;
	do {
		cout << "¬ведите команду" << endl;
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
			outPut2(tmp_char);
		else if (!strcmp(tmp_char, "find"))
			find2(tmp_char);
		else if (!strcmp(tmp_char, "input"))
			input2();
		else if (!strcmp(tmp_char, "exit"))
			cout << "выход" << endl;
		else
			cout << "неверна€ команда" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}

