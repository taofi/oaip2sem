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

union SALARY {
	int i;
	double d;
	char str[strsize];
};

int wrokerCount = 0;
struct WORKER
{
	unsigned salaryType : 3;
	SALARY salary;
	char fam[strsize];
	char name[strsize];
	char surename[strsize];
	char education[strsize];
	char speciality[strsize];
	char subdivision[strsize];
	char post[strsize];
	DATA data;
}listWorker[120];


void coutWorkerHead() {
	cout << "| индекс |";
	cout << "|" << setw(strsize + 1) << "им€ |";
	cout << "|" << setw(strsize + 1) << "фамили€ |";
	cout << "|" << setw(strsize + 1) << "отчество |";
	cout << "|" << setw(strsize + 1) << "образование|";
	cout << "|" << setw(strsize + 1) << "специал.|";
	cout << "|" << setw(strsize + 1) << "подраздел. |";
	cout << "|" << setw(strsize + 1) << "должность. |";
	cout << "| дата изменени€ |";
	cout << "|   оклад  |" << endl;
}

void coutWorker(int index) {
	cout << "| " << setw(6) << index << " |";
	cout  << "|" << setw(strsize) << listWorker[index].fam << "|";
	cout << "|" << setw(strsize) << listWorker[index].name << "|";
	cout << "|" << setw(strsize) << listWorker[index].surename << "|";
	cout << "|" << setw(strsize) << listWorker[index].education << "|";
	cout << "|" << setw(strsize) << listWorker[index].speciality << "|";
	cout << "|" << setw(strsize) << listWorker[index].subdivision << "|";
	cout << "|" << setw(strsize) << listWorker[index].post << "|";
	cout << "|   " <<setfill('0') << setw(2) << listWorker[index].data.day << " " << setw(2) << listWorker[index].data.month << " " << setw(4) << listWorker[index].data.years << "   |" << setfill(' ');
	switch (listWorker[index].salaryType) {
	case 1:
		cout << "|" << setw(10) << listWorker[index].salary.i << "|";
		break;
	case 2:
		cout << "|" << setw(10) << listWorker[index].salary.d << "|";
		break;
	case 3:
		cout << "|" << setw(10) << listWorker[index].salary.str << "|";
		break;
	}
	cout << endl;
}



void inputWorker() {
	int n;
	cout << "введите фамилию" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].fam);
	cout << "введите им€" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].name);
	cout << "введите отчество" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].surename);
	cout << "введите образование" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].education);
	cout << "введите специальностьx" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].speciality);
	cout << "введите подразделение" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].subdivision);
	cout << "введите должность" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].post);
	
	cout << "введите тип зарплаты 1 - целый 2 - дробный 3 - строчный" << endl;
	cin >> n;
	listWorker[wrokerCount].salaryType = n;
	switch (listWorker[wrokerCount].salaryType) {
	case 1:
		cin >>  listWorker[wrokerCount].salary.i;
		break;
	case 2:
		cin >> listWorker[wrokerCount].salary.d;
		break;
	case 3:
		cin >> listWorker[wrokerCount].salary.str;
		break;
	}
	cout << "введите дату: день мес€ц год" << endl;
	
	cin >> n;
	if (n < 31)
		listWorker[wrokerCount].data.day = n;
	cin >> n;
	if(n < 12)
	listWorker[wrokerCount].data.month = n;
	cin >> n;
	if(n < 9999)
		listWorker[wrokerCount].data.years = n;
	wrokerCount++;
}

void outputWorker(char *tmp_char) {
	tmp_char = strtok(NULL, " ");
	//cout << 1 << endl;
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (wrokerCount == 0)
			cout << "струтура пуста" << endl;
		else
		{
			coutWorkerHead();
			for (int i = 0; i < wrokerCount; i++)
				coutWorker(i);
		}
	}
	else
	{
		char arr[strsize] = {};
		strcpy(arr, tmp_char);
		int index = strtoi(arr);
		if (index == -1)
		{
			cout << "введЄн неправельный номер worker" << endl;
		}
		else
		{
			if (index >= wrokerCount)
			{
				cout << "максимальный индекс worker в струтуре: " << wrokerCount << endl;
			}
			else {
				coutWorkerHead();
				coutWorker(index);
			}
		}
	}
}

void findWorker(char* tmp_char) {
	tmp_char = strtok(NULL, " ");
	cout << tmp_char << endl;
	int countF = 0;
	int m[120];
	for (int i = 0; i < wrokerCount; i++)
	{
		if (!strcmp(tmp_char, listWorker[i].post))
		{
			m[countF++] = i;
		}
	}
	cout << "найдено: " << countF << endl;
	if (countF != 0) {
		coutWorkerHead();
		for (int i = 0; i < countF; i++)
		{
			coutWorker(m[i]);
		}
	}
}



int var6_2() {
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
			outputWorker(tmp_char);
		else if (!strcmp(tmp_char, "find"))
			findWorker(tmp_char);
		else if (!strcmp(tmp_char, "input"))
			inputWorker();
		else if (!strcmp(tmp_char, "exit"))
			cout << "выход" << endl;
		else
			cout << "неверна€ команда" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}
