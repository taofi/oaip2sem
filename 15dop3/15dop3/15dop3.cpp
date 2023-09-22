#include <iostream>
#include <vector>
#include <string>
#include <fstream>


#define TABLE4_MAX 128

using namespace std;



struct node {
	string number;
	string name;
	node* next;
};

struct  hashTable
{
	node** items;
	int size;
	int count;
};
void resizeHashTable(hashTable* table);
int collisionCount = 0;

int hashFun(string key, int size)
{
	int p = 0;
	for (int i = 0; i < key.size(); i++)
		p += key[i];
	return p % size;
}

node* createNode(string key, string s) {
	node* newNode = new node;
	newNode->number = key;
	newNode->name = s;
	newNode->next = NULL;
	return newNode;
}

hashTable* htCreate(int size) {
	hashTable* htNew = new hashTable;
	htNew->size = size;
	htNew->count = 0;
	htNew->items = new node * [size];
	for (int i = 0; i < size; i++)
		htNew->items[i] = NULL;
	return htNew;
}


void deleteHT(hashTable* table) {
	for (int i = 0; i < table->count; i++)
		delete table->items[i];
	delete table;
}

void showHT(hashTable* table) {
	node* p0;
	for (int i = 0; i < table->size; i++)
	{
		p0 = table->items[i];
		while (p0 != NULL) {
			cout << "number: " << p0->number << " name: " << p0->name << endl;
			p0 = p0->next;
		}
	}
}

void put(hashTable* table, string key, string name) {
	node* HtItem = createNode(key, name);
	int index = hashFun(key, table->size);
	node* currentItem = table->items[index];
	node* p0;
	if (table->count == table->size) {
		printf("Insert Error: Hash Table is full\n");
		delete HtItem;
		return;
	}
	p0 = table->items[index];
	if (p0 != NULL) {
		collisionCount++;
		while (p0->next != NULL)
		{
			if (p0->number == key) {
				p0->name = name;
				return;
			}
			p0 = p0->next;
		}
		if (p0->number == key) {
			p0->name = name;
			return;
		}
		p0->next = HtItem;
	}
	else
		table->items[index] = HtItem;
	table->count++;
	if (table->size * 0.7 <= table->count)
		resizeHashTable(table);
}


node* find(hashTable* table, string key) {
	int index = hashFun(key, table->size);
	node* item = table->items[index];
	if (item == NULL) {
		return NULL;
	}
	while (item->next != NULL) {
		if (item->number == key)
			return item;
		item = item->next;
	}
	if (item->number == key)
		return item;
	return NULL;
}





int main()
{
	hashTable* tableX128 = htCreate(TABLE4_MAX);
	node* item;
	int action = 1;
	string name;
	//cout << " 1 - add\n 2 - find\n 3 - collision count\n 4 - show ht\n 5 - del item\n 0-exit \n";
	ifstream in("help.txt"); // окрываем файл для чтения
	string line;
	string disc;
	bool isKey = true;
	if (in.is_open())
	{
		
		while (std::getline(in, line))
		{
			//cout << line << endl;
			if (isKey)
			{
				name = line;
				isKey = false;
			}
			else {
				isKey = true;
				disc = line;
				put(tableX128, name, disc);
			}
		}
	}
	in.close();
	//showHT(tableX128);
	while (true) {
		getline(cin, line);
		if (line[0] == '/') {
			cout << "fun. name" << endl;
			getline(cin, name);
			cout << "disc." << endl;
			getline(cin, disc);
			put(tableX128, name, disc);
		}
		else {
			item = find(tableX128, line);
			if (item != NULL)
				cout << item->number << " " << item->name << endl;
			else
				cout << "not found" << endl;
		}
	}

	deleteHT(tableX128);
}
void resizeHashTable(hashTable* table) {

	node** oldHashTable = table->items;
	table->size *= 3;
	for (int i = 0; i < table->count; i++)
		delete table->items[i];
	for (int i = 0; i < table->size / 3; i ++) {
		if (oldHashTable[i] != NULL) {
			put(table, oldHashTable[i]->number, oldHashTable[i]->name);
		}
	}
	cout << "resize complete" << endl;
	cout << "new size: " << table->size << endl;
}