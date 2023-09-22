#include "stdafx.h"

using namespace std;

void input(int d, CirclList*& begin, CirclList*& end) {
	CirclList* p = new CirclList;
	p->data = d;
	end->next = p;
	p->next = begin;
	end = p;
}

void tmpMove(CirclList*& tmp, int n) {
	for (int i = 0; i < n; i++) {
		tmp = tmp->next;
	}
}

void del(CirclList*& tmp, CirclList*& begin, CirclList*& end) {
	CirclList* p = begin;
	cout << tmp->data << endl;
	if (tmp == begin) {
		CirclList* q = begin;
		begin = begin->next;
		end->next = begin;
		tmp = begin;
		delete q;
		return;
	}
	
	while (p->next != tmp)
		p = p->next;
	if (tmp == end) {
		p->next = tmp->next;
		CirclList* q = tmp;
		end = p;
		tmp = end;
		delete q;
		return;
	}
	p->next = tmp->next;
	CirclList* q = tmp;
	tmp = p;
	delete q;
}

void show(CirclList* begin, CirclList* end) {
	do
	{
		cout << begin->data << " ";
		begin = begin->next ;
	}while (begin != end);
	cout << begin->data << " ";
	cout << endl;
}

void dop3() {
	CirclList* begin, *end, *tmp;
	int n, k;
	cin >> n >> k;
	if (n == 0)
		return;
	begin = new CirclList;
	begin->data = 1;
	begin->next = begin;
	end = tmp = begin;
	for (int i = 2; i <= n; i++) {
		input(i, begin, end);
	}
	show(begin, end);
	tmpMove(tmp, k - 1);
	del(tmp, begin, end);
	while (tmp->next != tmp) {
		tmpMove(tmp, k);
		del(tmp, begin, end);
	}
}