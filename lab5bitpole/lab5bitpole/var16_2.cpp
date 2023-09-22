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
	cout << "| ������ |";
	cout << "|" << setw(strsize + 1) << "��� |";
	cout << "|" << setw(strsize + 1) << "������� |";
	cout << "|" << setw(strsize + 1) << "�������� |";
	cout << "|   ������ |";
	cout << "|  ������������� |";
	cout << "|  ���������  |";
	cout << "| ���� �����������|";
	cout << "|    ������  |" << endl;
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
	cout << "������� �������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listStudent[studentCount].fam);
	cout << "������� ���" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listStudent[studentCount].name);
	cout << "������� ��������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listStudent[studentCount].surename);
	cout << "������� �������������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listStudent[studentCount].speciality);
	cout << "������� ���������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listStudent[studentCount].facult);
	cout << "������� ������� ���" << endl;
	cin >> listStudent[studentCount].mark;
	cout << "������� ��� ������ 1 - ����� 2 - ��������" << endl;
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
	cout << "������� ����: ���� ����� ���" << endl;
	
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
		cout << "����������� ������� �������" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (studentCount == 0)
			cout << "�������� �����" << endl;
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
			cout << "����� ������������ ����� student" << endl;
		}
		else
		{
			if (index >= studentCount)
			{
				cout << "������������ ������ student � ��������: " << studentCount << endl;
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
	cout << "������� ������" << endl;
	cin >> n;
	int countF = 0;
	int m[120];
	for (int i = 0; i < studentCount; i++)
	{
			if (listStudent[i].mark == n)
				m[countF++] = i;
	}
	cout << "�������: " << countF << endl;
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
	cout << "��� ��������� ������ ������� help" << endl;
	do {
		cout << "������� �������" << endl;
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
			cout << "�����" << endl;
		else
			cout << "�������� �������" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}

