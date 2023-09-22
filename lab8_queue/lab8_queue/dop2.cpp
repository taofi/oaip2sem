#include "stdafx.h"

int pop(dop2*& begin)
{
	if (begin != NULL)
	{
		dop2* t;
		t = begin;
		int s = t->data;
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

void push(dop2*& begin,dop2*& end, int sim, int maxSizeQ, int& sizeQ)
{
	if (sim == NULL)
	{
		cout << "неверная команда" << endl;
		return;
	}
	dop2* pv = new dop2;
	pv->next = NULL;
	pv->data = sim;
	sizeQ++;
	if (begin == nullptr)
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
}

void clear(dop2*& st) {
	dop2* pv = st;
	while (st != NULL) {
		pv = st;
		st = st->next;
		delete pv;
	}
	cout << "очищено" << endl;
}

void showQ(dop2* st) {
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
}

void moveM(dop2*& begin, dop2*& end, int maxSizeQ, int& sizeQ) {
	dop2* maxP = findMax(begin);
	if (maxP == NULL)
		return;
	while (begin != maxP) {
		push(begin, end, pop(begin), maxSizeQ, sizeQ);
	}
}

dop2* findMax(dop2* st)
{
	if (st == NULL)
	{
		cout << "пустo" << endl;
		return NULL;
	}
	int maxCh = st -> data;
	dop2* p = st;
	st = st->next;
	while (st != NULL)
	{
		if (maxCh < st->data)
		{
			maxCh = st->data;
			p = st;
		}
		st = st->next;
		//cout << p->data << endl;
	}
	return p;
}