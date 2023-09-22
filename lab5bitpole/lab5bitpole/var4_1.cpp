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
int structSize = 0;
struct bank_schet
{
	int number;
	int balance;
	char fam[strsize];
	char name[strsize];
	char surename[strsize];
	DATA data;
	int tips;
}listBank[120];

void coutBank(int index) {
	cout << "| " << setw(6) << index << " |";
	cout << "|" << setw(strsize) << listBank[index].fam << "|";
	cout << "|" << setw(strsize) << listBank[index].name << "|";
	cout << "|" << setw(strsize) << listBank[index].surename << "|";
	cout << "|" << setw(10) << listBank[index].balance << "|";
	cout << "| " << setw(5) << listBank[index].number << " |";
	cout << "|   " <<setfill('0') << setw(2) << listBank[index].data.day << " " << setw(2) << listBank[index].data.month << " " << setw(4) << listBank[index].data.years << "   |" << setfill(' ');
	switch (listBank[index].tips)
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



void inputBank() {
	cout << "введите фамилию" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listBank[structSize].fam);
	cout << "введите им€" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listBank[structSize].name);
	cout << "введите отчество" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listBank[structSize].surename);
	cout << "введите баланс" << endl;
	cin >> listBank[structSize].balance;
	cout << "введите номер счета" << endl;
	cin >> listBank[structSize].number;
	cout << "введите дату: день мес€ц год" << endl;
	int n;
	cin >> n;
	if (n < 31)
		listBank[structSize].data.day = n;
	cin >> n;
	if(n < 12)
	listBank[structSize].data.month = n;
	cin >> n;
	if(n < 9999)
		listBank[structSize].data.years = n;
	cout << "введите тип express - 1, preferential - 2, deposit - 3" << endl;
	cin >> listBank[structSize].tips;
	structSize++;
}

void outputBank(char *tmp_char) {
	tmp_char = strtok(NULL, " ");
	//cout << 1 << endl;
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (structSize == 0)
			cout << "струтура пуста" << endl;
		else
		{
			coutBankHead();
			for (int i = 0; i < structSize; i++)
				coutBank(i);
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
			if (index >= structSize)
			{
				cout << "максимальный индекс книги в струтуре: " << structSize << endl;
			}
			else {
				coutBankHead();
				coutBank(index);
			}
		}
	}
}

void findBank(char *tmp_char) {
	bool isMore;
	if (!strcmp(tmp_char, "more")) {
		cout << "more" << endl;
		isMore = true;
	}
	else
	{
		cout << "less" << endl;
		isMore = false;
	}
	int countF = 0;
	int m[120];
	for (int i = 0; i < structSize; i++)
	{
		if (isMore) {
			if (listBank[i].balance > 100)
				m[countF++] = i;
		}
		else if (listBank[i].balance < 100)
				m[countF++] = i;
	}
	cout << "найдено: " << countF << endl;
	if (countF != 0) {
		coutBankHead();
		for (int i = 0; i < countF; i++)
		{
			coutBank(m[i]);
		}
	}
}



int var4_1() {
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
			outputBank(tmp_char);
		else if (!strcmp(tmp_char, "find"))
			findBank(strtok(NULL, " "));
		else if (!strcmp(tmp_char, "input"))
			inputBank();
		else if (!strcmp(tmp_char, "exit"))
			cout << "выход" << endl;
		else
			cout << "неверна€ команда" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}

