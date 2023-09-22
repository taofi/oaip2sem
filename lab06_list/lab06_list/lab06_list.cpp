#include "stdafx.h"
 
int var4();
int var7();
int var8();
int var11();

int main() {
	setlocale(LC_CTYPE, "Russian");
	int action;
	do {
		cout << "4, 7, 8, 11" << endl;
		cin >> action;
		switch (action)
		{
		case 4:
			var4();
			break;
		case 7:
			var7();
			break;
		case 8:
			var8();
			break;
		case 11:
			var11();
			break;
		case -1:
			cout << "end" << endl;
			break;
		default:
			cout << "невернй вариант" << endl;
			break;
		}
	} while (action != -1);
	
	return 0;
}