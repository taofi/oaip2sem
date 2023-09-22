#include <iostream>
#include <fstream>

using namespace std;

void inFile(ifstream& f, char name[], char str2[]); //������� ������ �� �����
void ouFile(ofstream& f, char s[], char name[]); //������� ������ � ����


void var7_2()
{
	ifstream fin;
	ofstream fout;
	setlocale(0, "Rus");
	char str[256];
	char fileName[256];
	cout << "������� ������" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(str);
	cout << "������� ��� �����" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(fileName);
	ouFile(fout, str, fileName);
	int k, countWord = 0;
	char str2[256];
	inFile(fin, fileName, str2);
	cout << "������� k" << endl;
	cin >> k;
	for (int i = 1; i < k; i++) {
		if (str[i - 1] != ' ' && str[i] == ' ')
		{
			countWord++;
		}
	}
	if (k != ' ')
		++countWord;
	cout << "����� ����� ���������� k ������ " << countWord;
	fin.close();
	fout.close();
}


void inFile(ifstream& f, char name[], char str2[]) {
	f.open(name);
	if (f.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	f.getline(str2, 256);
	f.close();
}



void ouFile(ofstream& f, char s[], char name[]) {
	f.open(name);
	if (f.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	f << s << '\n';
	f.close();

}