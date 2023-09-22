#include <iostream>
#include <fstream>

using namespace std;

void var4_1()
{
	setlocale(0, "Rus");
	ifstream fin("file1.txt");
	ofstream fout("file2.txt");
	char str[256];
	bool isHaveNumber = false;
	while (fin.getline(str, 256)) {
		//cout << str << endl;
		isHaveNumber = false;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				isHaveNumber = true;
			}
		}
		if (!isHaveNumber)
			fout << str << endl;
	}
	fin.close();
	fout.close();
	ifstream fin2("file2.txt");
	int countA = 0;
	while (fin2.getline(str, 256)) {
		cout << str << endl;
		if (str[0] == 'A')
			countA++;
	}
	cout << "начниются на 'A'" << countA << " строк" << endl;
	fin2.close();
}