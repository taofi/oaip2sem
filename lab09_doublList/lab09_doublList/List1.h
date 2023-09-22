#pragma once
using namespace std;
const unsigned int NAME_SIZE = 30;

struct DATA
{
	char name[NAME_SIZE];
	char surname[NAME_SIZE];
	char parentname[NAME_SIZE];
	int month;
	int year;
	int day;
	int course;
	int group;
	int markCount;
	float mark[NAME_SIZE];
};

struct Address2
{
	DATA data;
	Address2* next;
	Address2* prev;
};
void insert2(Address2* e, Address2*& phead, Address2*& plast);
Address2* setElement();
void outputList(Address2** phead, Address2** plast);
void studentOld(Address2** phead, Address2** plast);
void studentYoung(Address2** phead, Address2** plast);
void average(Address2** phead, Address2** plast);
