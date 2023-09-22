#include "stdafx.h"

struct DATA
{
	unsigned month : 4;
	unsigned day : 6;
	unsigned years : 16;

};

union GROUP {
	int i;
	char str[strsize];
};

int studentCount = 0;
struct bank_schet
{
	double mark;
	unsigned grType : 3;
	GROUP group;
	char fam[strsize];
	char name[strsize];
	char surename[strsize];
	DATA data;
	char speciality[strsize];
	char facult[strsize];
}listStudent[120];

void coutStudentHead() {
	cout << "| индекс |";
	cout << "|" << setw(strsize + 1) << "им€ |";
	cout << "|" << setw(strsize + 1) << "фамили€ |";
	cout << "|" << setw(strsize + 1) << "отчество |";
	cout << "|   группа |";
	cout << "|  специальность |";
	cout << "|  факультет  |";
	cout << "| дата поступлени€|";
	cout << "|    оценка  |" << endl;
}

void coutStudent(int index) {
	cout << "| " << setw(6) << index << " |";
	cout << "|" << setw(strsize) << listStudent[index].fam << "|";
	cout << "|" << setw(strsize) << listStudent[index].name << "|";
	cout << "|" << setw(strsize) << listStudent[index].surename << "|";
	switch (listStudent[index].grType) {
	case 1:
		cout << "|" << setw(10) << listStudent[index].group.i << "|";
		break;
	case 2:
		cout << "|" << setw(10) << listStudent[index].group.str << "|";
		break;
	}
	cout << "|" << setw(16) << listStudent[index].speciality << "|";
	cout << "|" << setw(strsize) << listStudent[index].facult << "|";
	cout << "|    " <<setfill('0') << setw(2) << listStudent[index].data.day << " " << setw(2) << listStudent[index].data.month << " " << setw(4) << listStudent[index].data.years << "   |" << setfill(' ');
	cout << "|" << setw(12) << listStudent[index].mark << "|";
	cout << endl;
}



void inputStudent() {
	int n;
	cout << "введите фамилию" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listStudent[studentCount].fam);
	cout << "введите им€" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listStudent[studentCount].name);
	cout << "введите отчество" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listStudent[studentCount].surename);
	cout << "введите специальность" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listStudent[studentCount].speciality);
	cout << "введите факультет" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listStudent[studentCount].facult);
	cout << "введите средний бал" << endl;
	cin >> listStudent[studentCount].mark;
	cout << "введите тип группы 1 - целый 2 - строчный" << endl;
	cin >> n;
	listStudent[studentCount].grType = n;
	switch (listStudent[studentCount].grType) {
	case 1:
		cin >>  listStudent[studentCount].group.i;
		break;
	case 2:
		cin >> listStudent[studentCount].group.str;
		break;
	}
	cout << "введите дату: день мес€ц год" << endl;
	
	cin >> n;
	if (n < 31)
		listStudent[studentCount].data.day = n;
	cin >> n;
	if(n < 12)
	listStudent[studentCount].data.month = n;
	cin >> n;
	if(n < 9999)
		listStudent[studentCount].data.years = n;
	studentCount++;
}

void outputStudent(char *tmp_char) {
	tmp_char = strtok(NULL, " ");
	//cout << 1 << endl;
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (studentCount == 0)
			cout << "струтура пуста" << endl;
		else
		{
			coutStudentHead();
			for (int i = 0; i < studentCount; i++)
				coutStudent(i);
		}
	}
	else
	{
		char arr[strsize] = {};
		strcpy(arr, tmp_char);
		int index = strtoi(arr);
		if (index == -1)
		{
			cout << "введЄн неправельный номер student" << endl;
		}
		else
		{
			if (index >= studentCount)
			{
				cout << "максимальный индекс student в струтуре: " << studentCount << endl;
			}
			else {
				coutStudentHead();
				coutStudent(index);
			}
		}
	}
}

void findStudent() {
	double n;
	cout << "введите оценку" << endl;
	cin >> n;
	int countF = 0;
	int m[120];
	for (int i = 0; i < studentCount; i++)
	{
			if (listStudent[i].mark == n)
				m[countF++] = i;
	}
	cout << "найдено: " << countF << endl;
	if (countF != 0) {
		coutStudentHead();
		for (int i = 0; i < countF; i++)
		{
			coutStudent(m[i]);
		}
	}
}



int var16_2() {
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
			outputStudent(tmp_char);
		else if (!strcmp(tmp_char, "find"))
			findStudent();
		else if (!strcmp(tmp_char, "input"))
			inputStudent();
		else if (!strcmp(tmp_char, "exit"))
			cout << "выход" << endl;
		else
			cout << "неверна€ команда" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}

