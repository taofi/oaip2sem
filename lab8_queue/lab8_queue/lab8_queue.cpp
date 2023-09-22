#include "stdafx.h"



int main()
{
	setlocale(LC_ALL, "rus");
	queue* begin = nullptr, *end;
	dop2* beginI = nullptr, * endI;
	ifstream fin;
	ofstream fout;
	char buff[256];
	char* tmp_char;
	int maxSizeQ, sizeQ = 0;
	int sizeQI = 0;
	bool isSort = false;
	cin >> maxSizeQ;
	cout << "Для получения команд введите help" << endl;
	do {
		cout << "Введите команду\n";
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(buff);
		strcat(buff, " #/n");
		tmp_char = strtok(buff, " ");
		if (!strcmp(tmp_char, "help")) {
			cout << "push" << endl;
			cout << "pop" << endl;
			cout << "clear" << endl;
			cout << "show" << endl;
			cout << "exit" << endl;
		}
		else if (tmp_char[0] > '0' && tmp_char[0] < '9' || tmp_char[0]=='-')
			push(beginI, endI, strtoi(tmp_char), maxSizeQ, sizeQI);
		else if (!strcmp(tmp_char, "pop"))
			cout << pop(begin) << endl;
		else if (!strcmp(tmp_char, "push"))
		{
			if(isSort)
				SortPush(begin, end, tmp_char[6]);
			else
				push(begin, end, tmp_char[6], maxSizeQ, sizeQ);
		}
		else if (tmp_char[1] == '\0')
		{
			//cout << "a" << endl;
			if (isSort)
				SortPush(begin, end, tmp_char[0]);
			else
				push(begin, end, tmp_char[0], maxSizeQ, sizeQ);
		}
		else if (!strcmp(tmp_char, "clear"))
		{
			clear(begin);
			sizeQ = 0;
		}
		else if (!strcmp(tmp_char, "show"))
			showQ(begin);
		else if (!strcmp(tmp_char, "show2"))
			showQ2(begin);
		else if (!strcmp(tmp_char, "popI"))
			cout << pop(beginI) << endl;
		else if (!strcmp(tmp_char, "pushI"))
			push(beginI, endI, strtoi(strtok(NULL, "")), maxSizeQ, sizeQI);
		else if (!strcmp(tmp_char, "clearI"))
		{
			clear(beginI);
			sizeQI = 0;
		}
		else if (!strcmp(tmp_char, "showI"))
			showQ(beginI);
		else if (!strcmp(tmp_char, "move"))
			moveM(beginI, endI, maxSizeQ, sizeQI);
		else if (!strcmp(tmp_char, "dop3"))
			dop3(fin, fout);
		else if (!strcmp(tmp_char, "sort"))
		{
			if (tmp_char[5] == '1')
				isSort = true;
			else
				isSort = false;
			clear(begin);
			sizeQ = 0;
		}
		else if (!strcmp(tmp_char, "exit"))
		{
			clear(begin);
			clear(beginI);
			cout << "выход" << endl;
			return 0;
		}
		else
			cout << "неверная команда" << endl;
	} while (strcmp(tmp_char, "exit"));
}



char pop(queue*& begin)
{
	if (begin != NULL)
	{
		queue* t;
		
		//t = new queue;
		t = begin;
		char s = t->data;
		begin = begin->next;
		delete t;
		return s;
	}
	else
	{
		cout << "пусто" << endl;
		return 0;
	}

}

void push(queue*& begin, queue*& end, char sim, int maxSizeQ, int& sizeQ)
{
	queue* pv = new queue;
	pv->next = NULL;
	pv->data = sim;
	sizeQ++;
	if (begin == NULL)
		begin = end = pv;
	else
	{
		end->next = pv;
		end = pv;
		if (maxSizeQ < sizeQ)
		{
			sizeQ--;
			pop(begin);
		}
	}
	if (begin->data == end->data && sizeQ > 1)
	{
		for (int i = 0; i < 3; i++)
			pop(begin);
		sizeQ -= 3;
	}
	//cout << begin->data << endl;
}

void clear(queue*& st) {
	queue* pv = st;
	while (st != NULL) {
		pv = st;
		st = st->next;
		delete pv;
	}
	cout << "очищено" << endl;
}

void showQ(queue* st) {
	if (st == NULL)
	{
		cout << "пустo" << endl;
		return;
	}
	int n = 0;
	while (st != NULL)
	{
		cout << n << " " << st->data << endl;
		n++;
		st = st->next;
	}
	cout << endl;
}


void showQ2(queue* st) {
	if (st == NULL)
	{
		cout << "пустo" << endl;
		return;
	}
	while (st != NULL)
	{
		cout << " " << st->data;
		st = st->next;
	}
	cout << endl;
}

