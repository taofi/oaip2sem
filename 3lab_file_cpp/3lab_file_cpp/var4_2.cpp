#include <iostream>
#include <fstream>

using namespace std;

void iFile(ifstream& f, char name[], char str2[]); //Функция чтения из файла
void oFile(ofstream& f, char s[], char name[]); //Функция записи в файл


void var4_2()
{
	ifstream fin;
	ofstream fout;
	setlocale(0, "Rus");
	char str[256];
	char fileName[256];
	cout << "введите строку" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(str);
	cout << "введите имя файла" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(fileName);
	oFile(fout, str, fileName);
	int l = 0, maxL = 0;
	char str2[256];
	iFile(fin, fileName, str2);
	
	for (int i = 0; i < strlen(str2); i++) {
		if (str2[i] == ' ')
		{
			maxL = max(l, maxL);
			l = 0;
		}
		else
			l++;
	}
	maxL = max(l, maxL);
	cout << "длинна самого длинного слова " << maxL;
	fin.close();
	fout.close();
}


void iFile(ifstream& f, char name[], char str2[]) {
	f.open(name);
	if (f.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	f.getline(str2, 256);
	
	f.close();
}



void oFile(ofstream& f, char s[], char name[]) {
	f.open(name);
	if (f.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	f << s << '\n';
	f.close();

}