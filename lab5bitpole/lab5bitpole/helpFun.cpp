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
	cout << "| ������ |";
	cout << "|" << setw(strsize + 1) << "��� |";
	cout << "|" << setw(strsize + 1) << "������� |";
	cout << "|" << setw(strsize + 1) << "�������� |";
	cout << "|  ������  |";
	cout << "| ����� |";
	cout << "| ���� ��������� |";
	cout << "|   ��� �����  |" << endl;
}