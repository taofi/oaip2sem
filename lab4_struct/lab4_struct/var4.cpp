#include "stdafx.h"
#define size 40

struct LIBRARY
{
	char author[str_len];
	char name[str_len];
	char publishing[str_len];
	char section[str_len];
	char origin[str_len];
	bool availability;
};
LIBRARY list_of_book[size];
int structSize = 0;


void coutLibHead() {
	cout << "| номер |";
	cout << "|" << setw(str_len + 1) << "автор |";
	cout << "|" << setw(str_len + 1) << "название |";
	cout << "|" << setw(str_len + 1) << "издательство |";
	cout << "|" << setw(str_len + 1) << "раздел |";
	cout << "|" << setw(str_len + 1) << "происхождение |";
	cout << "| наличие |" << endl;
}
void coutLibBook(int index) {
	cout << "| " << setw(5) << index << " |";
	cout << "|" << setw(str_len) << list_of_book[index].author << "|";
	cout << "|" << setw(str_len) << list_of_book[index].name << "|";
	cout << "|" << setw(str_len) << list_of_book[index].publishing << "|";
	cout << "|" << setw(str_len) << list_of_book[index].section << "|";
	cout << "|" << setw(str_len) << list_of_book[index].origin << "|";
	cout << "|" << setw(8) << list_of_book[index].availability << " |" << endl;
}



void find(char* tmp_char) {
	tmp_char = strtok(NULL, " ");
	cout << tmp_char << endl;
	int countF = 0;
	int m[size];
	for (int i = 0; i < structSize; i++)
	{
		if (!strcmp(tmp_char, list_of_book[i].author)) 
		{
			m[countF++] = i;
		}
	}
	cout << "найдено: " << countF << endl;
	if (countF != 0) {
		coutLibHead();
		for (int i = 0; i < countF; i++)
		{
			coutLibBook(m[i]);
		}
	}
}
void outPut(char* tmp_char) {
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
			coutLibHead();
			for (int i = 0; i < structSize; i++)
				coutLibBook(i);
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
			if (index >= structSize)
			{
				cout << "максимальный индекс книги в струтуре: " << structSize << endl;
			}
			else {
				coutLibHead();
				coutLibBook(index);
			}
		}
	}
}

void inPut(char* tmp_char) { //input author name publishing section origin 1
	char arr[6][str_len] = {};
	int j = 0;
	while (tmp_char != NULL && j != 6) {	
		strcpy(arr[j], tmp_char);
		//cout << arr[j] << " " << j << endl;
		j++;
		tmp_char = strtok(NULL, " ");
	}
	for (int i = 0; i < 6; i++)
	{
		if (strlen(arr[i]) == 0)
		{
			cout << "неправильно введена команда" << endl;
			return;
		}
	}
	int digit = strtoi(arr[5]);
	if (digit == -1 || digit > 1)
	{
		cout << "введён неправельное наличие книги " << endl;
		return;
	}
	//cout << arr[5] << endl;
	strcpy(list_of_book[structSize].author, arr[0]);
	strcpy(list_of_book[structSize].name, arr[1]);
	strcpy(list_of_book[structSize].publishing, arr[2]);
	strcpy(list_of_book[structSize].section, arr[3]);
	strcpy(list_of_book[structSize].origin, arr[4]);
	list_of_book[structSize].availability = bool(digit);
	structSize++;
}


LIBRARY clearLib;
void Delete(char* tmp_char) {
	tmp_char = strtok(NULL, " ");
	if (tmp_char == NULL)
	{
		cout << "неправильно введена команда" << endl;
		return;
	}
	if (!strcmp(tmp_char, "all")) {
		for (int i = 0; i < size; i++)
			list_of_book[i] = clearLib;
		structSize = 0;
		cout << "все было очищено " << endl;
	}
	else
	{
		char arr[str_len] = {};
		strcpy(arr, tmp_char);
		int index = strtoi(arr);
		if (index == -1 || index > structSize)
		{
			cout << "введён неправельный номер" << endl;
		} else {
			for (int i = index ; i < structSize; i++)
				list_of_book[i] = list_of_book[i + 1];
			structSize--;
			list_of_book[structSize] = clearLib;
			cout << "удалено" << endl;
		}
		
	}
}
void readF(char* tmp_char, ifstream& f) {
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
		inPut(strtok(str, " "));
	}
	f.close();
}
void writeF(char* tmp_char, ofstream& f) {
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
	else
	{
		for(int index = 0; index < structSize; index ++ )
			f << list_of_book[index].author << " " << list_of_book[index].name << " " << list_of_book[index].publishing << " " << list_of_book[index].section << " " << list_of_book[index].origin << " " << list_of_book[index].availability << '\n';;
	}
	cout << "записано в файл " << tmp_char << endl;
	f.close();
}


int var4() {
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
			cout << "delete" << endl;
			cout << "writeF" << endl;
			cout << "readF" << endl;
			cout << "exit" << endl;
		}
		else if (!strcmp(tmp_char, "output"))
			outPut(tmp_char);
		else if (!strcmp(tmp_char, "find"))
			find(tmp_char);
		else if (!strcmp(tmp_char, "input"))
		{
			//tmp_char = strtok(NULL, " ");
			inPut(strtok(NULL, " "));
		}
		else if (!strcmp(tmp_char, "delete"))
			Delete(tmp_char);
		else if (!strcmp(tmp_char, "readF"))
			readF(tmp_char, fin);
		else if (!strcmp(tmp_char, "writeF"))
			writeF(tmp_char, fout);
		else if (!strcmp(tmp_char, "exit"))
			cout << "выход" << endl;
		else
			cout << "неверная команда" << endl;
	} while (strcmp(tmp_char, "exit"));
	return 0;
}

