#include "stdafx.h"
struct DATA
{
	unsigned month : 4;
	unsigned day : 6;
	unsigned years : 16;

};
int countEX = 0;
struct bank_schet
{
	char examen[strsize];
	char fam[strsize];
	DATA data;
}listEx[120];

void coutExHead() {
	cout << "| индекс |";
	cout << "|" << setw(strsize + 1) << "фамили€ |";
	cout << "|" << setw(strsize + 1) << "экзамен |";
	cout << "| дата экзамена |" << endl;
}

void coutEx(int index) {
	cout << "| " << setw(6) << index << " |";
	cout << "|" << setw(strsize) << listEx[index].fam << "|";
	cout << "|" << setw(strsize) << listEx[index].examen << "|";
	cout << "|  " <<setfill('0') << setw(2) << listEx[index].data.day << " " << setw(2) << listEx[index].data.month << " " << setw(4) << listEx[index].data.years << "   |" << setfill(' ');
	cout << endl;
}



void inputEx() {
	cout << "введите фамилию" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listEx[countEX].fam);
	cout << "введите экзамен" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listEx[countEX].examen);
	cout << "введите дату: день мес€ц год" << endl;
	int n;
	cin >> n;
	if (n < 31)
		listEx[countEX].data.day = n;
	cin >> n;
	if(n < 12)
	listEx[countEX].data.month = n;
	cin >> n;
	if(n < 9999)
		listEx[countEX].data.years = n;
	countEX++;
}

void outputEx(char *tmp_char) {
	tmp_char = strtok(NULL, " ");
	//cout << 1 << endl;
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (countEX == 0)
			cout << "струтура пуста" << endl;
		else
		{
			coutExHead();
			for (int i = 0; i < countEX; i++)
				coutEx(i);
		}
	}
	else
	{
		char arr[strsize] = {};
		strcpy(arr, tmp_char);
		int index = strtoi(arr);
		if (index == -1)
		{
			cout << "введЄн неправельный номер книги" << endl;
		}
		else
		{
			if (index >= countEX)
			{
				cout << "максимальный индекс книги в струтуре: " << countEX << endl;
			}
			else {
				coutExHead();
				coutEx(index);
			}
		}
	}
}

void findEx() {
	int m[120];
	int d, mm, y;
	cout << "введите дату: день мес€ц год" << endl;
	cin >> d >> mm >> y;
	int countF = 0;
	for (int i = 0; i < countEX; i++)
	{
		if (listEx[i].data.day == d && listEx[i].data.month == mm && listEx[i].data.years == y)
			m[countF++] = i;
	}
	cout << "найдено: " << countF << endl;
	if (countF != 0) {
		coutExHead();
		for (int i = 0; i < countF; i++)
		{
			coutEx(m[i]);
		}
	}
}



int var16_1() {
	char buff[256];
	char* tmp_char;
	cout << "ƒл€ получени€ команд введите help" << endl;
	do {
		cout << "¬ведите команду" << endl;
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(buff);
		tmp_char = strtok(buff, " ");
		if (!strcmp(tmp_char, "help")) {
			cout << "input" << endl;
			cout << "output" << endl;
			cout << "find" << endl;;
			cout << "exit" << endl;
		}
		else if (!strcmp(tmp_char, "output"))
			outputEx(tmp_char);
		else if (!strcmp(tmp_char, "find"))
			findEx();
		else if (!strcmp(tmp_char, "input"))
			inputEx();
		else if (!strcmp(tmp_char, "exit"))
			cout << "выход" << endl;
		else
			cout << "неверна€ команда" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}

