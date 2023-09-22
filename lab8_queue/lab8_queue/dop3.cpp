#include "stdafx.h"

void push(queue*& begin, queue*& end, char sim)
{
	queue* pv = new queue;
	pv->next = NULL;
	pv->data = sim;
	if (begin == nullptr)
		begin = end = pv;
	else
	{
		end->next = pv;
		end = pv;
	}
}

void dop3( ifstream& f, ofstream& g) {
	queue* begin = nullptr, * end;
	f.open("f.txt");
	if (f.fail())
	{
		cout << "\n ������ �������� �����";
		return;
	}
	char str[256];
	while (f.getline(str, 256)) {
		cout << str << endl;
		for (int i = 0; i < strlen(str); i++)
			if( !(str[i] >= '0' && str[i] <= '9'))
				push(begin, end, str[i]);
		for (int i = 0; i < strlen(str); i++)
			if(str[i] >= '0' && str[i] <= '9')
				push(begin, end, str[i]);
		writeF(begin, g);
		clear(begin);
	}
	f.close();
	clear(begin);
}

void writeF(queue*& p, ofstream& f) {
	
	f.open("g.txt", ios::app);
	if (f.fail())
	{
		cout << "\n ������ �������� �����";
		return;
	}
	if (p == NULL)
		cout << "������ ����" << endl;
	else
	{
		cout << "������:" << endl;
		while (p != NULL)
		{
			f << p->data;
			p = p->next;
		}
		f << "\n";
	}
	cout << "�������� � ���� " << endl;
	f.close();
}