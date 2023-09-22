#include <iostream>
#include <fstream>

using namespace std;

void var9_1()
{
	setlocale(0, "Rus");
	ifstream fin("file1.txt");
	ofstream fout("file2.txt");
	char str[256];
	int n1, n2, index = 0;
	cout << "введите n1, n2" << endl;
	cin >> n1 >> n2;
	while (fin.getline(str, 256)) {
		index++;
		if ( (index > n1) && (n2 > index) && (str[0] = 'C'))
			fout << str << endl;
	}
	fin.close();
	fout.close();
	ifstream fin2("file2.txt");
	int countA = 0;
	int countWord = 0;
	fin2.getline(str, 256);
	for (int i = 1; i < strlen(str); i++) {
		if (str[i - 1] != ' ' && str[i] == ' ')
		{
			countWord++;
		}
	}
	if (str[strlen(str) - 1] != ' ')
	{
		countWord++;
	}
	cout << "количество слов " << countWord  << endl;
	fin2.close();
}