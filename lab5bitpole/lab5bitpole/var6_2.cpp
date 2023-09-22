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
	cout << "| ������ |";
	cout << "|" << setw(strsize + 1) << "��� |";
	cout << "|" << setw(strsize + 1) << "������� |";
	cout << "|" << setw(strsize + 1) << "�������� |";
	cout << "|" << setw(strsize + 1) << "�����������|";
	cout << "|" << setw(strsize + 1) << "�������.|";
	cout << "|" << setw(strsize + 1) << "���������. |";
	cout << "|" << setw(strsize + 1) << "���������. |";
	cout << "| ���� ��������� |";
	cout << "|   �����  |" << endl;
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
	cout << "������� �������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].fam);
	cout << "������� ���" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].name);
	cout << "������� ��������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].surename);
	cout << "������� �����������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].education);
	cout << "������� �������������x" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].speciality);
	cout << "������� �������������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].subdivision);
	cout << "������� ���������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listWorker[wrokerCount].post);
	
	cout << "������� ��� �������� 1 - ����� 2 - ������� 3 - ��������" << endl;
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
	cout << "������� ����: ���� ����� ���" << endl;
	
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
		cout << "����������� ������� �������" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (wrokerCount == 0)
			cout << "�������� �����" << endl;
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
			cout << "����� ������������ ����� worker" << endl;
		}
		else
		{
			if (index >= wrokerCount)
			{
				cout << "������������ ������ worker � ��������: " << wrokerCount << endl;
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
	cout << "�������: " << countF << endl;
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
			outputWorker(tmp_char);
		else if (!strcmp(tmp_char, "find"))
			findWorker(tmp_char);
		else if (!strcmp(tmp_char, "input"))
			inputWorker();
		else if (!strcmp(tmp_char, "exit"))
			cout << "�����" << endl;
		else
			cout << "�������� �������" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}
