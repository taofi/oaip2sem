#include "stdafx.h"
#define size 40

struct SANATORI
{
	char name[str_len];
	char adress[str_len];
	char profil[str_len];
	int ticketCount;
};
SANATORI list_of_building[size];
int countSan = 0;


void coutBuildingHead() {
	cout << "| номер |";
	cout << "|" << setw(str_len + 1) << "название |";
	cout << "|" << setw(str_len + 1) << "адресс |";
	cout << "|" << setw(str_len + 1) << "профиль |";
	cout << "|" << setw(str_len + 1) << "кол. путевок |" << endl;
}
void coutBuilding(int index) {
	cout << "| " << setw(5) << index << " |";
	cout << "|" << setw(str_len) << list_of_building[index].name << "|";
	cout << "|" << setw(str_len) << list_of_building[index].adress << "|";
	cout << "|" << setw(str_len) << list_of_building[index].profil << "|";
	cout << "|" << setw(str_len) << list_of_building[index].ticketCount  << "|" << endl;
}

bool Compare (const SANATORI& a, const SANATORI& b)
{
	if (strcmp(a.profil, b.profil) < 0) return true;
	if (strcmp(a.profil, b.profil) == 0)
		return strcmp(a.name, b.name) < 0;
	return false;
}

void findSan(char* tmp_char) {
	int countF = 0;
	int m[size];
	if (!strcmp(tmp_char, "name")) {
		tmp_char = strtok(NULL, " ");
		for (int i = 0; i < countSan; i++)
		{
			if (!strcmp(tmp_char, list_of_building[i].name))
			{
				m[countF++] = i;
			}
		}
	}
	else if (!strcmp(tmp_char, "address")) {
		tmp_char = strtok(NULL, " ");
		for (int i = 0; i < countSan; i++)
		{
			if (!strcmp(tmp_char, list_of_building[i].adress))
			{
				m[countF++] = i;
			}
		}
	}
	else if (!strcmp(tmp_char, "profil")) {
		tmp_char = strtok(NULL, " ");
		for (int i = 0; i < countSan; i++)
		{
			if (!strcmp(tmp_char, list_of_building[i].profil))
			{
				m[countF++] = i;
			}
		}
	}
	else if (!strcmp(tmp_char, "ticket")) {
		tmp_char = strtok(NULL, " ");
		int digit = strtoi(tmp_char);
		if (digit == -1)
		{
			cout << "введён неправельное количество путевок " << endl;
			return;
		}
		for (int i = 0; i < countSan; i++)
		{
			if (list_of_building[i].ticketCount == digit)
			{
				m[countF++] = i;
			}
		}
	}
	cout << "найдено: " << countF << endl;
	if (countF != 0) {
		coutBuildingHead();
		for (int i = 0; i < countF; i++)
		{
			coutBuilding(m[i]);
		}
	}
}

void outPutSan(char* tmp_char) {
	if (countSan == 0)
	{
		cout << "струтура пуста" << endl;
		return;
	}
	SANATORI temp;
	for (int i = 0; i < countSan; i++)
	{
		for (int j = i; j < countSan; j++)
		{
			if (Compare(list_of_building[j], list_of_building[i]))
			{
				temp = list_of_building[i];
				list_of_building[i]= list_of_building[j];
				list_of_building[j] = temp;
			}
		}
	}
	coutBuildingHead();
	coutBuilding(0);
	for (int i = 1; i < countSan; i++)
	{
		if (strcmp(list_of_building[i - 1].profil, list_of_building[i].profil))
		{
			cout << setfill('-') << setw(str_len * 5) << "" << setfill(' ') << endl;
			coutBuildingHead();
		}
		coutBuilding(i);
	}
	
}

void inPutSan(char* tmp_char) { //input author name publishing section origin 1
	char arr[5][str_len] = {};
	int j = 0;
	while (tmp_char != NULL && j != 5) {	
		strcpy(arr[j], tmp_char);
		//cout << arr[j] << " " << j << endl;
		j++;
		tmp_char = strtok(NULL, " ");
	}
	int digit = strtoi(arr[3]);
	if (digit == -1 )
	{
		cout << "введён неправельное количество путевок " << endl;
		return;
	}
//	cout << arr[5] << endl;
	strcpy(list_of_building[countSan].name, arr[0]);
	strcpy(list_of_building[countSan].adress, arr[1]);
	strcpy(list_of_building[countSan].profil, arr[2]);
	list_of_building[countSan].ticketCount = digit;
	countSan++;
}



void readFsan(char* tmp_char, ifstream& f) {
	tmp_char = strtok(NULL, " ");
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	f.open(tmp_char);
	if (f.fail())
	{
		cout << "\n Ошибка открытия файла";
		return;
	}
	char str[256]={};
	while (f.getline(str, 256)) {
		inPutSan(strtok(str, " "));
	}
	f.close();
}
SANATORI voidSan;
void DeleteSan(char* tmp_char) {
	tmp_char = strtok(NULL, " ");
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		for (int i = 0; i < size; i++)
			list_of_building[i] = voidSan;
		countSan = 0;
		cout << "все было очищено " << endl;
	}
	else
	{
		char arr[str_len] = {};
		strcpy(arr, tmp_char);
		int index = strtoi(arr);
		if (index == -1 || index > countSan)
		{
			cout << "введён неправельный номер" << endl;
		}
		else {
			for (int i = index; i < countSan; i++)
				list_of_building[i] = list_of_building[i + 1];
			countSan--;
			list_of_building[countSan] = voidSan;
			cout << "удалено" << endl;
		}

	}
}

void dop3() {
	ifstream fin;
	ofstream fout;
	char buff[256];
	char *tmp_char;
	cout << "Для получения команд введите help" << endl;
	do {
		cout << "Введите команду" << endl;
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(buff);
		tmp_char = strtok(buff, " ");
		if (!strcmp(tmp_char, "help")) {
			cout << "input" << endl;
			cout << "output" << endl;
			cout << "find" << endl;
			cout << "readF" << endl;
			cout << "exit" << endl;
		}
		else if (!strcmp(tmp_char, "output"))
			outPutSan(tmp_char);
		else if (!strcmp(tmp_char, "delete"))
			DeleteSan(tmp_char);
		else if (!strcmp(tmp_char, "input"))
			inPutSan(strtok(NULL, " "));
		else if (!strcmp(tmp_char, "find"))
			findSan(strtok(NULL, " "));
		else if (!strcmp(tmp_char, "readF"))
			readFsan(tmp_char, fin);
		else if (!strcmp(tmp_char, "exit"))
			cout << "выход" << endl;
		else
			cout << "неверная команда" << endl;
	} while (strcmp(tmp_char, "exit"));
}

