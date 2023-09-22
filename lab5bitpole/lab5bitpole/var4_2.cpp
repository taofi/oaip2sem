#include "stdafx.h"

enum TipSch
{
	express = 1, preferential, deposit
};

struct DATA
{
	unsigned month : 4;
	unsigned day : 6;
	unsigned years : 16;

};

union BALANCE {
	int i;
	double d;
	char str[strsize];
};

int structSize2 = 0;
struct bank_schet
{
	int number;
	unsigned balanceType : 3;
	BALANCE balance;
	char fam[strsize];
	char name[strsize];
	char surename[strsize];
	DATA data;
	int tips;
}listBank2[120];



void coutBank2(int index) {
	cout << "| " << setw(6) << index << " |";
	cout << "|" << setw(strsize) << listBank2[index].fam << "|";
	cout << "|" << setw(strsize) << listBank2[index].name << "|";
	cout << "|" << setw(strsize) << listBank2[index].surename << "|";
	switch (listBank2[index].balanceType) {
	case 1:
		cout << "|" << setw(10) << listBank2[index].balance.i << "|";
		break;
	case 2:
		cout << "|" << setw(10) << listBank2[index].balance.d << "|";
		break;
	case 3:
		cout << "|" << setw(10) << listBank2[index].balance.str << "|";
		break;
	}
	cout << "| " << setw(5) << listBank2[index].number << " |";
	cout << "|   " <<setfill('0') << setw(2) << listBank2[index].data.day << " " << setw(2) << listBank2[index].data.month << " " << setw(4) << listBank2[index].data.years << "   |" << setfill(' ');
	switch (listBank2[index].tips)
	{
	case express:
		cout << "|" << setw(16) << "срочный|";
		break;
	case deposit:
		cout << "|" << setw(16) << "депозитный|";
		break;
	case preferential:
		cout << "|" << setw(16) << "льготный|";
		break;
	default:
		cout << "|неивестный тип|" << endl;
		break;
	}
	cout << endl;
}



void inputBank2() {
	int n;
	cout << "введите фамилию" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listBank2[structSize2].fam);
	cout << "введите им€" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listBank2[structSize2].name);
	cout << "введите отчество" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listBank2[structSize2].surename);
	cout << "введите тип баланса 1 - целый 2 - дробный 3 - строчный" << endl;
	cin >> n;
	listBank2[structSize2].balanceType = n;
	switch (listBank2[structSize2].balanceType) {
	case 1:
		cin >>  listBank2[structSize2].balance.i;
		break;
	case 2:
		cin >> listBank2[structSize2].balance.d;
		break;
	case 3:
		cin >> listBank2[structSize2].balance.str;
		break;
	}
	cout << "введите номер счета" << endl;
	cin >> listBank2[structSize2].number;
	cout << "введите дату: день мес€ц год" << endl;
	
	cin >> n;
	if (n < 31)
		listBank2[structSize2].data.day = n;
	cin >> n;
	if(n < 12)
	listBank2[structSize2].data.month = n;
	cin >> n;
	if(n < 9999)
		listBank2[structSize2].data.years = n;
	cout << "введите тип express - 1, preferential - 2, deposit - 3" << endl;
	cin >> listBank2[structSize2].tips;
	structSize2++;
}

void outputBank2(char *tmp_char) {
	tmp_char = strtok(NULL, " ");
	//cout << 1 << endl;
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (structSize2 == 0)
			cout << "струтура пуста" << endl;
		else
		{
			coutBankHead();
			for (int i = 0; i < structSize2; i++)
				coutBank2(i);
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
			if (index >= structSize2)
			{
				cout << "максимальный индекс книги в струтуре: " << structSize2 << endl;
			}
			else {
				coutBankHead();
				coutBank2(index);
			}
		}
	}
}

void findBank2() {
	int n;
	cout << "введите номер" << endl;
	cin >> n;
	int countF = 0;
	int m[120];
	for (int i = 0; i < structSize2; i++)
	{
			if (listBank2[i].number == n)
				m[countF++] = i;
	}
	cout << "найдено: " << countF << endl;
	if (countF != 0) {
		coutBankHead();
		for (int i = 0; i < countF; i++)
		{
			coutBank2(m[i]);
		}
	}
}



int var4_2() {
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
			outputBank2(tmp_char);
		else if (!strcmp(tmp_char, "find"))
			findBank2();
		else if (!strcmp(tmp_char, "input"))
			inputBank2();
		else if (!strcmp(tmp_char, "exit"))
			cout << "выход" << endl;
		else
			cout << "неверна€ команда" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}

