#include "stdafx.h"
#define size 40

struct TRAIN
{
	char adress[str_len];
	char number[str_len];
	int hours;
	int minut;
};
TRAIN list_of_train[size];
int countTr = 0;


void coutTrainHead() {
	cout << "| индекс |";
	cout << "|" << setw(str_len + 1) << "пункт назначение |";
	cout << "|" << setw(str_len + 1) << "номер поезда|";
	cout << "| время |" << endl;
}
void coutTrain(int index) {
	cout << "| " << setw(6) << index << " |";
	cout << "|" << setw(str_len) << list_of_train[index].adress << "|";
	cout << "|" << setw(str_len) << list_of_train[index].number << "|";
	cout << "| " << setfill('0') << setw(2) << list_of_train[index].hours << ":" << setfill('0') << setw(2) << list_of_train[index].minut << " |" << setfill(' ') <<endl;
}



void findTrain(char* tmp_char) {
	char arr[6];
	strcpy(arr, tmp_char);
	if (arr[2] == ':')
		arr[2] = ' ';
	else if (arr[1] == ' ')
		arr[1] = ' ';
	else {
		cout << "введён неправельное время " << endl;
		return;
	}
	tmp_char = strtok(arr, " ");
	//cout << tmp_char << endl;
	int hours = strtoi(tmp_char);
	//cout << tmp_char << endl;
	cout << hours << endl;
	if (hours == -1)
	{
		cout << "введён неправельное время " << endl;
		return;
	}
	int minutes = strtoi(tmp_char);
	if (minutes == -1)
	{
		cout << "введён неправельное время " << endl;
		return;
	}
	int m[size], n = 0;
	for (int i = 0; i < countTr; i++) 
	{
		if (hours < list_of_train[i].hours || (minutes < list_of_train[i].minut && hours == list_of_train[i].hours))
		{
				m[n++] = i;
		}
	}
	if (n == 0)
		cout << "таких поездов нет " << endl;
	else
	{
		coutTrainHead();
		for (int i = 0; i < n; i++)
			coutTrain(m[i]);
	}

}
void outPutTr(char* tmp_char) {
	tmp_char = strtok(NULL, " ");
	//cout << 1 << endl;
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (countTr == 0)
			cout << "струтура пуста" << endl;
		else
		{
			coutTrainHead();
			for (int i = 0; i < countTr; i++)
				coutTrain(i);
		}
	}
	else 
	{
		char arr[str_len] = {};
		strcpy(arr, tmp_char);
		int index = strtoi(arr);
		if (index == -1)
		{
			cout << "введён неправельный номер книги" << endl;
		}
		else
		{
			if (index >= countTr)
			{
				cout << "максимальный индекс книги в струтуре: " << countTr << endl;
			}
			else {
				coutTrainHead();
				coutTrain(index);
			}
		}
	}
}

void inPutTr(char* tmp_char) { //input author name publishing section origin 1
	char arr[4][str_len] = {};
	int j = 0;
	while (tmp_char != NULL && j != 4) {	
		strcpy(arr[j], tmp_char);
		//cout << arr[j] << " " << j << endl;
		j++;
		tmp_char = strtok(NULL, " ");
	}
	strcpy(list_of_train[countTr].adress, arr[0]);
	strcpy(list_of_train[countTr].number, arr[1]);
	if (arr[2][2] == ':')
		arr[2][2] = ' ';
	else {
		cout << "введён неправельное время " << endl;
		return;
	}
	tmp_char = strtok(arr[2], " ");
	//cout << tmp_char << endl;
	int hours = strtoi(tmp_char);
	if (hours == -1)
	{
		cout << "введён неправельное время " << endl;
		return;
	}
	tmp_char = strtok(NULL, " ");
	int minutes = strtoi(tmp_char);
	if (minutes == -1)
	{
		cout << "введён неправельное время " << endl;
		return;
	}
	list_of_train[countTr].hours = hours;
	list_of_train[countTr].minut = minutes;
	countTr++;
}



void readFTr(char* tmp_char, ifstream& f) {
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
		inPutTr(strtok(str, " "));
	}
	f.close();
}

void dop2() {
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
			outPutTr(tmp_char);
		else if (!strcmp(tmp_char, "find"))
			findTrain(strtok(NULL, " "));
		else if (!strcmp(tmp_char, "input"))
			inPutTr(strtok(NULL, " "));
		else if (!strcmp(tmp_char, "readF"))
			readFTr(tmp_char, fin);
		else if (!strcmp(tmp_char, "exit"))
			cout << "выход" << endl;
		else
			cout << "неверная команда" << endl;
	} while (strcmp(tmp_char, "exit"));
}

