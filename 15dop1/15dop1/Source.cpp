#include <iostream>
#include <vector>
#include <string>


#define TABLE4_MAX 128

using namespace std;



struct node {
	int key;
	int count;
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

node* createNode(int key, int count) {
	node* newNode = new node;
	newNode->key = key;
	newNode->count = count;
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


void put(hashTable* table, int key, int count) {
	node* HtItem = createNode(key, count);
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
			if (p0->key == key) {
				p0->count ++;
				return;
			}
			p0 = p0->next;
		}
		if (p0->key == key) {
			p0->count++;
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
		if (item->key == key)
			return item;
		item = item->next;
	}
	if (item->key == key)
		return item;
	return NULL;
}

void showHT(hashTable* table) {
	node* p0;
	for (int i = 0; i < table->size; i++)
	{
		p0 = table->items[i];
		while (p0 != NULL) {
			cout << char(p0->key) << " count: " << p0->count << endl;
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
	int action = 1;
	string st;
	char c;
	getline(cin, st);
	for (int i = 0; i < st.length(); i++) {
		put(tableX128, int(st[i]), 1);
	}
	cout << " 2 - find\n 3 - collision count\n 4 - show ht\n 0-exit \n";
	while (action != 0) {
		cin >> action;
		switch (action)
		{
		case 2:
			cin >> c;
			item = find(tableX128, int(c));
			if (item != NULL)
				cout << char(item->key) << " " << item->count << endl;
			else
				cout << "not found" << endl;
			break;

		case 3:
			cout << "collision: " << collisionCount << endl;
			break;
		case 4:
			showHT(tableX128);
			break;
		}

	}
	deleteHT(tableX128);
}