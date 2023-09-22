#include "stdafx.h"
#define size 40

struct EXAMEN
{
	char secondname[str_len];
	char name[str_len];
	char surname[str_len];
	int examenCount;
	int mark[10];
};
EXAMEN list_of_student[size];
int countSt = 0;


void coutStudentHead() {
	cout << "| номер |";
	cout << "|" << setw(str_len + 1) << "фамилия |";
	cout << "|" << setw(str_len + 1) << "имя |";
	cout << "|" << setw(str_len + 1) << "отчество |";
	cout << "|" << setw(str_len + 1) << "кол. экзаменов |";
	cout << "|" << setw(str_len + 1) << "оценки" << endl;
}
void coutStudentBook(int index) {
	cout << "| " << setw(5) << index << " |";
	cout << "|" << setw(str_len) << list_of_student[index].secondname << "|";
	cout << "|" << setw(str_len) << list_of_student[index].name << "|";
	cout << "|" << setw(str_len) << list_of_student[index].surname << "|";
	cout << "|" << setw(str_len) << list_of_student[index].examenCount << "||";
	for(int i = 0; i < list_of_student[index].examenCount; i ++)
	cout << " " << list_of_student[index].mark[i];
	cout << endl;
}



void result(char* tmp_char) {
	int goodMark = 0;
	bool isGood = true;
	for (int i = 0; i < countSt; i++)
	{
		isGood = true;
		for (int j = 0; j < list_of_student[i].examenCount; j++)
		{
			//cout << list_of_student[i].mark[j] << endl;
			if (list_of_student[i].mark[j] < 4)
			{
				isGood = false;
				break;
			}
		}
		if (isGood)
			goodMark++;
	}
	cout << "процент студентов здавшие на 4, 5 " << double(goodMark) / countSt * 100 << "%" << endl;
	cout << "4, 5: " << goodMark << " все сдавшие: " << countSt << endl;
}
void outPutSt(char* tmp_char) {
	tmp_char = strtok(NULL, " ");
	cout << 1 << endl;
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		if (countSt == 0)
			cout << "струтура пуста" << endl;
		else
		{
			coutStudentHead();
			for (int i = 0; i < countSt; i++)
				coutStudentBook(i);
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
			if (index >= countSt)
			{
				cout << "максимальный индекс книги в струтуре: " << countSt << endl;
			}
			else {
				coutStudentHead();
				coutStudentBook(index);
			}
		}
	}
}

void inPutSt(char* tmp_char) { //input author name publishing section origin 1
	char arr[15][str_len] = {};
	int j = 0;
	while (tmp_char != NULL && j != 15) {	
		strcpy(arr[j], tmp_char);
		//cout << arr[j] << " " << j << endl;
		j++;
		tmp_char = strtok(NULL, " ");
	}
	int digit = strtoi(arr[3]);
	if (digit == -1 )
	{
		cout << "введён неправельное количество экзаменов " << endl;
		return;
	}
//	cout << arr[5] << endl;
	strcpy(list_of_student[countSt].secondname, arr[0]);
	strcpy(list_of_student[countSt].name, arr[1]);
	strcpy(list_of_student[countSt].surname, arr[2]);
	list_of_student[countSt].examenCount = digit;
	for (int i = 0; i < list_of_student[countSt].examenCount; i++)
	{
		digit = strtoi(arr[4 + i]);
		if (digit == -1)
		{
			cout << "введён неправельная оценка за экзамен " << endl;
			return;
		}
		list_of_student[countSt].mark[i] = digit;
		//cout << list_of_student[countSt].mark[i] << endl;
	}
	countSt++;
}



void readFst(char* tmp_char, ifstream& f) {
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
		inPutSt(strtok(str, " "));
	}
	f.close();
}

void dop1() {
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
			cout << "result" << endl;
			cout << "readF" << endl;
			cout << "exit" << endl;
		}
		else if (!strcmp(tmp_char, "output"))
			outPutSt(tmp_char);
		else if (!strcmp(tmp_char, "result"))
			result(tmp_char);
		else if (!strcmp(tmp_char, "input"))
			inPutSt(strtok(NULL, " "));
		else if (!strcmp(tmp_char, "readF"))
			readFst(tmp_char, fin);
		else if (!strcmp(tmp_char, "exit"))
			cout << "выход" << endl;
		else
			cout << "неверная команда" << endl;
	} while (strcmp(tmp_char, "exit"));
}

