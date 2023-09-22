#include <iostream>
#include <fstream>

using namespace std;

void iFile11(ifstream& f, char name[], char str2[], int n); //Функция чтения из файла
void oFile11(ofstream& f, char s[], char name[]); //Функция записи в файл
void findWord(char s[], int size, char word[]);
int countGlass(char* ps);

void var11_2()
{
	ifstream fin;
	ofstream fout;
	setlocale(0, "Rus");
	char str[256];
	char fileName[256];
	cout << "введите имя файла" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(fileName);
	cout << "введите строку 1" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(str);	
	oFile11(fout, str, fileName);
	cout << "введите строку 2" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	gets_s(str);
	oFile11(fout, str, fileName);
	
	int l = 0, minL = -1, maxL = -1, n = 0;
	char str2[256], word1[256];
	iFile11(fin, fileName, str2, 1);
	for (int i = 0; i < strlen(str2); i++)
	{
		if (str2[i] == ' ') {
			if (l < minL || minL == -1)
				minL = l;
			l = 0;
		}
		else
			l++;
	}
	if (str2[strlen(str) - 1] != ' ') {
		if (l < minL || minL == -1)
			minL = l;
	}
	cout << "длинна самого кароткого слова в первой строке " << minL << endl;
	findWord(str2, minL, word1);
	//cout << word1 << endl;
	cout << "количество глассных " << countGlass(word1) << endl;
	iFile11(fin, fileName, str2, 2);
	l = 0;
	for (int i = 0; i < strlen(str2); i++)
	{
		if (str2[i] == ' ') {
			maxL = max(maxL, l);
			l = 0;
		}
		else
			l++;
	}
	maxL = max(maxL, l);
	cout << "длинна самого длиного слова во втрой строке " << maxL << endl;
	char word2[256];
	findWord(str2, maxL, word2);
	cout << word2 << endl;
	cout << "количество глассных " << countGlass(word2) << endl;
	fin.close();
	fout.close();
}


void iFile11(ifstream& f, char name[], char str2[], int n) {
	f.open(name);
	if (f.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	for(int i = 0;  i < n; i ++)
		f.getline(str2, 256);
	
	f.close();
}



void oFile11(ofstream& f, char s[], char name[]) {
	f.open(name, ios::app);
	if (f.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	f << s << '\n';
	f.close();

}

void findWord(char s[], int size, char word[]) {
	int l = 0, n = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		l++;
		if (s[i] == ' ') {
			if (l == size) {
				for (int j = i - size; j < i; j++)
				{
					word[n] = s[j];
					n++;
				}
				word[n] = '\n';
				break;
			}
			l = 0;
		}			
	}
	if (l == size) {
		for (int j = strlen(s) - size; j < strlen(s); j++)
		{
			word[n] = s[j];
			n++;
		}
		word[n] = '\n';
	}
}

int countGlass(char* ps) {
	char glas[] = "aeiouy"; //6
	int k = 0;
	while (*ps != '\n')
	{
		for (int i = 0; i < 6; i++) {
			if (*ps == glas[i])
			{
				k++;
				break;
			}
		}
		ps++;
	}
	return k;
}