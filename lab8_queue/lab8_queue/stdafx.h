#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>


using namespace std;

int strtoi(char arr[]);

struct queue {
	char data;
	queue* next;
};


struct dop2
{
	int data;
	dop2* next;
};

char pop(queue*& begin);
void push(queue*&, queue*&, char, int, int&);
void clear(queue*& st);
void showQ(queue* st);
void showQ2(queue* st);

int pop(dop2*& begin);
void push(dop2*&, dop2*&, int, int, int&);
void clear(dop2*& st);
void showQ(dop2* st);
void moveM(dop2*& begin, dop2*& end, int maxSizeQ, int& sizeQ);
dop2* findMax(dop2* st);

void push(queue*&, queue*&, char);
void dop3(ifstream& f, ofstream& g);
void writeF(queue*& p, ofstream& f);

void SortPush(queue*&, queue*&, char);