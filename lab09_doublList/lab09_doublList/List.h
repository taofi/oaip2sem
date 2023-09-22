#pragma once
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct DATA
{
	char author[NAME_SIZE];
	char name[NAME_SIZE];
	char publish[NAME_SIZE];
	char type[NAME_SIZE];
	char origin[NAME_SIZE];
};

struct address
{
	
	DATA data;
	address* next;
	address* prev;
};
void insert(address* e, address** phead, address** plast);
address* setElement();
void outputList(address** phead, address** plast);
void find(char name[NAME_SIZE], address** phead);
void countList(address** phead, address** plast);
void delAll(address** phead, address** plast);
