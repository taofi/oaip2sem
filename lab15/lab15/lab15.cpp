#include <iostream>
#include <vector>
#include <string>


#define TABLE1_MAX 16
#define TABLE2_MAX 32
#define TABLE3_MAX 64
#define TABLE4_MAX 128

using namespace std;



struct node {
	int number;
	string name;
	node* next;
};

struct  hashTable
{
	node** items;
	int size;
	int count;
};

int collisionCount = 0;

int hashFun(int key, int size)
{
	return key % size;
}

node* createNode(int key, string s) {
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


void put(hashTable* table, int key, string name) {
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

}



node* find(hashTable* table, int key) {
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

void deleteItem(hashTable* table, int key) {
	int index = hashFun(key, table->size);
	node* item = find(table, key);
	node* p0 = table->items[index];
	if (item != NULL) {
		while (p0->next != item)
			p0 = p0->next;
		p0->next = item->next;
		delete item;
		table->count--;
	}
	else {
		cout << "not found" << endl;
		return;
	}
}


int main()
{
	hashTable* tableX128 = htCreate(TABLE4_MAX);
	node* item;
	int action = 1, number;
	string name;
	char x;
	cout << "1 - add\n 2 - find\n 3 - collision count\n 4 - show ht\n 5 - del item\n 0-exit \n";
	while (action != 0) {
		cin >> action;
		switch (action)
		{
		case 1:
			cin >> number;
			cin.get(x);
			getline(cin, name);
			put(tableX128, number, name);
			break;
		case 2:
			cin >> number;
			item = find(tableX128, number);
			if (item != NULL)
				cout << item->number << " " << item->name << endl;
			else
				cout << "not found" << endl;
			break;

		case 3:
			cout << "collision: " << collisionCount << endl;
			break;
		case 4:
			showHT(tableX128);
			break;
		case 5:
			cin >> number;
			deleteItem(tableX128, number);
			break;
		}

	}
			
	deleteHT(tableX128);
}