#include "stdafx.h"

enum mark
{
	Audi = 1, BMW, Ford, Honda
};

struct DATA
{
	unsigned month : 4;
	unsigned day : 6;
	unsigned years : 16;

};
int carCount = 0;
struct CAR
{
	int number;
	char color[strsize];
	char type[strsize];
	char owner[strsize];
	DATA data;
	int mark;
}listCar[120];

void coutCarHead() {
	cout << "| ������ |";
	cout << "|" << setw(strsize + 1) << "���� |";
	cout << "|" << setw(strsize + 1) << "�������� |";
	cout << "|" << setw(strsize + 1) << "��� ������ |";
	cout << "| ����� |";
	cout << "|  ���� �������  |";
	cout << "|   �����  |" << endl;
}

void coutCar(int index) {
	cout << "| " << setw(6) << index << " |";
	cout << "|" << setw(strsize) << listCar[index].color << "|";
	cout << "|" << setw(strsize) << listCar[index].owner << "|";
	cout << "|" << setw(strsize) << listCar[index].type << "|";
	cout << "| " << setw(5) << listCar[index].number << " |";
	cout << "|   " <<setfill('0') << setw(2) << listCar[index].data.day << " " << setw(2) << listCar[index].data.month << " " << setw(4) << listCar[index].data.years << "   |" << setfill(' ');
	switch (listCar[index].mark)
	{
	case Audi:
		cout << "|" << setw(11) << "Audi|";
		break;
	case BMW:
		cout << "|" << setw(11) << "BMW|";
		break;
	case Ford:
		cout << "|" << setw(11) << "Ford|";
		break;
		case Honda :
			cout << "|" << setw(11) << "Honda|";
			break;
	default:
		cout << "|���������� �����|" << endl;
		break;
	}
	cout << endl;
}



void inputCar() {
	cout << "������� ����" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listCar[carCount].color);
	cout << "������� ���������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listCar[carCount].owner);
	cout << "������� ��� ������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(listCar[carCount].type);
	cout << "������� ����� " << endl;
	cin >> listCar[carCount].number;
	cout << "������� ����: ���� ����� ���" << endl;
	int n;
	cin >> n;
	if (n < 31)
		listCar[carCount].data.day = n;
	cin >> n;
	if(n < 12)
	listCar[carCount].data.month = n;
	cin >> n;
	if(n < 9999)
		listCar[carCount].data.years = n;
	cout << "������� ����� Audi = 1, BMW = 2, Ford = 3, Honda = 4" << endl;
	cin >> listCar[carCount].mark;
	carCount++;
}

void outputCar(char *tmp_char) {
	tmp_char = strtok(NULL, " ");
	//cout << 1 << endl;
	if (tmp_char == NULL)
	{
		cout << "����������� ������� �������" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (carCount == 0)
			cout << "�������� �����" << endl;
		else
		{
			coutCarHead();
			for (int i = 0; i < carCount; i++)
				coutCar(i);
		}
	}
	else
	{
		char arr[strsize] = {};
		strcpy(arr, tmp_char);
		int index = strtoi(arr);
		if (index == -1)
		{
			cout << "����� ������������ ����� car" << endl;
		}
		else
		{
			if (index >= carCount)
			{
				cout << "������������ ������ car � ��������: " << carCount << endl;
			}
			else {
				coutCarHead();
				coutCar(index);
			}
		}
	}
}

void findCar() {
	int n;
	cout << "������� �����" << endl;
	cin >> n;
	int countF = 0;
	int m[120];
	for (int i = 0; i < carCount; i++)
	{
		if (listCar[i].number == n)
			m[countF++] = i;
	}
	cout << "�������: " << countF << endl;
	if (countF != 0) {
		coutCarHead();
		for (int i = 0; i < countF; i++)
		{
			coutCar(m[i]);
		}
	}
}



int var6_1() {
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
			outputCar(tmp_char);
		else if (!strcmp(tmp_char, "find"))
			findCar();
		else if (!strcmp(tmp_char, "input"))
			inputCar();
		else if (!strcmp(tmp_char, "exit"))
			cout << "�����" << endl;
		else
			cout << "�������� �������" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}

