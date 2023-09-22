#include <iostream>
#include <fstream>

using namespace std;

void var7_1()
{
	setlocale(0, "Rus");
	ifstream fin("file1.txt");
	ofstream fout("file2.txt");
	char str[256];
	bool isHaveWord = false;
	while (fin.getline(str, 256)) {
		//cout << str << endl;
		isHaveWord = false;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == ' ')
			{
				isHaveWord = true;
			}
		}
		if (!isHaveWord)
			fout << str << endl;
	}
	fin.close();
	fout.close();
	ifstream fin2("file2.txt");
	int countA = 0;
	while (fin2.getline(str, 256)) {
		if (strlen(str) == 5)
		{
			cout << "длина слова 5: " << str << endl;
		}
	}
	fin2.close();
}