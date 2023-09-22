#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

int TABLE_SIZE = 10;
const double A = ((sqrt(5) - 1) / 2);


using namespace std;

struct HashEntry {
    int key;
    string value;
};

void resizeHashTable(vector<HashEntry>& hashTable, int f(int));//var 16
int a, b, elCount = 0;

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

int hashUniversal(int key) {
    double key_product = key * A;
    double fractional_part = key_product - floor(key_product);
    return  floor(TABLE_SIZE * fractional_part);
}

int insert(vector<HashEntry>& hashTable, int key, string& value, int f(int), bool IsResize = true) {
    
    if (elCount / double(hashTable.size()) >= 0.7 && IsResize) {
        resizeHashTable(hashTable, f);
    }
    if (elCount == TABLE_SIZE) {
        cout << "Error: Hash table overflow" << endl;
        return 0;
    }
    int hashIndex = f(key), callision = 0;
    if(hashTable[hashIndex].key != -1)
        callision++;

    while (hashTable[hashIndex].key != -1 && hashTable[hashIndex].key != key) {
        hashIndex = hashFunction(hashIndex + 1);
    }
    hashTable[hashIndex].key = key;
    hashTable[hashIndex].value = value;
    if (hashTable[hashIndex].key == key) {
        elCount++;
    }
    return callision;
}

string search(vector<HashEntry>& hashTable, int key, int f(int)) {
    int hashIndex = f(key);

    while (hashTable[hashIndex].key != -1) {
        if (hashTable[hashIndex].key == key) {
            return hashTable[hashIndex].value;
        }
        hashIndex = hashFunction(hashIndex + 1);
    }

    return "not found";
}

void clearHashTable(vector<HashEntry>& hashTable) {
    for (HashEntry& entry : hashTable) {
        entry.key = -1;
        entry.value = "";
    }
    elCount = 0;
}

void getAll(vector<HashEntry>& hashTable) {
    for (HashEntry& entry : hashTable) {
        if (entry.key != -1) { 
            cout << "key: " << entry.key << " value: " << entry.value << endl;
        }
    }
}

int main() {
    srand(time(0));
    vector<HashEntry> hashTable(TABLE_SIZE, { -1, "" });
    vector<HashEntry> hashTableUnivers(TABLE_SIZE, { -1, "" });
    int action = 1, key;
    string value;
    int modulCallision = 0;
    int unCallision = 0;
    while (action != 0) {
        cin >> action;
        switch (action)
        {
        case 1:
            cin >> key;
            cin >> value;
            insert(hashTableUnivers, key, value, hashUniversal);
            break;
        case 2:
            cin >> key;
            cout << "universal " << search(hashTableUnivers, key, hashUniversal) << endl;
            break;
        case 3:
            clearHashTable(hashTable);
            clearHashTable(hashTableUnivers);
            value = "test";
            modulCallision = 0;
            unCallision = 0;
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                key = rand() % (TABLE_SIZE * 10);
                modulCallision += insert(hashTable, key, value, hashFunction, false);
                elCount--;
                unCallision += insert(hashTableUnivers, key, value, hashUniversal, false);
            }
            cout << "modulCallision: " << modulCallision << endl;
            cout << "unCallision: " << unCallision << endl;
            break;
        case 4:
            getAll(hashTableUnivers);
            break;
        }
    }

    return 0;
}

void resizeHashTable(vector<HashEntry>& hashTable, int f(int)) {
    vector<HashEntry> oldHashTable = hashTable;
    TABLE_SIZE *= 3;
    hashTable = std::vector<HashEntry>(TABLE_SIZE, { -1, "" });
    elCount = 0;
    for (const HashEntry& entry : oldHashTable) {
        if (entry.key != -1) {
            string value = entry.value;
            insert(hashTable, entry.key, value, f);
        }
    }
    cout << "resize complete" << endl;
    cout << "new size: " << TABLE_SIZE << endl;
}