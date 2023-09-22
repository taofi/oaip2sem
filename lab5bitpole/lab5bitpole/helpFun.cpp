#include "stdafx.h"

int strtoi(char arr[]) {
	char* p = arr;
	bool isd = true;
	int digit = -1;
	while (*p)
		if (!isdigit(*p++))
		{
			isd = false;
			break;
		}
	if (isd)
		return atoi(arr);
	else
		return -1;
}

void coutBankHead() {
	cout << "| индекс |";
	cout << "|" << setw(strsize + 1) << "имя |";
	cout << "|" << setw(strsize + 1) << "фамилия |";
	cout << "|" << setw(strsize + 1) << "отчество |";
	cout << "|  баланс  |";
	cout << "| номер |";
	cout << "| дата изменения |";
	cout << "|   тип счета  |" << endl;
}