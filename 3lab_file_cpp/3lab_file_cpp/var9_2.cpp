#include <iostream>
#include <fstream>

using namespace std;

void iFile9(ifstream& f, char name[], char str2[]); //Функция чтения из файла
void oFile9(ofstream& f, char s[], char name[]); //Функция записи в файл


void var9_2()
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
	oFile9(fout, str, fileName);
	int l = 0, minL, index = -1, countWord = 0;
	char str2[256];
	iFile9(fin, fileName, str2);
	
	for (int i = 0; i < strlen(str2); i++) {
		if (str2[i] == ' ')
		{
			if (index == -1 || minL > l)
			{
				minL = l;
				index = countWord;
			}
			countWord++;
			l = 0;

		}
		else
			l++;
	}
	if (index == -1 || minL > l)
	{
		minL = l;
		index = countWord;
	}
	cout << "индекс самого короткого слова " << index << endl;
	cout << "длинна самого короткого слова " << minL << endl;
	fin.close();
	fout.close();
}


void iFile9(ifstream& f, char name[], char str2[]) {
	f.open(name);
	if (f.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	f.getline(str2, 256);
	
	f.close();
}



void oFile9(ofstream& f, char s[], char name[]) {
	f.open(name);
	if (f.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	f << s << '\n';
	f.close();

}