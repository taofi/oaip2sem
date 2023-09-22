#include "List1.h"
#include "stdafx.h"

using namespace std;
void insert2(Address2* e, Address2*& phead, Address2*& plast)
{
	Address2* p = phead;

	if (plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		plast = e;
		phead = e;
		return;
	}
	else
	{
		if ( strcmp(phead->data.surname, e->data.surname) > 0)
		{
			e->next = phead;
			e->prev = NULL;
			phead = e;
		}
		else {
			while (p->next != NULL && strcmp(p->next->data.surname, e->data.surname))
				p = p->next;
			if (p->next == NULL)
			{
				e->prev = p;
				e->next = NULL;
				p->next = e->prev;
				plast = e;
			}
			else {
				e->next = p->next;
				e->prev = p;
				p->next = e;
			}
		}
	}
}
//-----------------------------------------------------------
Address2* setElement()
{
	Address2* temp = new Address2();
	if (!temp)
	{
		cerr << "������ ��������� ������ ������";
		return NULL;
	}
	cout << "������� �������: ";
	cin >> temp->data.surname;
	cout << "������� ���: ";
	cin >> temp->data.name;
	cout << "������� ��������: ";
	cin >> temp->data.parentname;
	cout << "������� ���� ��������: " << endl;;
	cout << "������� ����:";
	cin >> temp->data.day;
	cout << endl;
	cout << "������� �����:";
	cin >> temp->data.month;
	cout << endl;
	cout << "������� ���:";
	cin >> temp->data.year;
	cout << endl;
	cout << "������� ����� �����: ";
	cin >> temp->data.course;
	cout << "������� ����� ������: ";
	cin >> temp->data.group;
	cout << "������� ���������� ������ �� ���������: " << endl;
	cin >> temp->data.markCount;
	cout << "�������  ������� �� ���������: " << endl;
	for (int i = 0; i < temp->data.markCount; i++) {
		cin >> temp->data.mark[i];
	}
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void outputList(Address2** phead, Address2** plast)
{
	Address2* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	while (t)
	{
		cout << "--------------------------------------------------" << endl;
		cout << "�������:" << t->data.surname << endl;
		cout << "���:" << t->data.name << endl;
		cout << "��������:" << t->data.parentname << endl;
		cout << "���� ��������:" << t->data.day << "." << t->data.month << "." << t->data.year << endl;
		cout << "����:" << t->data.course << endl;
		cout << "������:" << t->data.group << endl;
		cout << "������: ";
		for (int i = 0; i < t->data.markCount; i++)
			cout << t->data.mark[i] << ", ";
		cout << endl;
		t = t->next;

	}
}

void outputhCourse(Address2** phead, Address2** plast, int course)
{
	Address2* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	cout << "--------------------�������� "<<course<<" �����----------------" << endl;
	while (t)
	{
		if (t->data.course == course)
		{
			cout << "--------------------------------------------------" << endl;
			cout << "�������:" << t->data.surname << endl;
			cout << "���:" << t->data.name << endl;
			cout << "��������:" << t->data.parentname << endl;
			cout << "���� ��������:" << t->data.day << "." << t->data.month << "." << t->data.year << endl;
			cout << "����:" << t->data.course << endl;
			cout << "������:" << t->data.group << endl;
			cout << "������: ";
			for (int i = 0; i < t->data.markCount; i++)
				cout << t->data.mark[i] << ", ";
			cout << endl;
			t = t->next;
		}
		else
			t = t->next;

	}
}
void studentOld(Address2** phead, Address2** plast)
{
	int old = 0;
	Address2* tmp = *phead;
	old = tmp->data.year;
	while (tmp)
	{

		if (tmp->data.year < old)
		{
			old = tmp->data.year;
		}
		tmp = tmp->next;

	}
	Address2* t = *phead;
	while (t)
	{
		if (t->data.year == old)
		{
			cout << "������� �������=" << t->data.surname << endl;
		}
		t = t->next;
	}

}
void studentYoung(Address2** phead, Address2** plast)
{
	int young = 0;
	Address2* tmp = *phead;
	young = tmp->data.year;
	while (tmp)
	{
		if (tmp->data.year > young)
			young = tmp->data.year;
		tmp = tmp->next;
	}
	Address2* t = *phead;
	while (t)
	{
		if (t->data.year == young)
			cout << "������� �������=" << t->data.surname << endl;
		t = t->next;
	}
}


float mathAvreg(int markCount, float m[]) {
	int s = 0;
	for (int i = 0; i < markCount; i++) {
		s += m[i];
	}
	return s / markCount;
}

void average(Address2** phead, Address2** plast)
{
	
}
void dop2()
{
	Address2* head = NULL;
	Address2* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	int choice;
	char s[80]; int c;
	cout << endl;
	cout << "1. ���� ��������" << endl;
	cout << "2. ������� �������" << endl;
	cout << "3. ������� �������" << endl;
	cout << "4. ������ ������" << endl;
	cout << "5. ����� ������" << endl;
	cout << "6. 1 ����" << endl;
	cout << "7. 2 ����" << endl;
	cout << "8. 3 ����" << endl;
	cout << "9. 4 ����" << endl;
	cout << "10. �����" << endl;
	cout << endl;
	for (;;)
	{
		cout << "��� �����: ";
		cin >> choice;
		switch (choice)
		{
		case 1: insert2(setElement(), head, last);
			break;
		case 2: studentOld(&head, &last);
			break;
		case 3: studentYoung(&head, &last);
			break;
		case 4: average(&head, &last);
			break;
		case 5: outputList(&head, &last);
			break;
		case 10: exit(0);
		default: exit(1);
		}
	}
}
